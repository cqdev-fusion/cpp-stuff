#include "columnView.hpp"
#include "giomm/liststore.h"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtkmm/columnview.h"
#include "gtkmm/columnviewcolumn.h"
#include "gtkmm/enums.h"
#include "gtkmm/label.h"
#include "gtkmm/listitem.h"
#include "gtkmm/object.h"
#include "gtkmm/progressbar.h"
#include "gtkmm/signallistitemfactory.h"
#include "gtkmm/singleselection.h"
#include "sigc++/adaptors/bind.h"
#include "sigc++/functors/mem_fun.h"
#include <memory>

ColumnView::ColumnView()
    : m_mainBox(Gtk::Orientation::VERTICAL), m_btnQuit("Quit") {
  const int SCREEN_WIDTH{500};
  const int SCREEN_HEIGHT{250};
  set_title("Gtk::ColumnView (Gio::ListStore) Example");
  set_default_size(SCREEN_WIDTH, SCREEN_HEIGHT);

  m_mainBox.set_margin(10);
  set_child(m_mainBox);

  // Add the columnView inside a scrolled window with a button beneath
  m_scrolledWindow.set_child(m_columnView);

  // Only show scrollbars when needed
  m_scrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC,
                              Gtk::PolicyType::AUTOMATIC);
  m_scrolledWindow.set_expand();

  m_mainBox.append(m_scrolledWindow);
  m_mainBox.append(m_btnBox);

  m_btnBox.append(m_btnQuit);
  m_btnBox.set_margin(10);

  m_btnQuit.set_hexpand(true);
  m_btnQuit.set_valign(Gtk::Align::END);
  m_btnQuit.signal_clicked().connect(
      sigc::mem_fun(*this, &ColumnView::onBtnQuit));

  // Create the list model
  m_listStore = Gio::ListStore<ModelColumns>::create();
  m_listStore->append(ModelColumns::create(1, "John Doe", 10, 15));
  m_listStore->append(ModelColumns::create(1, "Kim Twinkle", 20, 40));
  m_listStore->append(ModelColumns::create(1, "Barry Knight", 30, 70));

  // Set the list model and selection model
  auto selectionModel = Gtk::SingleSelection::create(m_listStore);
  selectionModel->set_autoselect(false);
  selectionModel->set_can_unselect(true);
  m_columnView.set_model(selectionModel);
  m_columnView.add_css_class("data-table");
  m_columnView.set_reorderable(true);
  // m_columnView.set_model(selectionModel);
  // m_columnView.add_css_class("data-table");
  // m_columnView.set_reorderable(true);

  // Adding the Column views ModelColumns

  // // ID Column
  auto factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(sigc::bind(
      sigc::mem_fun(*this, &ColumnView::onSetupLabel), Gtk::Align::END));
  factory->signal_bind().connect(sigc::mem_fun(*this, &ColumnView::onBindName));

  auto column = Gtk::ColumnViewColumn::create("ID", factory);
  m_columnView.append_column(column);

  // // Name the Column
  factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(sigc::bind(
      sigc::mem_fun(*this, &ColumnView::onSetupLabel), Gtk::Align::END));
  factory->signal_bind().connect(
      sigc::mem_fun(*this, &ColumnView::onBindnumber));
  column = Gtk::ColumnViewColumn::create("Formatted Number", factory);
  m_columnView.append_column(column);

  // // Percentage Column
  factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(
      sigc::mem_fun(*this, &ColumnView::onSetupProgressBar));
  factory->signal_bind().connect(
      sigc::mem_fun(*this, &ColumnView::onBindPercentage));
  column = Gtk::ColumnViewColumn::create("Some Percentage", factory);
  m_columnView.append_column(column);
}

ColumnView::~ColumnView() {}

void ColumnView::onBtnQuit() { set_visible(false); }

void ColumnView::onSetupLabel(const Glib::RefPtr<Gtk::ListItem> &listItem,
                              Gtk::Align halign) {
  listItem->set_child(*Gtk::make_managed<Gtk::Label>("", halign));
}

void ColumnView::onSetupProgressBar(
    const Glib::RefPtr<Gtk::ListItem> &listItem) {
  auto progressBar = Gtk::make_managed<Gtk::ProgressBar>();
  progressBar->set_show_text(true);
  listItem->set_child(*progressBar);
}

void ColumnView::onBindId(const Glib::RefPtr<Gtk::ListItem> &listItem) {
  auto col = std::dynamic_pointer_cast<ModelColumns>(listItem->get_item());
  if (!col)
    return;

  auto label = dynamic_cast<Gtk::Label *>(listItem->get_child());
  if (!label)
    return;
  label->set_text(Glib::ustring::format(col->m_colID));
}

void ColumnView::onBindName(const Glib::RefPtr<Gtk::ListItem> &listItem) {
  auto col = std::dynamic_pointer_cast<ModelColumns>(listItem->get_item());
  if (!col)
    return;

  auto label = dynamic_cast<Gtk::Label *>(listItem->get_child());
  if (!label)
    return;
  label->set_text(col->m_colName);
}

void ColumnView::onBindnumber(const Glib::RefPtr<Gtk::ListItem> &listItem) {
  auto col = std::dynamic_pointer_cast<ModelColumns>(listItem->get_item());
  if (!col)
    return;

  auto label = dynamic_cast<Gtk::Label *>(listItem->get_child());
  if (!label)
    return;
  label->set_text(Glib::ustring::sprintf("%010d", col->m_colNumber));
}

void ColumnView::onBindPercentage(const Glib::RefPtr<Gtk::ListItem> &listItem) {
  auto col = std::dynamic_pointer_cast<ModelColumns>(listItem->get_item());
  if (!col)
    return;

  auto progressBar = dynamic_cast<Gtk::ProgressBar *>(listItem->get_child());
  if (!progressBar)
    return;
  progressBar->set_fraction(col->m_colPercentage * 0.01);
}
