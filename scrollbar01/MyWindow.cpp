#include "MyWindow.h"

MyWindow::MyWindow()
{
	set_default_size(800, 600);
	set_border_width(10);

	area.set_size_request(400, 300);
	area.signal_draw().connect(sigc::mem_fun(*this, & MyWindow::on_area_draw));

/*
	grid.set_row_homogeneous();
	grid.set_column_homogeneous(true);
*/
	area.set_hexpand(true);
	area.set_vexpand(true);

	grid.set_row_spacing(10);
	grid.set_column_spacing(10);
	grid.attach(area	  , 0, 0, 1, 1);
	grid.attach(hscrollbar, 1, 0, 1, 1);
	grid.attach(vscrollbar, 0, 1, 1, 1);

	add(grid);

	show_all_children();
}

bool MyWindow::on_area_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	cr->set_source_rgb(1., 0., 0.);
	cr->paint();

	return true;
}
