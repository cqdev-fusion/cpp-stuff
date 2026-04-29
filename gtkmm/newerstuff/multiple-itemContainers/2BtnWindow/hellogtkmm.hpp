#pragma once

#include "glibmm/ustring.h"
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Hellogtkmm : public Gtk::Window {
public:
  Hellogtkmm();
  ~Hellogtkmm();

protected:
  void onBtnClicked(const Glib::ustring &data);

  Gtk::Box m_box1;
  Gtk::Button m_btn1, m_btn2;
};
