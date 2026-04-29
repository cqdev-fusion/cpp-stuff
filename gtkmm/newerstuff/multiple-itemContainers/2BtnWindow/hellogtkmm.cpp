#include "hellogtkmm.hpp"
#include "sigc++/adaptors/bind.h"
#include "sigc++/functors/mem_fun.h"

#include <iostream>

Hellogtkmm::Hellogtkmm() : m_btn1("Button 1"), m_btn2("Button 2") {
  set_title("Buttons Here");
  m_box1.set_margin(10);
  set_child(m_box1);

  // Now when the button is clicked, we call the on_button_clicked() function
  // with a pointer to "button 1" as its argument.
  m_btn1.signal_clicked().connect(
      sigc::bind(sigc::mem_fun(*this, &Hellogtkmm::onBtnClicked), "Button 1"));
  // We are using Gtk::Box::append to pack this button into the box.
  // This has been packed into the window.
  m_box1.append(m_btn1);

  // Widget will not expand is there is extra space se we ste it to true
  m_btn1.set_expand(true);

  // call the same signal handler with a different argument,
  // passing a pointer to "button 2" instead.
  m_btn2.signal_clicked().connect(
      sigc::bind(sigc::mem_fun(*this, &Hellogtkmm::onBtnClicked), "Button 2"));
  m_box1.append(m_btn2);
  m_btn2.set_expand(true);
}
Hellogtkmm::~Hellogtkmm() {}

void Hellogtkmm::onBtnClicked(const Glib::ustring &data) {
  std::cout << "Hello GTKMM - " << data << " was pressed" << std::endl;
}
