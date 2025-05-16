#pragma once
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/separator.h>
#include <gtkmm/window.h>

class ExampleWindow : public Gtk::Window {
public:
  ExampleWindow(int which);
  ~ExampleWindow();

protected:
  void on_btn_quit_clicked();

  Gtk::Box m_box1;
  Gtk::Box m_box_quit;

  Gtk::Button m_btn;
  Gtk::Button m_btn_quit;

  Gtk::Label m_label1, m_label2;

  Gtk::Separator m_seperator1, m_seperator2;
};
