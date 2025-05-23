#pragma once
#include <gtkmm.h>

class PackBox : public Gtk::Box {
public:
  PackBox(bool homogeneous = false, int spacing = 0, bool expand = false,
          Gtk::Align align = Gtk::Align::FILL, int margin = 0);

protected:
  Gtk::Button m_buttons[4];
};
