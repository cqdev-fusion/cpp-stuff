#include "buttonWidget.hpp"
#include "sigc++/functors/mem_fun.h"

#include <iostream>

const int SCREEN_WIDTH{600};
const int SCREEN_HEIGHT{400};

BasicWindow::BasicWindow() : m_btn_1("Click Here") {
  set_title("Basic Button");
  set_default_size(SCREEN_WIDTH, SCREEN_HEIGHT);
  set_margin(10);

  m_btn_1.signal_clicked().connect(
      sigc::mem_fun(*this, &BasicWindow::on_btn_pressed));
  set_child(m_btn_1);
}

BasicWindow::~BasicWindow() {}

void BasicWindow::on_btn_pressed() {
  std::cout << "Button Pressed" << std::endl;
}
