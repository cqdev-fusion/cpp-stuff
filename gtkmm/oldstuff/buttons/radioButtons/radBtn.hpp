#pragma once
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/separator.h>
#include <gtkmm/window.h>

class RadioButtons : public Gtk::Window {
public:
  RadioButtons();
  ~RadioButtons();

protected:
  void on_btn_clicked();

  Gtk::Box m_box_main, m_box_top, m_box_bottom;
  Gtk::CheckButton m_radioBtn1, m_radioBtn2, m_radioBtn3;
  Gtk::Separator m_separator;
  Gtk::Button m_closeBtn;
};
