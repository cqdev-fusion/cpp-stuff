#include "checkBtn.hpp"
#include <iostream>

MyCbtn::MyCbtn() : m_cb1("Click here") {
  set_title("Example CB");
  set_margin(10);

  m_cb1.signal_toggled().connect(sigc::mem_fun(*this, &MyCbtn::on_btn_checked));
  set_child(m_cb1);
  set_expand();
}

MyCbtn::~MyCbtn() {}

void MyCbtn::on_btn_checked() {
  std::cout << "The button was clicked state= "
            << (m_cb1.get_active() ? "true" : "false") << std::endl;
}
