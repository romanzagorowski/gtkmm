#include <gtkmm/application.h>

#include "MainWindow.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.example");
    return app->make_window_and_run<Abc::MainWindow>(argc, argv);
}
