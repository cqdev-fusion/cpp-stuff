#include "exampleWindow.hpp"
#include "gtk/gtk.h"
#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include "packBox.hpp"
#include "sigc++/functors/mem_fun.h"
#include <iostream>

ExampleWindow::ExampleWindow(int which)
    : m_box1(Gtk::Orientation::VERTICAL), m_btn_quit("Quit") {
  set_title("Gtk::Box::Example");

  m_seperator1.set_margin_top(5);
  m_seperator1.set_margin_bottom(5);

  m_seperator2.set_margin_top(5);
  m_seperator2.set_margin_top(5);

  switch (which) {
  case 1: {
    m_label1.set_text(
        "Gtk::Box(Gtk::Orientation::HORIZONTAL, 0); set_homogeneous(false);");

    // Align the label to the left
    m_label1.set_halign(Gtk::Align::START);
    m_label1.set_valign(Gtk::Align::START);

    // Pack label into the vertical box (vbox box1)
    // Widgets added to a vbox will be packed ontop of each other
    // Order
    m_box1.append(m_label1);

    // Create the PackBox
    // homogeneous = false, spacing = 0, expand = false, Gtk::Align::Fill,
    // margin = 0
    auto pPackBox = Gtk::make_managed<PackBox>();
    m_box1.append(*pPackBox);

    // homogeneous = false, spacing = 0, expand = true, Gtk::Align::CENTER,
    // margin = 0
    pPackBox =
        Gtk::make_managed<PackBox>(false, 0, true, Gtk::Align::CENTER, 0);
    m_box1.append(*pPackBox);

    // homogeneous = false, spacing = 0, expand = true, Gtk::Align::FILL,
    // margin = 0
    pPackBox = Gtk::make_managed<PackBox>(false, 0, true, Gtk::Align::FILL, 0);
    m_box1.append(*pPackBox);

    // Pack the seperator into the vbox.
    m_box1.append(m_seperator1);

    // Create another new label and show it.
    m_label2.set_text(
        "Gtk::Box(Gtk::Orientation::Horizontal, 0; set_homogeneous(true);");
    m_label2.set_halign(Gtk::Align::START);
    m_label2.set_valign(Gtk::Align::START);
    m_box1.append(m_label2);

    // Args are homogeneous, spacing, expand, align, margin
    pPackBox = Gtk::make_managed<PackBox>(true, 0, true, Gtk::Align::CENTER);
    m_box1.append(*pPackBox);
    m_box1.append(m_seperator2);
    break;
  }

  case 2: {
    m_label1.set_text(
        "Gtk::Box(Gtk::Orientation::Horizontal,0); set_homogeneous(true)");
    m_label1.set_halign(Gtk::Align::START);
    m_label1.set_valign(Gtk::Align::START);
    m_box1.append(m_label1);

    auto pPackBox =
        Gtk::make_managed<PackBox>(false, 10, true, Gtk::Align::CENTER);
    m_box1.append(*pPackBox);

    pPackBox = Gtk::make_managed<PackBox>(false, 10, true);
    m_box1.append(*pPackBox);

    m_box1.append(m_seperator1);

    m_label2.set_text(
        "Gtk::Box(Gtk::Orientation::Horizontal, 0); set_homogeneous(false);");

    m_label2.set_halign(Gtk::Align::START);
    m_label2.set_valign(Gtk::Align::START);
    m_box1.append(m_label2);

    pPackBox =
        Gtk::make_managed<PackBox>(false, 0, false, Gtk::Align::FILL, 10);
    m_box1.append(*pPackBox);

    pPackBox = Gtk::make_managed<PackBox>(false, 0, true, Gtk::Align::FILL, 10);
    m_box1.append(*pPackBox);

    m_box1.append(m_seperator2);
    break;
  }

  case 3: {
    // this demonstrates the ability to use Gtk::Align::END to right justify
    // widgets.
    auto pPackBox = Gtk::make_managed<PackBox>();

    // Create the label that will be placed at the end.
    m_label1.set_text("end");

    m_label1.set_halign(Gtk::Align::END);
    m_label1.set_expand(true);
    pPackBox->append(m_label1);

    m_box1.append(*pPackBox);

    // Explicitly sets the separator 700px wide by 5px high.
    // This is so the hbox we create will also be 700.
    // The "end" label will be seperated from the other labels in the hbox.
    // Otherwise all the widgets in the hbox will be packed too close together.
    m_seperator1.set_size_request(700, 5);

    // Packing the seperator into the box.
    m_box1.append(m_seperator1);

    break;
  }
  default: {

    std::cerr << "Unexpectd command line option. " << std::endl;
    break;
  }
  }

  m_btn_quit.signal_clicked().connect(
      sigc::mem_fun(*this, &ExampleWindow::on_btn_quit_clicked));
  m_box_quit.append(m_btn_quit);
  m_btn_quit.set_hexpand(true);
  m_btn_quit.set_halign(Gtk::Align::CENTER);
  m_box1.append(m_box_quit);
  set_child(m_box1);
}

ExampleWindow::~ExampleWindow() {}

void ExampleWindow::on_btn_quit_clicked() { set_visible(false); }
