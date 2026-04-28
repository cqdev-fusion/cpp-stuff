#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloGtkmm : public Gtk::Window {
public:
  HelloGtkmm();
  ~HelloGtkmm();

protected:
  void onBtnClicked();

  Gtk::Button m_btn1;
};
