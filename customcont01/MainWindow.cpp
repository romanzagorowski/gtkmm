#include "MainWindow.h"

#include <iostream>

Abc::MainWindow::MainWindow() :
    vbox_{Gtk::Orientation::VERTICAL},
    button_one_{"Child one"},
    label_two_{"Child label"},
    quit_button_{"Quit"}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    this->set_default_size(400, 200);
    
    vbox_.set_margin(6);
    this->set_child(vbox_);

    // Add the child widgets to the custom container
    container_.set_child_widgets(button_one_, label_two_);
    container_.set_expand();

    vbox_.append(container_);
    vbox_.append(button_box_);

    button_box_.append(quit_button_);
    button_box_.set_margin(6);
    
    quit_button_.set_hexpand(true);
    quit_button_.set_halign(Gtk::Align::END);
    quit_button_.signal_clicked().connect(
        sigc::mem_fun(
            *this,
            &MainWindow::on_button_quit
        )
    );
}

Abc::MainWindow::~MainWindow()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Abc::MainWindow::on_button_quit()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    hide();
}
