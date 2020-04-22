#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/adjustment.h>

#pragma GCC diagnostic pop

class MyWindow: public Gtk::Window
{
public:
	MyWindow();

private:
    Glib::RefPtr<Gtk::Adjustment> hadjustment;

	Gtk::Grid grid;
	//Gtk::VScrollbar vscrollbar;
	Gtk::HScrollbar hscrollbar;
	Gtk::DrawingArea area;

private:
	bool on_area_draw(const Cairo::RefPtr<Cairo::Context>& cr);
	void on_area_size_allocate(Gtk::Allocation& allocation);
	void on_area_realize();
};
