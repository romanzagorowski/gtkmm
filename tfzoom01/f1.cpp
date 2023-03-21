#include "mt4hst.h"
#include "stdio.h"
#include "string.h"
#include "errno.h"
#include "assert.h"

/*
#include <exception>

class errno_exception : public std::exception
{
public:

};
*/

bool read_hst_header(FILE* f, mt4::hst::header& h)
{
    assert(f);

    return fread(&h, sizeof(h), 1, f) == 1;
}

long get_file_size(FILE* f)
{
    assert(f);

    const long current_pos = ftell(f);
    assert(-1L != current_pos);

    const int e1 = fseek(f, 0, SEEK_END);
    assert(0 == e1);

    const long file_size = ftell(f);
    assert(-1L != file_size);

    fseek(f, current_pos, SEEK_SET);

    return file_size;
}

const char* hst_filename = "/home/roman/tmp/EURUSD.1.hst";

int f1()
{
    FILE* f = fopen(hst_filename, "r");

    if(nullptr == f)
    {
        fprintf(
            stderr, 
            "ERROR: f1(): Failed to open the file '%s' for reading (errno='%d', errstr='%s').\n", 
            hst_filename, 
            errno, 
            strerror(errno)
        );

        return 1;
    }
    else
    {
        fprintf(
            stdout, 
            "INFO: f1(): Succeeded to open the file '%s' for reading!\n", 
            hst_filename
        );
    }

    //-------------------------------------------------------------------------

    const long file_size = get_file_size(f);
    assert(-1L != file_size);

    fprintf(stdout, "INFO: f1(): The size of the file '%s' is %ld.\n", hst_filename, file_size);

    //-------------------------------------------------------------------------

    mt4::hst::header h{};

    if(!read_hst_header(f, h))
    {
        fprintf(
            stderr, 
            "ERROR: f1(): Failed to read hst header from the file '%s' for reading (errno='%d', errstr='%s').\n", 
            hst_filename, 
            errno, 
            strerror(errno)
        );

        return 2;
    }

    //-------------------------------------------------------------------------

    // TODO: To be continued...

    //-------------------------------------------------------------------------

    if(f)
        fclose(f);

    return 0;
}
