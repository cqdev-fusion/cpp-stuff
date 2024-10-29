#pragma once
#include <gtkmm/window.h>
#include <gtkmm/checkbutton.h>

class MyCbtn : public Gtk::Window {
public:
 MyCbtn();
  ~MyCbtn();
protected:
  void on_btn_checked();

  Gtk::CheckButton m_cb1;
  
};

