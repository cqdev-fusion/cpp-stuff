#include "buttons.hpp"
#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include "sigc++/functors/mem_fun.h"
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <iostream>

Buttons::Buttons() {
  auto pmap = Gtk::make_managed<Gtk::Image>(
      "/usr/share/icons/Adwaita/symbolic/actions/help-about-symbolic.svg");
  auto lable = Gtk::make_managed<Gtk::Label>("Cool Button");
  lable->set_expand(true);

  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(*pmap);
  hbox->append(*lable);

  m_btn1.set_child(*hbox);

  set_title("Pixmap'd buttons");

  m_btn1.signal_clicked().connect(
      sigc::mem_fun(*this, &Buttons::on_btn_clicked));

  m_btn1.set_margin(10);
  set_child(m_btn1);
}

Buttons::~Buttons() {}

void Buttons::on_btn_clicked() {
  std::cout << "Button was clicked" << std::endl;
}
