#pragma once
#include <gtkmm/checkbutton.h>
#include <gtkmm/window.h>

class MyCbtn : public Gtk::Window {
public:
  MyCbtn();
  ~MyCbtn();

protected:
  void on_btn_checked();

  Gtk::CheckButton m_cb1;
};
