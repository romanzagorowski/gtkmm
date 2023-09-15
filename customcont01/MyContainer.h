#pragma once

#include <gtkmm/widget.h>

namespace Abc
{
    class MyContainer : public Gtk::Widget
    {
    public:
        MyContainer();
        ~MyContainer() override;

        void set_child_widgets(Gtk::Widget& child_one, Gtk::Widget& child_two);

    protected:
        // Overrides
        Gtk::SizeRequestMode get_request_mode_vfunc() const override;

        void measure_vfunc(Gtk::Orientation orientation, int for_size, int& minimum, int& natural, int& minimum_baseline, int& natural_baseline) const override;

        void size_allocate_vfunc(int width, int height, int baseline) override;

#if 0
        void forall_vfunc(const ForeachSlot& slot) override;

        void on_add(Gtk::Widget* child) override;
        void on_remove(Gtk::Widget* child) override;
        GType child_type_vfunc() const override;
#endif
        Gtk::Widget* child_one_;
        Gtk::Widget* child_two_;
    };
}
