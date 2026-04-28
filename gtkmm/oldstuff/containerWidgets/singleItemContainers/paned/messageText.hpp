#pragma once

#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>

class MessageText : public Gtk::ScrolledWindow {
  public:
  MessageText();
  ~MessageText();

  void insert_text();

  protected:

  Gtk::TextView m_textView;
};
