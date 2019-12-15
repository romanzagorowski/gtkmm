#include <gtkmm/application.h>
#include <gtkmm/window.h>

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.gtkmm01");

	Gtk::Window win;
	win.set_default_size(800, 600);
	win.show_all();

	return app->run(win);
}
