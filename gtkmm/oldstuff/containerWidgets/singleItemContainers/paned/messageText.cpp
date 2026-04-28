#include "messageText.hpp"
#include "gtkmm/enums.h"

MessageText::MessageText(){
  set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  set_child(m_textView);
  insert_text();
}

MessageText::~MessageText(){}

void MessageText::insert_text()
{
  auto refTextBuffer = m_textView.get_buffer();

  auto iter = refTextBuffer->get_iter_at_offset(0);
  refTextBuffer->insert(iter,
    "From: pathfinder@nasa.gov\n"
    "To: mom@nasa.gov\n"
    "Subject: Made it!\n"
    "\n"
    "We just got in this morning. The weather has been\n"
    "great - clear but cold, and there are lots of fun sights.\n"
    "Sojourner says hi. See you soon.\n"
    " -Path\n");
}
