#pragma once

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/vbox.h>

namespace Abc
{
    class MainWindow : public Gtk::Window
    {
    public:
        MainWindow();
        virtual MainWindow();

    protected:
        // signal handlers
        void on_button_quit();

        // child widgets
        Gtk::Box vbox_;
        Gtk::Button button_one_;

    };
}
