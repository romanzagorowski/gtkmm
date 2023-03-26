#include "MyArea.h"
#include "R.h"
#include <cmath>
#include <thread>
#include <chrono>

void d1(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea* area)
{
    Gtk::Allocation allocation = area->get_allocation();

    const auto width  = allocation.get_width();
    const auto height = allocation.get_height();

    const int xc = width  / 2;
    const int yc = height / 2;

    cr->set_line_width(10.0);

    // draw red lines out from the center of the window

    cr->set_source_rgb(0.8, 0, 0);
    cr->move_to(0, 0);
    cr->line_to(xc, yc);
    cr->line_to(0, height);
    cr->move_to(xc, yc);
    cr->line_to(width, yc);
    cr->stroke();
}

void d2(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea* area)
{
    cr->set_source_rgb(0.2, 0.3, 0.8);
    cr->rectangle(10, 10, 30, 30);
    cr->fill();

    cr->translate(20, 20);
    cr->set_source_rgb(0.8, 0.3, 0.2);
    cr->rectangle(0, 0, 30, 30);
    cr->fill();

    cr->translate(30, 30);
    cr->set_source_rgb(0.8, 0.8, 0.2);
    cr->rectangle(0, 0, 30, 30);
    cr->fill();

    cr->translate(40, 40);
    cr->set_source_rgb(0.3, 0.8, 0.8);
    cr->rectangle(0, 0, 30, 30);
    cr->fill();
}


void d3(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea* area)
{
    cr->set_source_rgb(0.6, 0.6, 0.6);
    cr->rectangle(20, 30, 80, 50);
    cr->fill();

    Cairo::Matrix m{
        1.0, 0.5,   // xx, yx
        0.0, 1.0,   // xy, yy
        0.0, 0.0    // x0, y0
    };

    cr->transform(m);
    cr->rectangle(130, 30, 80, 50);
    cr->fill();

}

void scale(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea* area)
{
    cr->set_source_rgb(0.2, 0.3, 0.8);
    cr->rectangle(10, 10, 90, 90);
    cr->fill();

    cr->scale(0.6, 0.6);

    cr->set_source_rgb(0.8, 0.3, 0.2);
    cr->rectangle(30, 30, 90, 90);
    cr->fill();

    cr->scale(0.8, 0.8);
    cr->set_source_rgb(0.8, 0.8, 0.2);
    cr->rectangle(50, 50, 90, 90);
    cr->fill();
}

struct X
{
    X(const Cairo::RefPtr<Cairo::Context>& cr) :
        cr(cr)
    {
        cr->save();
    }

    ~X()
    {
        cr->restore();
    }

    const Cairo::RefPtr<Cairo::Context>& cr;
};

void isolate_x(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea* area)
{
    cr->set_source_rgb(.2, .3, .8);
    cr->rectangle(10, 10, 90, 90);
    cr->fill();

    {
        X x{cr};
        cr->scale(.6, .6);
        cr->set_source_rgb(.8, .3, .2);
        cr->rectangle(30, 30, 90, 90);
        cr->fill();
    }

    {
        X x{cr};
        cr->scale(.8, .8);
        cr->set_source_rgb(.8, .8, .2);
        cr->rectangle(50, 50, 90, 90);
        cr->fill();
    }
}

void isolate(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea* area)
{
    cr->set_source_rgb(.2, .3, .8);
    cr->rectangle(10, 10, 90, 90);
    cr->fill();

    cr->save();
    cr->scale(.6, .6);
    cr->set_source_rgb(.8, .3, .2);
    cr->rectangle(30, 30, 90, 90);
    cr->fill();
    cr->restore();

    cr->save();
    cr->scale(.8, .8);
    cr->set_source_rgb(.8, .8, .2);
    cr->rectangle(50, 50, 90, 90);
    cr->fill();
    cr->restore();
}

void donut(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea* area)
{
    Gtk::Allocation allocation = area->get_allocation();

    const auto width  = allocation.get_width();
    const auto height = allocation.get_height();

//    const int xc = width  / 2;
//    const int yc = height / 2;

    cr->set_line_width(.5);
    cr->translate(width / 2, height / 2);
    cr->arc(0, 0, 120, 0, 2 * M_PI);
    cr->stroke();

    for(int i = 0; i < 36; ++i)
    {
        cr->save();
        cr->rotate(i * M_PI / 36);
        cr->scale(.3, 1);
        cr->arc(0, 0, 120, 0, 2 * M_PI);
        cr->restore();
        cr->stroke();

        //std::this_thread::sleep_for(std::chrono::seconds{1});
    }
}

void star(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea* area)
{
    int points[][2] = {
        {   0,  85 },
        {  75,  75 },
        { 100,  10 },
        { 125,  75 },
        { 200,  85 },
        { 150, 125 },
        { 160, 190 },
        { 100, 150 },
        {  40, 190 },
        {  50, 125 },
        {   0,  85 }
    };

    static double angle = 0;
    static double scale = 1;
    static double delta = 0.01;

    Gtk::Allocation allocation = area->get_allocation();

    const auto width  = allocation.get_width();
    const auto height = allocation.get_height();

    cr->set_source_rgb(0, .44, .7);
    cr->set_line_width(1);

    cr->translate(width / 2, height / 2);
    cr->rotate(angle);
    cr->scale(scale, scale);

    for(int i = 0; i < 10; ++i)
    {
        cr->line_to(points[i][0], points[i][1]);
    }

    cr->close_path();
    cr->fill();
    cr->stroke();

    if(scale < 0.01)
        delta = -delta;
    else if(scale > 0.99)
        delta = -delta;

    scale += delta;
    angle += 0.01;
}

void draw_seires(
    const Cairo::RefPtr<Cairo::Context>& cr
,   Gtk::DrawingArea* area
,   const std::vector<R>& series
)
{

}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    d1(cr, this);
    
    return true;
}

MyArea::MyArea()
{
    this->set_size_request(2000, 600);
}
