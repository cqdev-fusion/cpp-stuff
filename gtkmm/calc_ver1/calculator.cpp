#include "calculator.hpp"
#include "gtkmm/enums.h"
#include "gtkmm/grid.h"
#include <cstdlib>
#include <string>

CalcWindow::CalcWindow()
    : m_btn0("0"), m_btn1("1"), m_btn2("2"), m_btn3("3"), m_btn4("4"),
      m_btn5("5"), m_btn6("6"), m_btn7("7"), m_btn8("8"), m_btn9("9"),
      m_btnPlus("+"), m_btnMinus("-"), m_btnMultiply("*"), m_btnDivide("/"),
      m_btnClear("Clear"), m_btnEqual("=") {
  const int SCREEN_WIDTH{800};
  const int SCREEN_HEIGHT{400};

  set_default_size(SCREEN_WIDTH, SCREEN_HEIGHT);
  m_text.set_size_request(400, 20);
  m_btn1.set_expand(true);
  m_btn2.set_expand(true);
  m_btn3.set_expand(true);
  m_btn4.set_expand(true);
  m_btn5.set_expand(true);
  m_btn6.set_expand(true);
  m_btn7.set_expand(true);
  m_btn8.set_expand(true);
  m_btn9.set_expand(true);
  m_btn0.set_expand(true);
  m_btnPlus.set_expand(true);
  m_btnMinus.set_expand(true);
  m_btnDivide.set_expand(true);
  m_btnEqual.set_expand(true);
  m_btnClear.set_expand(true);

  m_btn0.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn0_click));

  m_btn1.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn1_click));

  m_btn2.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn2_click));
  m_btn3.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn3_click));
  m_btn4.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn4_click));
  m_btn5.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn5_click));
  m_btn6.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn6_click));
  m_btn7.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn7_click));
  m_btn8.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn8_click));
  m_btn9.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btn9_click));
  m_btnPlus.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btnPlus_click));
  m_btnMinus.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btnMinus_click));
  m_btnMultiply.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btnMultiply_click));
  m_btnDivide.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btnDivide_click));
  m_btnClear.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btnClear_click));
  m_btnEqual.signal_clicked().connect(
      sigc::mem_fun(*this, &CalcWindow::on_btnEqual_click));

  m_grid.set_margin(12);
  m_grid.attach(m_text, 0, 0);
  m_grid.attach(m_btn1, 1, 0);
  m_grid.attach(m_btn2, 2, 0);
  m_grid.attach(m_btn3, 3, 0);
  m_grid.attach_next_to(m_btn4, m_btn1, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btn5, m_btn2, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btn6, m_btn3, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btn7, m_btn4, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btn8, m_btn5, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btn9, m_btn6, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btnClear, m_btn7, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btn0, m_btn8, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btnEqual, m_btn9, Gtk::PositionType::BOTTOM);
  m_grid.attach_next_to(m_btnMultiply, m_btn3, Gtk::PositionType::RIGHT);
  m_grid.attach_next_to(m_btnMinus, m_btn6, Gtk::PositionType::RIGHT);
  m_grid.attach_next_to(m_btnPlus, m_btn9, Gtk::PositionType::RIGHT);
  m_grid.attach_next_to(m_btnDivide, m_btnPlus, Gtk::PositionType::BOTTOM);

  set_child(m_grid);
}

CalcWindow::~CalcWindow() {}

void CalcWindow::on_btn1_click() {
  x += "1";
  m_text.set_text(x);
}
void CalcWindow::on_btn2_click() {
  x += "2";
  m_text.set_text(x);
}
void CalcWindow::on_btn3_click() {
  x += "3";
  m_text.set_text(x);
}
void CalcWindow::on_btn4_click() {
  x += "4";
  m_text.set_text(x);
}
void CalcWindow::on_btn5_click() {
  x += "5";
  m_text.set_text(x);
}
void CalcWindow::on_btn6_click() {
  x += "6";
  m_text.set_text(x);
}
void CalcWindow::on_btn7_click() {
  x += "7";
  m_text.set_text(x);
}
void CalcWindow::on_btn8_click() {
  x += "8";
  m_text.set_text(x);
}
void CalcWindow::on_btn9_click() {
  x += "9";
  m_text.set_text(x);
}
void CalcWindow::on_btn0_click() {
  x += "0";
  m_text.set_text(x);
}

void CalcWindow::on_btnPlus_click() {
  op = '+';
  opc = '+';
  m_text.set_text(op);
  y = x;
  x = "";
}
void CalcWindow::on_btnMinus_click() {
  op = '-';
  opc = '-';
  m_text.set_text(op);
  y = x;
  x = "";
}
void CalcWindow::on_btnMultiply_click() {
  op = '*';
  opc = '*';
  m_text.set_text(op);
  y = x;
  x = "";
}

void CalcWindow::on_btnDivide_click() {
  op = '/';
  opc = '/';
  m_text.set_text(op);
  y = x;
  x = "";
}

void CalcWindow::on_btnClear_click() {
  x = "", y = "";
  op = ' ';
  m_text.set_text("");
}
void CalcWindow::on_btnEqual_click() {
  switch (opc) {
  case '+':
    strx = strtof(x.c_str(), NULL);
    stry = strtof(y.c_str(), NULL);
    z = stry + strx;
    m_text.set_text(std::to_string(z));
    x = std::to_string(z);
    break;
  case '-':
    strx = strtof(x.c_str(), NULL);
    stry = strtof(y.c_str(), NULL);
    z = stry - strx;
    m_text.set_text(std::to_string(z));
    x = std::to_string(z);
    break;
  case '*':
    strx = strtof(x.c_str(), NULL);
    stry = strtof(y.c_str(), NULL);
    z = stry * strx;
    m_text.set_text(std::to_string(z));
    x = std::to_string(z);
    break;
  case '/':
    strx = strtof(x.c_str(), NULL);
    stry = strtof(y.c_str(), NULL);
    z = stry / strx;
    m_text.set_text(std::to_string(z));
    x = std::to_string(z);
    break;
  default:
    m_text.set_text("ERROR");
    break;
  }
}
