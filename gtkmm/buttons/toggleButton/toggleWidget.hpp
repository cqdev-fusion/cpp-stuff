#pragma once
#include <gtkmm/togglebutton.h>
#include <gtkmm/window.h>

class ToggleButtonWidget : public Gtk::Window {
public:
  ToggleButtonWidget();
  ~ToggleButtonWidget();

protected:
  void on_press_toggle();

  Gtk::ToggleButton m_toggle_1;
};
