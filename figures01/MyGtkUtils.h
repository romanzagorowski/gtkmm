#pragma once

#include <gtkmm/widget.h>

namespace My
{

std::string gdk_scroll_direction_to_string(GdkScrollDirection gdk_scroll_direction);
void print_set_event_masks(Gtk::Widget& widget);

}   // namespace My
