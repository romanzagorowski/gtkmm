#include <iostream>
//#include <iostream>
#include <gtkmm/window.h>
#include <gtkmm/application.h>

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
  /*
  POINTER_MOTION_MASK = 1 << 2,
  POINTER_MOTION_HINT_MASK = 1 << 3,
  BUTTON_MOTION_MASK = 1 << 4,
  BUTTON1_MOTION_MASK = 1 << 5,
  BUTTON2_MOTION_MASK = 1 << 6,
  BUTTON3_MOTION_MASK = 1 << 7,
  BUTTON_PRESS_MASK = 1 << 8,
  BUTTON_RELEASE_MASK = 1 << 9,
  KEY_PRESS_MASK = 1 << 10,
  KEY_RELEASE_MASK = 1 << 11,
  ENTER_NOTIFY_MASK = 1 << 12,
  LEAVE_NOTIFY_MASK = 1 << 13,
  FOCUS_CHANGE_MASK = 1 << 14,
  STRUCTURE_MASK = 1 << 15,
  PROPERTY_CHANGE_MASK = 1 << 16,
  VISIBILITY_NOTIFY_MASK = 1 << 17,
  PROXIMITY_IN_MASK = 1 << 18,
  PROXIMITY_OUT_MASK = 1 << 19,
  SUBSTRUCTURE_MASK = 1 << 20,
  SCROLL_MASK = 1 << 21,
  TOUCH_MASK = 1 << 22,
  SMOOTH_SCROLL_MASK = 1 << 23,
  TOUCHPAD_GESTURE_MASK = 1 << 24,
  TABLET_PAD_MASK = 1 << 25,
  ALL_EVENTS_MASK = 0x3FFFFFE
  */
}

namespace My
{
    class Window : public Gtk::Window
    {
    public:
        Window()
        {
            //this->on_enter_notify_event
            //this->on_leave_notify_event
            //this->on_motion_
            //this->set_events

            // std::cout << "get_events()=" << std::hex << this->get_events() << '\n';
            
            // std::cout << "POINTER_MOTION_MASK is set=" 
            //     << (Gdk::EventMask::POINTER_MOTION_MASK & this->get_events())
            //     << '\n';

            this->set_events(Gdk::EventMask::POINTER_MOTION_MASK);

            print_set_event_masks(*this);
        }

    private:
        bool on_leave_notify_event(GdkEventCrossing* e)
        {
            std::cout << "on_leave_notify_event(): "
                << "x=" << e->x << ", y=" << e->y << ", x_root=" << e->x_root << ", y_root=" << e->y_root << std::endl;

            return true;
        }

        /// This is a default handler for the signal signal_enter_notify_event().
        bool on_enter_notify_event(GdkEventCrossing* e) override
        {
            std::cout << "on_enter_notify_event(): "
                << "x=" << e->x << ", y=" << e->y << ", x_root=" << e->x_root << ", y_root=" << e->y_root << std::endl;

            return true;
        }

        /// This is a default handler for the signal signal_motion_notify_event().
        bool on_motion_notify_event(GdkEventMotion* e)
        {
            std::cout << "on_motion_notify_event(): "
                << "x=" << e->x << ", y=" << e->y << ", x_root=" << e->x_root << ", y_root=" << e->y_root << std::endl;

            return true;
        }
    };
}

int main(int argc, char* argv[]) 
{
    auto app = Gtk::Application::create(argc, argv, "org.gnome.example");

    My::Window win;
    win.set_size_request(800, 600);
    

    return app->run(win);
}
