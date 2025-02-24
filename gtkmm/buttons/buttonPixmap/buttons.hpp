#pragma once

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Buttons : public Gtk::Window {
public:
  Buttons();
  ~Buttons();

protected:
  void on_btn_clicked();

  Gtk::Button m_btn1;
};
