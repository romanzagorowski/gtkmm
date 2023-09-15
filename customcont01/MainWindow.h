#pragma once

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include "MyContainer.h"

namespace Abc
{
    class MainWindow : public Gtk::Window
    {
    public:
        MainWindow();
        virtual ~MainWindow();

    protected:
        // Signal handlers
        void on_button_quit();

        // Child widgets
        Gtk::Box vbox_;
        Gtk::Button button_one_;
        Gtk::Label label_two_;

        // A restricton with MyContainer is that it must be deleted before its children,
        // meaning that it must be declared after its children.
        Abc::MyContainer container_;

        Gtk::Box button_box_;
        Gtk::Button quit_button_;
    };
}
