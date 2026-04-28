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

  Gtk::Box m_box_main, m_box_top, m_box_middle, m_box_bottom, m_box_btns;
  Gtk::CheckButton m_rb1, m_rb2, m_rb3, m_rb4, m_rb5, m_rb6;
  Gtk::Separator m_sep1, m_sep2, m_sep3;
  Gtk::Button m_btn_cancel;
};
