#include "toggleWidget.hpp"
#include <iostream>

ToggleButtonWidget::ToggleButtonWidget() {
  set_title("Toggle Buttons");
  set_default_size(300, 400);

  m_toggle_1.set_label("Toggle Button 1");
  m_toggle_1.set_margin(10);

  m_toggle_1.signal_toggled().connect(
      sigc::mem_fun(*this, &ToggleButtonWidget::on_press_toggle));
  set_child(m_toggle_1);
}

ToggleButtonWidget::~ToggleButtonWidget() {}

void ToggleButtonWidget::on_press_toggle() {
  if (m_toggle_1.get_active()) {
    std::cout << "Toggled on" << std::endl;
  } else {
    std::cout << "Toggled off" << std::endl;
  }
}
