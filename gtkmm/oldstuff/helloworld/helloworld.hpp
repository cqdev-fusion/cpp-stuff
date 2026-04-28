#pragma once

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window {
public:
  HelloWorld();
  virtual ~HelloWorld();

protected:
  // Signal Handler
  void on_btn_pressed();

  // Member Widgets
  Gtk::Button m_btn1;
};
