#pragma once

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class BasicWindow : public Gtk::Window {
public:
  BasicWindow();
  ~BasicWindow();

protected:
  // Signal handlers
  void on_btn_pressed();

  // Member Widgets
  Gtk::Button m_btn_1;

private:
};
