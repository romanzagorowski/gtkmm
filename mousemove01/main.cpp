#include "pch.h"

#include <iostream>
#include <cassert>

namespace My
{
    class Window : public Gtk::Window
    {
    public:
    };
}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.gnome01");

    My::Window win;
    win.set_size_request(800, 600);

    return app->run(win);
}

