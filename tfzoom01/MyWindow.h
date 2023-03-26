#pragma once

#include <gtkmm/window.h>
#include <gtkmm/scrolledwindow.h>
#include "MyArea.h"

class MyWindow : public Gtk::Window
{
public:
    MyWindow();

private:
    MyArea area;
    Gtk::ScrolledWindow scrolled;
};
