#include "viewExample.hpp"
#include "gtk/gtkshortcut.h"
#include <gtkmm.h>

ViewWindow::ViewWindow()
    : m_mainBox(Gtk::Orientation::VERTICAL),
      m_headingLabel("<b>Name </b>", Gtk::Align::START), m_btnQuit("Quit") {

  const int SCREEN_WIDTH{300};
  const int SCREEN_HEIGHT{200};

  set_title("Gtk::ListView (Gtk::StringList) example");
  set_default_size(SCREEN_WIDTH, SCREEN_HEIGHT);
  set_child(m_mainBox);

  m_headingLabel.set_use_markup();
  m_mainBox.append(m_headingLabel);
  m_scrolledWindow.set_child(m_listView);

  m_scrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC,
                              Gtk::PolicyType::AUTOMATIC);
  m_scrolledWindow.set_expand();

  m_mainBox.append(m_scrolledWindow);
  m_mainBox.append(m_btnBox);

  m_btnBox.append(m_btnQuit);
  m_btnBox.set_margin(5);

  m_btnQuit.set_hexpand(true);
  m_btnQuit.set_halign(Gtk::Align::END);
  m_btnQuit.signal_clicked().connect(
      sigc::mem_fun(*this, &ViewWindow::onBtnQuit));

  m_stringList = Gtk::StringList::create({"John Doe", "Jack Doe", "Kim Joe"});

  auto selectionModel = Gtk::SingleSelection::create(m_stringList);
  selectionModel->set_autoselect(false);
  selectionModel->set_can_unselect(true);
  m_listView.set_model(selectionModel);
  m_listView.add_css_class("data-table");

  auto factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(
      sigc::mem_fun(*this, &ViewWindow::onSetupLabel));
  factory->signal_bind().connect(sigc::mem_fun(*this, &ViewWindow::onBindName));
  m_listView.set_factory(factory);
}

ViewWindow::~ViewWindow() {}

void ViewWindow::onBtnQuit() { set_visible(false); }

void ViewWindow::onSetupLabel(const Glib::RefPtr<Gtk::ListItem> &listItem) {
  listItem->set_child(*Gtk::make_managed<Gtk::Label>("", Gtk::Align::START));
}

void ViewWindow::onBindName(const Glib::RefPtr<Gtk::ListItem> &listItem) {
  auto pos = listItem->get_position();
  if (pos == GTK_INVALID_LIST_POSITION)
    return;
  auto label = dynamic_cast<Gtk::Label *>(listItem->get_child());
  if (!label)
    return;
  label->set_text(m_stringList->get_string(pos));
}
