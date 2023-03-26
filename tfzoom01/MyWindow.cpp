#include "MyWindow.h"

MyWindow::MyWindow()
{
    this->scrolled.add(this->area);
    this->add(this->scrolled);
    //this->add(this->area);
}
