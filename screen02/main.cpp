#include <iostream>
#include <gtkmm.h>
#include <string>

#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <boost/filesystem.hpp>

namespace My
{

#define CASE_GDK_SCROLL_DIRECTION(gdk_scroll_direction) case gdk_scroll_direction: return #gdk_scroll_direction

std::string gdk_scroll_direction_to_string(GdkScrollDirection gdk_scroll_direction)
{
    switch(gdk_scroll_direction)
    {
        CASE_GDK_SCROLL_DIRECTION(GDK_SCROLL_UP);
        CASE_GDK_SCROLL_DIRECTION(GDK_SCROLL_DOWN);
        CASE_GDK_SCROLL_DIRECTION(GDK_SCROLL_LEFT);
        CASE_GDK_SCROLL_DIRECTION(GDK_SCROLL_RIGHT);
        CASE_GDK_SCROLL_DIRECTION(GDK_SCROLL_SMOOTH);
    }

    return "";
}

void print_set_event_masks(Gtk::Widget& widget)
{
    if(Gdk::EventMask::EXPOSURE_MASK & widget.get_events()) std::cout << "EXPOSURE_MASK" << std::endl;
    if(Gdk::EventMask::POINTER_MOTION_MASK & widget.get_events()) std::cout << "POINTER_MOTION_MASK" << std::endl;
    if(Gdk::EventMask::POINTER_MOTION_HINT_MASK & widget.get_events()) std::cout << "POINTER_MOTION_HINT_MASK" << std::endl;
    if(Gdk::EventMask::BUTTON_MOTION_MASK & widget.get_events()) std::cout << "BUTTON_MOTION_MASK" << std::endl;
    if(Gdk::EventMask::BUTTON1_MOTION_MASK & widget.get_events()) std::cout << "BUTTON1_MOTION_MASK" << std::endl;
    if(Gdk::EventMask::BUTTON2_MOTION_MASK & widget.get_events()) std::cout << "BUTTON2_MOTION_MASK" << std::endl;
    if(Gdk::EventMask::BUTTON3_MOTION_MASK & widget.get_events()) std::cout << "BUTTON3_MOTION_MASK" << std::endl;
    if(Gdk::EventMask::BUTTON_PRESS_MASK & widget.get_events()) std::cout << "BUTTON_PRESS_MASK" << std::endl;
    if(Gdk::EventMask::BUTTON_RELEASE_MASK & widget.get_events()) std::cout << "BUTTON_RELEASE_MASK" << std::endl;
    if(Gdk::EventMask::ENTER_NOTIFY_MASK & widget.get_events()) std::cout << "ENTER_NOTIFY_MASK" << std::endl;
    if(Gdk::EventMask::LEAVE_NOTIFY_MASK & widget.get_events()) std::cout << "LEAVE_NOTIFY_MASK" << std::endl;
    if(Gdk::EventMask::FOCUS_CHANGE_MASK & widget.get_events()) std::cout << "FOCUS_CHANGE_MASK" << std::endl;
    if(Gdk::EventMask::STRUCTURE_MASK & widget.get_events()) std::cout << "STRUCTURE_MASK" << std::endl;
    if(Gdk::EventMask::PROPERTY_CHANGE_MASK & widget.get_events()) std::cout << "PROPERTY_CHANGE_MASK" << std::endl;
    if(Gdk::EventMask::VISIBILITY_NOTIFY_MASK & widget.get_events()) std::cout << "VISIBILITY_NOTIFY_MASK" << std::endl;
    if(Gdk::EventMask::PROXIMITY_IN_MASK & widget.get_events()) std::cout << "PROXIMITY_IN_MASK" << std::endl;
    if(Gdk::EventMask::PROXIMITY_OUT_MASK & widget.get_events()) std::cout << "PROXIMITY_OUT_MASK" << std::endl;
    if(Gdk::EventMask::SUBSTRUCTURE_MASK & widget.get_events()) std::cout << "SUBSTRUCTURE_MASK" << std::endl;
    if(Gdk::EventMask::SCROLL_MASK & widget.get_events()) std::cout << "SCROLL_MASK" << std::endl;
    if(Gdk::EventMask::TOUCH_MASK & widget.get_events()) std::cout << "TOUCH_MASK" << std::endl;
    if(Gdk::EventMask::SMOOTH_SCROLL_MASK & widget.get_events()) std::cout << "SMOOTH_SCROLL_MASK" << std::endl;
    if(Gdk::EventMask::TOUCHPAD_GESTURE_MASK & widget.get_events()) std::cout << "TOUCHPAD_GESTURE_MASK" << std::endl;
    if(Gdk::EventMask::TABLET_PAD_MASK & widget.get_events()) std::cout << "TABLET_PAD_MASK" << std::endl;
}

class Window : public Gtk::Window
{
public:
    Window(const boost::property_tree::ptree& pt)
    {
        set_default_size(
            pt.get<int>("window.width", 800), 
            pt.get<int>("window.height", 600)
            );

        area.set_events(Gdk::EventMask::SCROLL_MASK);
        area.signal_draw().connect(sigc::mem_fun(*this, &My::Window::area_on_draw));
        area.signal_scroll_event().connect(sigc::mem_fun(*this, &My::Window::area_on_scroll_event));
        add(area);

        print_set_event_masks(area);
    }

private:
    Gtk::DrawingArea area;
    double area_translate_x = 1.0;
    double area_translate_y = 1.0;

private:
    void on_hide() override
    {
        auto a = get_allocation();

        std::cout << "on_hide(): "
            << "x=" << a.get_x() << ", "
            << "y=" << a.get_y() << ", "
            << "width=" << a.get_width() << ", "
            << "height=" << a.get_height()
            << std::endl
            ;

        boost::property_tree::ptree pt;
        pt.add("window.width", a.get_width());
        pt.add("window.height", a.get_height());
        boost::property_tree::json_parser::write_json("./settings.json", pt);
    }

/*     void on_size_allocate(Gtk::Allocation& allocation) override
    {
        std::cout << "on_size_allocate(): "
            << "x=" << allocation.get_x() << ", "
            << "y=" << allocation.get_y() << ", "
            << "width=" << allocation.get_width() << ", "
            << "height=" << allocation.get_height()
            << std::endl
            ;

        Gtk::Window::on_size_allocate(allocation);
    }
 */
    bool area_on_scroll_event(GdkEventScroll* event)
    {
/*         std::cout << "INFO: area_on_scroll_event(): " 
            << "x=" << event->x << ","
            << "y=" << event->y << ","
            << "state=" << event->state << ","
            << "direction=" << gdk_scroll_direction_to_string(event->direction) << ","
            << "x_root=" << event->x_root << ","
            << "y_root=" << event->x_root << ","
            << "delta_x=" << event->delta_x << ","
            << "delta_y=" << event->delta_y << ","
            << "is_stop=" << event->is_stop
            << std::endl;
            ;
 */        
        double& area_translate = event->state & GdkModifierType::GDK_SHIFT_MASK ? area_translate_x : area_translate_y;

        if(event->direction == GDK_SCROLL_UP)
        {
            area_translate += 1;
        }

        if(event->direction == GDK_SCROLL_DOWN)
        {
            area_translate -= 1;
        }

        area.queue_draw();

        return true;
    }

    bool area_on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
    {
        cr->translate(area_translate_x, area_translate_y);

        //cr->scale(area_scale_x, area_scale_y);
        cr->rectangle(0, 0, 20, 100);
        cr->stroke();

        cr->move_to(10, 0);
        cr->line_to(10, -20);
        cr->stroke();

        return true;
    }
};  // calss Window

}   // namespace My

namespace fs = boost::filesystem;

constexpr auto settings_filename = "settings.json";

int main(int argc, char* argv[]) 
{
    try
    {
        auto app = Gtk::Application::create(argc, argv, "com.gnome.examples.screen01");

        boost::property_tree::ptree pt;

        if(fs::exists(settings_filename))
        {
            boost::property_tree::json_parser::read_json(settings_filename, pt);
        }

        My::Window win{pt};
        win.show_all();

        return app->run(win);
    }
    catch(const std::exception& e)
    {
        std::cerr << "main(): Exception caught: '" << e.what() << "'" << std::endl;
    }
}
