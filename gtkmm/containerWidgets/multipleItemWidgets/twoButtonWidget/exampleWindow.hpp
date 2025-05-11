#pragma once

#include "glibmm/ustring.h"
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class ExampleWindow : public Gtk::Window {
  public:
  ExampleWindow();
  ~ExampleWindow();

protected:
  void on_btn_clicked(const Glib::ustring& data);

  Gtk::Box m_box1;
  Gtk::Button m_btn1, m_btn2;
};
