#include "MyWindow.h"

#include <iostream>

MyWindow::MyWindow() :
    hadjustment(Gtk::Adjustment::create(
            0,      // value
            0,      // lower
            1000,   // upper
            100,    // step_increment
            1000,   // page_increment
            1000    // page_size
            )
    ),
    hscrollbar(hadjustment)
{
	set_default_size(800, 600);
	//set_border_width(10);

//	Glib::RefPtr<Gtk::Adjustment> hadjustment = hscrollbar.get_adjustment();
//	hadjustment->set_upper(10 + 1000 + 10);
//	hadjustment->set_step_increment(100);

	area.set_size_request(400, 300);
	area.signal_draw().connect(sigc::mem_fun(*this, & MyWindow::on_area_draw));
	area.signal_size_allocate().connect(sigc::mem_fun(*this, & MyWindow::on_area_size_allocate));
	area.signal_realize().connect(sigc::mem_fun(*this, & MyWindow::on_area_realize));

/*
	grid.set_row_homogeneous();
	grid.set_column_homogeneous(true);
*/
	area.set_hexpand(true);
	//area.set_vexpand(true);

//	grid.set_row_spacing(10);
//	grid.set_column_spacing(10);

	grid.attach(area	  , 0, 0, 1, 1);
	grid.attach(hscrollbar, 0, 1, 1, 1);
	//grid.attach(vscrollbar, 1, 0, 1, 1);

	add(grid);

	show_all_children();
}

bool MyWindow::on_area_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	static int count = 1;

    Gtk::Allocation a = area.get_allocation();

	std::cout << "on_area_draw"
	        << ": count = " << count++
	        << ", width = " << a.get_width()
	        << ", height = " << a.get_height()
	        << std::endl;

	// paint white background
	cr->set_source_rgb(1, 1, 1);
	cr->rectangle(0, 0, a.get_width(), a.get_height());
	cr->paint();

	// stroke green line around all allocation
	cr->set_source_rgb(0, 1, 0);
    cr->rectangle(0, 0, a.get_width(), a.get_height());
    cr->stroke();

    // stroke main red box
	cr->set_source_rgb(1, 0, 0);
	cr->translate(-hadjustment->get_value(), 10);
    cr->rectangle(10, 10, 980, 100);
	cr->stroke();

	// stroke long blue box
    cr->set_source_rgb(0, 0, 1);
    cr->translate(-hadjustment->get_value(), 10);
    cr->rectangle(20, 10, 1820, 80);
    cr->stroke();

	return true;
}

void MyWindow::on_area_size_allocate(Gtk::Allocation& allocation)
{
	static int count = 1;

	std::cout << "on_area_size_allocate: count = " << count++
			<< ", x = " << allocation.get_x()
			<< ", y = " << allocation.get_y()
			<< ", w = " << allocation.get_width()
			<< ", h = " << allocation.get_height()
			<< std::endl;

	//Glib::RefPtr<Gtk::Adjustment> hadjustment = hscrollbar.get_adjustment();

    std::cout << "on_area_size_allocate"
        << ": value = " << hadjustment->get_value()
        << ", lower = " << hadjustment->get_lower()
        << ", upper = " << hadjustment->get_upper()
        << ", page_size = " << hadjustment->get_page_size()
        << ", page_inc = " << hadjustment->get_page_increment()
        << ", step_inc = " << hadjustment->get_step_increment()
        << std::endl
        ;

    hadjustment->set_page_size     (allocation.get_width());
    hadjustment->set_page_increment(allocation.get_width());

    std::cout << "on_area_size_allocate"
        << ": value = " << hadjustment->get_value()
        << ", lower = " << hadjustment->get_lower()
        << ", upper = " << hadjustment->get_upper()
        << ", page_size = " << hadjustment->get_page_size()
        << ", page_inc = " << hadjustment->get_page_increment()
        << ", step_inc = " << hadjustment->get_step_increment()
        << std::endl
        ;
}

void MyWindow::on_area_realize()
{
    Gdk::Geometry geometry = {};

    geometry.max_width  = 1000;
    geometry.max_height =  300;

    set_geometry_hints(area, geometry, Gdk::HINT_MAX_SIZE);
}
