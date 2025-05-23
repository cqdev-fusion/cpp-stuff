#pragma once
#include "messageList.hpp"
#include "messageText.hpp"
#include <gtkmm/paned.h>
#include <gtkmm/window.h>

class ExampleWindow : public Gtk::Window {
public:
  ExampleWindow();
  ~ExampleWindow();

protected:
  Gtk::Paned m_VPaned;
  MessageList m_message_list;
  MessageText m_message_text;
};
