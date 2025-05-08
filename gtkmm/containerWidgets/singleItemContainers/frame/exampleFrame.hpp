#pragma once 

#include <gtkmm/window.h>
#include <gtkmm/frame.h>

class SingleFrameExample : public Gtk::Window {
  public:
    SingleFrameExample();
    ~SingleFrameExample();

  protected:
    Gtk::Frame m_frame;
};
