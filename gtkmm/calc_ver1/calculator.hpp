#pragma once
#include "gtkmm/entry.h"
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <gtkmm/window.h>

class CalcWindow : public Gtk::Window {
public:
  CalcWindow();
  ~CalcWindow();
  float z{};
  float strx{};
  float stry{};
  char *pEnd;
  std::string op;
  std::string x;
  std::string y;
  char opc;

  const int BUTTON_HEIGHT{100};
  const int BUTTON_WIDTH{100};

protected:
  void on_btn1_click();
  void on_btn2_click();
  void on_btn3_click();
  void on_btn4_click();
  void on_btn5_click();
  void on_btn6_click();
  void on_btn7_click();
  void on_btn8_click();
  void on_btn9_click();
  void on_btn0_click();

  void on_btnPlus_click();
  void on_btnMinus_click();
  void on_btnMultiply_click();
  void on_btnDivide_click();
  void on_btnClear_click();
  void on_btnEqual_click();

  Gtk::Button m_btn0, m_btn1, m_btn2, m_btn3, m_btn4, m_btn5, m_btn6, m_btn7,
      m_btn8, m_btn9, m_btnPlus, m_btnMinus, m_btnMultiply, m_btnDivide,
      m_btnClear, m_btnEqual;

  Gtk::Entry m_text;
  Gtk::Grid m_grid;
};
