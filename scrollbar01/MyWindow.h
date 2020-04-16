#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/drawingarea.h>

#pragma GCC diagnostic pop

class MyWindow: public Gtk::Window
{
public:
	MyWindow();

private:
	Gtk::Grid grid;
	Gtk::VScrollbar vscrollbar;
	Gtk::HScrollbar hscrollbar;
	Gtk::DrawingArea area;

private:
	bool on_area_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};
