#include "radBtn.hpp"
#include "gtkmm/enums.h"
#include "sigc++/functors/mem_fun.h"

RadioButtons::RadioButtons()
    : m_box_main(Gtk::Orientation::VERTICAL),
      m_box_top(Gtk::Orientation::VERTICAL, 10),
      m_box_middle(Gtk::Orientation::VERTICAL, 10),
      m_box_bottom(Gtk::Orientation::VERTICAL, 10), m_rb1("Radio 1"),
      m_rb2("Radio 2"), m_rb3("Radio 3"), m_rb4("Radio 4"), m_rb5("Radio 5"),
      m_rb6("Radio 6"), m_btn_cancel("Close") {
  set_title("Radio Buttons");
  set_child(m_box_main);

  // Set the groups
  m_rb2.set_group(m_rb1);
  m_rb4.set_group(m_rb3);
  m_rb6.set_group(m_rb5);

  // Place boxes in main with separators
  m_box_main.append(m_box_top);
  m_box_main.append(m_sep1);
  m_box_main.append(m_box_middle);
  m_box_main.append(m_sep2);
  m_box_main.append(m_box_bottom);
  m_box_main.append(m_sep3);
  m_box_main.append(m_box_btns);

  // Set margins
  m_box_top.set_margin(10);
  m_box_middle.set_margin(10);
  m_box_bottom.set_margin(10);
  m_box_btns.set_margin(10);

  // Place buttons in required box.
  m_box_top.append(m_rb1);
  m_box_top.append(m_rb2);
  m_rb1.set_expand();
  m_rb2.set_expand();

  m_box_middle.append(m_rb3);
  m_box_middle.append(m_rb4);
  m_rb3.set_expand();
  m_rb4.set_expand();

  m_box_bottom.append(m_rb5);
  m_box_bottom.append(m_rb6);
  m_rb5.set_expand();
  m_rb6.set_expand();

  m_box_btns.append(m_btn_cancel);
  m_btn_cancel.set_expand();

  m_rb2.set_active(true);

  set_default_widget(m_btn_cancel);

  m_btn_cancel.signal_clicked().connect(
      sigc::mem_fun(*this, &RadioButtons::on_btn_clicked));
}

RadioButtons::~RadioButtons() {}

void RadioButtons::on_btn_clicked() { set_visible(false); }
