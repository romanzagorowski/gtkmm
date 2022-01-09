#include "pch.h"

#include <iostream>
#include <cassert>

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.gnome01");

    auto builder = Gtk::Builder::create();

    try
    {
        builder->add_from_file("glade01.glade");
    }
    catch(const Glib::FileError& e)
    {
        std::cerr << "FileError: " << e.what() << std::endl;
        return 1;
    }
    catch(const Glib::MarkupError& e)
    {
        std::cerr << "MarkupError: " << e.what() << std::endl;
        return 1;
    }
    catch(const Gtk::BuilderError& e)
    {
        std::cerr << "BuildError: " << e.what() << std::endl;
        return 1;
    }

    Gtk::Window* window1 = nullptr;
    builder->get_widget("window1", window1);
    assert(window1);

    return app->run(*window1);
}

