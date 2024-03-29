#include "MyContainer.h"

#include <iostream>

Abc::MyContainer::MyContainer() :
    child_one_{nullptr},
    child_two_{nullptr}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Abc::MyContainer::~MyContainer()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if(child_one_) child_one_->unparent();
    if(child_two_) child_two_->unparent();
}

void Abc::MyContainer::set_child_widgets(
    Gtk::Widget& widget_one,
    Gtk::Widget& widget_two
)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    child_one_ = &widget_one;
    child_two_ = &widget_two;

    child_one_->set_parent(*this);
    child_two_->set_parent(*this);
}

// This example container is a simplified vertical Box with at most 2 children.
Gtk::SizeRequestMode Abc::MyContainer::get_request_mode_vfunc() const
{
    return Gtk::SizeRequestMode::HEIGHT_FOR_WIDTH;
}

// Discover the total amount of minimum space and natural space needed by this container and its children.
void Abc::MyContainer::measure_vfunc(
    Gtk::Orientation orientation,
    int for_size,
    int& minimum,
    int& natural,
    int& minimum_baseline,
    int& natural_baseline
) const
{
    // Don't use baseline aligment.
    minimum_baseline = -1;
    natural_baseline = -1;

    int dummy_minimum_baseline = 0;
    int dummy_natural_baseline = 0;

    if(orientation == Gtk::Orientation::HORIZONTAL)
    {
        int height_per_child = for_size;

        if(for_size >= 0)
        {
            int visible_children = 0;

            // Get number of visible children
            if(child_one_ != nullptr && child_one_->get_visible())
            {
                visible_children += 1;
            }
            if(child_two_ != nullptr && child_two_->get_visible())
            {
                visible_children += 1;
            }

            // Divide the height equally among the visible children.
            if(visible_children > 0)
            {
                height_per_child = for_size / visible_children;
            }

            int child_minimum_width[2]{};
            int child_natural_width[2]{};

            if(child_one_ != nullptr && child_one_->get_visible())
            {
                child_one_->measure(
                    orientation,
                    height_per_child,
                    child_minimum_width[0],
                    child_natural_width[0],
                    dummy_minimum_baseline,
                    dummy_natural_baseline
                );
            }

            if(child_two_ != nullptr && child_two_->get_visible())
            {
                child_two_->measure(
                    orientation,
                    height_per_child,
                    child_minimum_width[1],
                    child_natural_width[1],
                    dummy_minimum_baseline,
                    dummy_natural_baseline
                );
            }

            // Request the width equal to the width of the widest visible child.
            minimum = std::max(child_minimum_width[0], child_minimum_width[1]);
            natural = std::max(child_natural_width[0], child_natural_width[1]);
        }
    }
    else    // Gtk::Orientation::VERTICAL
    {
        int child_minimum_height[2]{};
        int child_natural_height[2]{};
        int visible_children = 0;

        if(child_one_ != nullptr && child_one_->get_visible())
        {
            ++visible_children;
            child_one_->measure(
                orientation,
                for_size,
                child_minimum_height[0],
                child_natural_height[0],
                dummy_minimum_baseline,
                dummy_natural_baseline
            );
        }

        if(child_two_ != nullptr && child_two_->get_visible())
        {
            ++visible_children;
            child_two_->measure(
                orientation,
                for_size,
                child_minimum_height[1],
                child_natural_height[1],
                dummy_minimum_baseline,
                dummy_natural_baseline
            );
        }

        // The allocated height will be divided equally among the visible childred.
        // Request a height equal to the number of visible children times the height of the highest child.
        minimum = visible_children * std::max(child_minimum_height[0], child_minimum_height[1]);
        natural = visible_children * std::max(child_natural_height[0], child_natural_height[1]);
    }
}

void Abc::MyContainer::size_allocate_vfunc(int width, int height, int baseline)
{
    // Do something with the space that we have actually been given.
    // We will not be given heights or widths less than we have requested,
    // though we might get more.

    // Get number of visible children.
    const bool visible_one = child_one_ && child_one_->get_visible();
    const bool visible_two = child_two_ && child_two_->get_visible();
    
    int visible_children = 0;
    
    if(visible_one) ++visible_children;
    if(visible_two) ++visible_children;

    if(visible_children == 0)
    {
        // No visible children at all.
        return;
    }

    // Assign space to the children.
    Gtk::Allocation child_allocation_one{};
    Gtk::Allocation child_allocation_two{};

    // Place the first child at the top-left:
    child_allocation_one.set_x(0);
    child_allocation_one.set_y(0);

    // Make it take up the full width available:
    child_allocation_one.set_width(width);

    if(visible_one)
    {
        // Divide the height equally among the visible children.
        child_allocation_one.set_height(height / visible_children);
        child_one_->size_allocate(child_allocation_one, baseline);
    }
    else 
    {
        child_allocation_one.set_height(0);
    }

    // Place the second child below the first child:
    child_allocation_two.set_x(0);
    child_allocation_two.set_y(child_allocation_one.get_height());

    // Make it take up the full width available:
    child_allocation_two.set_width(width);

    // Make it take up the remaining height:
    child_allocation_two.set_height(height - child_allocation_one.get_height());

    if(visible_two)
    {
        child_two_->size_allocate(child_allocation_two, baseline);
    }
}

#if 0
void MyContainer::forall_vfunc(const ForeachSlot& slot)
{
  if (m_child_one)
    slot(*m_child_one);

  if (m_child_two)
    slot(*m_child_two);
}

void MyContainer::on_add(Gtk::Widget* child)
{
  if(!m_child_one)
  {
    m_child_one = child;
    m_child_one->set_parent(*this);
  }
  else if(!m_child_two)
  {
    m_child_two = child;
    m_child_two->set_parent(*this);
  }
}

void MyContainer::on_remove(Gtk::Widget* child)
{
  if(child)
  {
    const bool visible = child->get_visible();
    bool found = false;

    if(child == m_child_one)
    {
      m_child_one = nullptr;
      found = true;
    }
    else if(child == m_child_two)
    {
      m_child_two = nullptr;
      found = true;
    }

    if(found)
    {
      child->unparent();

      if(visible)
        queue_resize();
    }
  }
}

GType MyContainer::child_type_vfunc() const
{
  //If there is still space for one widget, then report the type of widget that
  //may be added.
  if(!m_child_one || !m_child_two)
    return Gtk::Widget::get_type();
  else
  {
    //No more widgets may be added.
    return G_TYPE_NONE;
  }
}
#endif
