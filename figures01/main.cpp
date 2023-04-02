#include "MyWindow.h"

#include <iostream>
#include <gtkmm/application.h>

#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

constexpr auto settings_filename = "settings.json";

int main(int argc, char* argv[]) 
{
    try
    {
        auto app = Gtk::Application::create(argc, argv, "com.gnome.examples.screen01");

        boost::property_tree::ptree pt;

        if(fs::exists(settings_filename))
        {
            boost::property_tree::json_parser::read_json(settings_filename, pt);
        }

        My::Window win{pt};
        win.show_all();

        return app->run(win);
    }
    catch(const std::exception& e)
    {
        std::cerr << "main(): Exception caught: '" << e.what() << "'" << std::endl;
    }
}
