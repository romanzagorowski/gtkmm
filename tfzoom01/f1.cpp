#include "mt4hst.h"
#include "stdio.h"
#include "string.h"
#include "errno.h"
#include "assert.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

void read_hst_header(
    std::istream& stream,
    mt4::hst::header& header
)
{
    stream.read((char*)&header, sizeof(header));
}

void print_hst_header(
    std::ostream& stream,
    const mt4::hst::header& header
)
{
    stream << "{ version=" << header.version << " }" << std::endl;
}

void print_hst_record(
    std::ostream& stream,
    const mt4::hst::record_v401& record,
    std::uint32_t digits
)
{
    // https://stackoverflow.com/questions/11989374/floating-point-format-for-stdostream

    stream << std::fixed;
    stream << std::setprecision(digits);

    stream << "{ "
        << "ctm=" << record.ctm << ", "
        << "open=" << record.open << ", "
        << "high=" << record.high << ", "
        << "low=" << record.low << ", "
        << "close=" << record.close << ", "
        << "volume=" << record.volume << ", "
        << "spread=" << record.spread << ", "
        << "real_volume=" << record.real_volume
        << " }"
        << std::endl;
}

const char* hst_filename = "/home/roman/tmp/EURUSD.1.hst";

int f1()
{
    const std::uintmax_t file_size = fs::file_size(hst_filename);

    std::cout << "file_size=" << file_size << std::endl;

    std::ifstream stream{hst_filename};

    mt4::hst::header header{};
    read_hst_header(stream, header);
    print_hst_header(std::cout, header);

    if(header.version == 401)
    {
        const auto number_of_records = (file_size - sizeof(mt4::hst::header)) / sizeof(mt4::hst::record_v401);

        std::cout << "number_of_records=" << number_of_records << std::endl;
        std::cout << (file_size - sizeof(mt4::hst::header)) % sizeof(mt4::hst::record_v401) << std::endl;

        std::vector<mt4::hst::record_v401> records{number_of_records};
        //records.reserve(number_of_records);

        std::cout << "records.size()=" << records.size() << std::endl;

        stream.read((char*)records.data(), records.size() * sizeof(mt4::hst::record_v401));

        std::cout << "stream.good()=" << std::boolalpha << stream.good() << std::endl;
        std::cout << "stream.eof()="  << std::boolalpha << stream.eof()  << std::endl;

        for(const auto& record : records)
        {
            print_hst_record(std::cout, record, header.digits);
        }
    }

    return 0;
}
