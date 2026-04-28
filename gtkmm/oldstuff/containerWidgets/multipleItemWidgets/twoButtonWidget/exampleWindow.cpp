#include "exampleWindow.hpp"
#include "glibmm/ustring.h"
#include <iostream>

ExampleWindow::ExampleWindow() : m_btn1("Button 1"), m_btn2("Button 2") {
  set_title("Two Buttons");
  m_box1.set_margin(10);
  set_child(m_box1);

  m_btn1.signal_clicked().connect(sigc::bind(
      sigc::mem_fun(*this, &ExampleWindow::on_btn_clicked), "button 1"));
  m_box1.append(m_btn1);
  m_btn1.set_expand();

  m_btn2.signal_clicked().connect(sigc::bind(
      sigc::mem_fun(*this, &ExampleWindow::on_btn_clicked), "button 2"));
  m_box1.append(m_btn2);
  m_btn2.set_expand();
}

ExampleWindow::~ExampleWindow() {}

void ExampleWindow::on_btn_clicked(const Glib::ustring &data) {
  std::cout << "Hi There - " << data << " was pressed" << std::endl;
}
