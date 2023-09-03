#include <gtkmm.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.example");
    return app->make_window_and_run<Gtk::Window>(argc, argv);
}
