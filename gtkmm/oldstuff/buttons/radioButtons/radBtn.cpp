#include "radBtn.hpp"
#include "sigc++/functors/mem_fun.h"

RadioButtons::RadioButtons()
    : m_box_main(Gtk::Orientation::VERTICAL),
      m_box_top(Gtk::Orientation::VERTICAL, 10),
      m_box_bottom(Gtk::Orientation::VERTICAL, 10), m_radioBtn1("button 1"),
      m_radioBtn2("button 2"), m_radioBtn3("button 3"), m_closeBtn("Close") {

  set_title("Radio Buttons");

  // Gtk::CheckButton and Gtk::ToggleButton have set_group() methods.
  // They act as radio buttons, if they are included in a group.

  // Put radio buttons 2 and 3 in the same group as 1:
  m_radioBtn2.set_group(m_radioBtn1);
  m_radioBtn3.set_group(m_radioBtn1);

  // Add outer box to the window (because the window
  // can only contain a single widget)
  set_child(m_box_main);

  // put inner boxes and separator in outer box
  m_box_main.append(m_box_top);
  m_box_main.append(m_separator);
  m_box_main.append(m_box_bottom);

  // Set the inner boxes' margins
  m_box_top.set_margin(10);
  m_box_bottom.set_margin(10);

  // Put the radio buttons in m_box_top:
  m_box_top.append(m_radioBtn1);
  m_box_top.append(m_radioBtn2);
  m_box_top.append(m_radioBtn3);
  m_radioBtn1.set_expand();
  m_radioBtn2.set_expand();
  m_radioBtn3.set_expand();

  // Set the second button active
  m_radioBtn2.set_active(true);

  // Put Close button in m_box_bottom
  m_box_bottom.append(m_closeBtn);

  // Connect the toggled signal of the button to
  // RadioButtons::on_button_toggled()
  m_closeBtn.signal_clicked().connect(
      sigc::mem_fun(*this, &RadioButtons::on_btn_clicked));
}

RadioButtons::~RadioButtons() {}

void RadioButtons::on_btn_clicked() { set_visible(false); }
