#include "hellogtkmm.hpp"
#include "sigc++/functors/mem_fun.h"
#include <iostream>

HelloGtkmm::HelloGtkmm() : m_btn1("Press Me") {
  static int MAX_WIDTH{800};
  static int MAX_HEIGHT{600};

  set_title("Hello Gtkmm");
  set_default_size(MAX_WIDTH, MAX_HEIGHT);

  m_btn1.set_margin(10);
  m_btn1.signal_clicked().connect(
      sigc::mem_fun(*this, &HelloGtkmm::onBtnClicked));
  set_child(m_btn1);
}

HelloGtkmm::~HelloGtkmm() {}

void HelloGtkmm::onBtnClicked() {
  std::cout << "Button 1 was clicked" << std::endl;
}
