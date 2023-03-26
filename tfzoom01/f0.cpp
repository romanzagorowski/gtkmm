#include <gtkmm/application.h>
#include "MyWindow.h"

int f0(int argc, char* argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.tfzoom01");

	MyWindow win;
	win.set_default_size(600, 400);
	win.show_all();

	return app->run(win);
}
