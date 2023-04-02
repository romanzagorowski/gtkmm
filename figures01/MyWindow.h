#pragma once

#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>

#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/property_tree/ptree.hpp>

namespace My
{

class Window : public Gtk::Window
{
public:
    Window(const boost::property_tree::ptree& pt);

private:
    Gtk::DrawingArea area;
    gdouble area_translate_x = 0;
    gdouble area_translate_y = 0;

    gdouble last_x;
    gdouble last_y;

private:
    bool area_on_motion_notify_event(GdkEventMotion* event);
    bool area_on_button_press_event(GdkEventButton* event);
    bool area_on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

    void on_hide() override;

};  // calss Window

}   // namespace My
