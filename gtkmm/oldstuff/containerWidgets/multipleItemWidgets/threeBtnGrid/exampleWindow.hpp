#pragma once
#include "glibmm/ustring.h"
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <gtkmm/window.h>

class ExampleWindow:  public Gtk::Window {
  public: 
  ExampleWindow();
  ~ExampleWindow();

private:
  void on_btn_close();
  void on_btn_clicked(const Glib::ustring& data);

  Gtk::Button m_btn1, m_btn2, m_btn_quit;
  Gtk::Grid m_grid;
};

