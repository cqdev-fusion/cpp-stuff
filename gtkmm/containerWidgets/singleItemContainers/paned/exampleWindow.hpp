#pragma once
#include "messageList.hpp"
#include "messageText.hpp"
#include <gtkmm/window.h>
#include <gtkmm/paned.h>

class ExampleWindow : public Gtk::Window {
  public:
   ExampleWindow();
  ~ExampleWindow();

  protected:
   Gtk::Paned m_VPaned;
  MessageList m_message_list;
  MessageText m_message_text;
};
