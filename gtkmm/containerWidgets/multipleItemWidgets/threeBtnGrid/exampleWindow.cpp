#include "exampleWindow.hpp"
#include "glibmm/ustring.h"
#include "gtkmm/enums.h"
#include "sigc++/adaptors/bind.h"
#include "sigc++/functors/mem_fun.h"
#include <iostream>

ExampleWindow::ExampleWindow() :
  m_btn1("Button 1"),
  m_btn2("Button 2"),
  m_btn_quit("Quit") {
  
  set_title("3 Button Grid");
  m_grid.set_margin(10);
  set_child(m_grid);

  m_grid.attach(m_btn1, 0, 0);
  m_grid.attach(m_btn2, 1, 0);
  m_grid.attach_next_to(m_btn_quit, m_btn1, Gtk::PositionType::BOTTOM, 2, 1);

  m_btn1.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &ExampleWindow::on_btn_clicked), "button 1"));
  m_btn2.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &ExampleWindow::on_btn_clicked), "button 2"));
  m_btn_quit.signal_clicked().connect(sigc::mem_fun(*this, & ExampleWindow::on_btn_close));
}

ExampleWindow::~ExampleWindow(){}

void ExampleWindow::on_btn_close(){
  set_visible(false);
}

void ExampleWindow::on_btn_clicked(const Glib::ustring& data) {
  std::cout << data << " was clicked" << std::endl;
}
