#include "mywindow.h"
#include "mygtkutils.h"

#include <iostream>

#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/property_tree/json_parser.hpp>

namespace My
{

Window::Window(const boost::property_tree::ptree& pt)
{
    set_default_size(
        pt.get<int>("window.width", 800), 
        pt.get<int>("window.height", 600)
        );

    area.set_events(
        Gdk::EventMask::BUTTON_PRESS_MASK
    |   Gdk::EventMask::BUTTON_MOTION_MASK
    );

    area.signal_draw().connect(sigc::mem_fun(*this, &My::Window::area_on_draw));
    area.signal_button_press_event().connect(sigc::mem_fun(*this, &My::Window::area_on_button_press_event));
    area.signal_motion_notify_event().connect(sigc::mem_fun(*this, &My::Window::area_on_motion_notify_event));

    add(area);

    print_set_event_masks(area);
}

bool Window::area_on_motion_notify_event(GdkEventMotion* event)
{
    std::cout
        << "area_on_motion_notify_event(): "
        << "x=" << event->x << ","
        << "y=" << event->y
        << std::endl
    ;

    const gdouble delta_x = event->x - this->last_x;
    const gdouble delta_y = event->y - this->last_y;

    this->last_x = event->x;
    this->last_y = event->y;

    this->area_translate_x += delta_x;
    this->area_translate_y += delta_y;
    
    this->queue_draw();

    return true;
}

bool Window::area_on_button_press_event(GdkEventButton* event)
{
    std::cout
        << "area_on_button_press_event(): "
        << "button=" << event->button << ","
        << "x=" << event->x << ","
        << "y=" << event->y
        << std::endl
    ;

    this->last_x = event->x;
    this->last_y = event->y;
    
    return true;
}

bool Window::area_on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    auto a = get_allocation();

    cr->translate(this->area_translate_x, this->area_translate_y);

    //cr->scale(area_scale_x, area_scale_y);
    cr->rectangle(0, 0, 200, 200);
    cr->stroke();

    return true;
}

void Window::on_hide()
{
    auto a = get_allocation();
/*
    std::cout << "on_hide(): "
        << "x=" << a.get_x() << ", "
        << "y=" << a.get_y() << ", "
        << "width=" << a.get_width() << ", "
        << "height=" << a.get_height()
        << std::endl
        ;
*/
    boost::property_tree::ptree pt;
    pt.add("window.width", a.get_width());
    pt.add("window.height", a.get_height());
    boost::property_tree::json_parser::write_json("./settings.json", pt);
}

}   // namespace My
