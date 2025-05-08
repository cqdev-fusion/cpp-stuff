#pragma once

#include "glibmm/refptr.h"
#include "gtkmm/listitem.h"
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/listview.h>
#include <gtkmm/stringlist.h>

class MessageList : public Gtk::ScrolledWindow {
  public:
  MessageList();
  ~MessageList();

  protected:
    void on_setup_message(const Glib::RefPtr<Gtk::ListItem>& list_item);
    void on_bind_message(const Glib::RefPtr<Gtk::ListItem>& list_item);

  Glib::RefPtr<Gtk::StringList> m_refStringList; 
  Gtk::ListView m_listView;
};
