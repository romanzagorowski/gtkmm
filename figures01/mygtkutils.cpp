#include "mygtkutils.h"
#include <iostream>

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

}   // namespace My
