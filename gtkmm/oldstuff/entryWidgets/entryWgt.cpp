#include "entryWgt.hpp"

EntryWidget::EntryWidget()
    : m_VBox(Gtk::Orientation::VERTICAL), m_btn_close("Close"),
      m_cb_editable("Editable"), m_cb_visible("Visable") {
  set_size_request(200, 200);
  set_title("Gtk::Entry");
  set_child(m_VBox);

  m_entry.set_max_length(50);
  m_entry.set_text("Howdy");
  m_entry.set_text(m_entry.get_text() + "partner");
  m_entry.select_region(0, m_entry.get_text_length());
  m_entry.set_expand(true);
  m_VBox.append(m_entry);

  m_VBox.append(m_HBox);

  m_HBox.append(m_cb_editable);
  m_cb_editable.set_expand(true);
  m_cb_editable.signal_toggled().connect(
      sigc::mem_fun(*this, &EntryWidget::on_cb_editable_toggled));
  m_cb_editable.set_active(true);

  m_HBox.append(m_cb_visible);
  m_cb_visible.set_expand(true);
  m_cb_visible.signal_toggled().connect(
      sigc::mem_fun(*this, &EntryWidget::on_cb_visibility_toggled));
  m_cb_visible.set_active(true);

  m_btn_close.signal_clicked().connect(
      sigc::mem_fun(*this, &EntryWidget::on_btn_close));
  m_VBox.append(m_btn_close);
  m_btn_close.set_expand();
  set_default_widget(m_btn_close);
}

EntryWidget::~EntryWidget() {}

void EntryWidget::on_cb_editable_toggled() {
  m_entry.set_editable(m_cb_editable.get_active());
}

void EntryWidget::on_cb_visibility_toggled() {
  m_entry.set_visibility(m_cb_visible.get_active());
}
void EntryWidget::on_btn_close() { set_visible(false); }
