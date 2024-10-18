#include "helloworld.hpp"
#include "sigc++/functors/mem_fun.h"
#include <iostream>

const int SCREEN_WIDTH{250};
const int SCREEN_HEIGHT{250};

HelloWorld::HelloWorld() : m_btn1("click Me") {
  set_title("Hello World Button");
  set_margin(10);
  set_default_size(SCREEN_WIDTH, SCREEN_HEIGHT);

  m_btn1.signal_clicked().connect(
      sigc::mem_fun(*this, &HelloWorld::on_btn_pressed));
  set_child(m_btn1);
}

HelloWorld::~HelloWorld() {}

void HelloWorld::on_btn_pressed() {
  std::cout << "Button was pressed" << std::endl;
}
