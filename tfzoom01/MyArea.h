#pragma once

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{
public:
    MyArea();
    
private:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};
