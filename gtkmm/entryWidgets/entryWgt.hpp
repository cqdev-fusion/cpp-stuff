#pragma once
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/entry.h>
#include <gtkmm/window.h>

class EntryWidget : public Gtk::Window {
public:
  EntryWidget();
  ~EntryWidget();

protected:
  void on_cb_editable_toggled();
  void on_cb_visibility_toggled();
  void on_btn_close();

  Gtk::Box m_HBox, m_VBox;
  Gtk::Entry m_entry;
  Gtk::Button m_btn_close;
  Gtk::CheckButton m_cb_editable, m_cb_visible;
};
