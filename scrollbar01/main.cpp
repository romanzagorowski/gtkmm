#include "MyWindow.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <gtkmm/application.h>

#pragma GCC diagnostic pop

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	MyWindow win;

	return app->run(win);
}
