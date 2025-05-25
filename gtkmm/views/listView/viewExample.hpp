#pragma once

#include "glibmm/refptr.h"
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/listitem.h>
#include <gtkmm/listview.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/stringlist.h>
#include <gtkmm/window.h>

class ViewWindow : public Gtk::Window {
public:
  ViewWindow();
  ~ViewWindow();

protected:
  void onBtnQuit();
  void onSetupLabel(const Glib::RefPtr<Gtk::ListItem> &listItem);
  void onBindName(const Glib::RefPtr<Gtk::ListItem> &listItem);

  Gtk::Box m_mainBox;
  Gtk::Box m_btnBox;
  Gtk::Label m_headingLabel;
  Gtk::Button m_btnQuit;
  Gtk::ListView m_listView;
  Gtk::ScrolledWindow m_scrolledWindow;

  Glib::RefPtr<Gtk::StringList> m_stringList;
};
