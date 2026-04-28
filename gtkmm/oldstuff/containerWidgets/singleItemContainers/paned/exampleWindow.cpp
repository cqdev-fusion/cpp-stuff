#include "exampleWindow.hpp"
#include "gtkmm/enums.h"

ExampleWindow::ExampleWindow() : m_VPaned(Gtk::Orientation::VERTICAL) {
  set_title("Panned Windows");
  set_default_size(450, 400);
  m_VPaned.set_margin(10);
  
  set_child(m_VPaned);

  m_VPaned.set_start_child(m_message_list);
  m_VPaned.set_end_child(m_message_text);
}

ExampleWindow::~ExampleWindow(){}
