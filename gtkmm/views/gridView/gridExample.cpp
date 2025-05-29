#include "gdkmm/pixbuf.h"
#include "giomm/liststore.h"
#include "glibmm/fileutils.h"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "gtkmm/label.h"
#include "gtkmm/listitem.h"
#include "gtkmm/object.h"
#include "gtkmm/signallistitemfactory.h"
#include "gtkmm/singleselection.h"
#include "sigc++/functors/mem_fun.h"
#include <array>
#include <gridExample.hpp>
#include <iostream>
#include <memory>

namespace {
struct GridEntry {
  std::string m_fileName;
  Glib::ustring m_description;
};
std::array<GridEntry, 8> entries = {
    GridEntry{"/home/fusion/development/cpp-stuff/gtkmm/views/gridView/images/"
              "GridViews/mozilla-firefox.png",
              "<b>Mozilla Firefox</b> Logo"},
    GridEntry{"/home/fusion/development/cpp-stuff/gtkmm/views/gridView/images/"
              "GridViews/xmms.xpm",
              "<b>XMMS</b> Logo"},
    GridEntry{"/home/fusion/development/cpp-stuff/gtkmm/views/gridView/images/"
              "GridViews/gnome-dice-1.svg",
              "<b> Gnome Dice 1</b> Logo"},
    GridEntry{"/home/fusion/development/cpp-stuff/gtkmm/views/gridView/images/"
              "GridViews/gnome-dice-2.svg",
              "<b> Gnome Dice 2</b> Logo"},
    GridEntry{"/home/fusion/development/cpp-stuff/gtkmm/views/gridView/images/"
              "GridViews/gnome-dice-3.svg",
              "<b> Gnome Dice 3</b> Logo"},
    GridEntry{"/home/fusion/development/cpp-stuff/gtkmm/views/gridView/images/"
              "GridViews/gnome-dice-4.svg",
              "<b> Gnome Dice 4</b> Logo"},
    GridEntry{"/home/fusion/development/cpp-stuff/gtkmm/views/gridView/images/"
              "GridViews/gnome-dice-5.svg",
              "<b> Gnome Dice 5</b> Logo"},
    GridEntry{"/home/fusion/development/cpp-stuff/gtkmm/views/gridView/images/"
              "GridViews/gnome-dice-6.svg",
              "<b> Gnome Dice 6</b> Logo"}

};
} // namespace

GridExample::GridExample()
    : m_mainBox(Gtk::Orientation::VERTICAL), m_btnQuit("Quit") {
  set_title("Gtk::GridView (Gio::ListStore) example");
  set_default_size(800, 600);

  m_mainBox.set_margin(10);
  set_child(m_mainBox);

  // Add the gridview inside a scrolled window with a button underit.
  m_scrolledWindow.set_child(m_gridView);
  m_scrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC,
                              Gtk::PolicyType::AUTOMATIC);
  m_scrolledWindow.set_expand();

  m_mainBox.append(m_scrolledWindow);
  m_mainBox.append(m_btnBox);

  m_btnBox.append(m_btnQuit);
  m_btnBox.set_margin(10);

  m_btnQuit.set_hexpand(true);
  m_btnQuit.set_halign(Gtk::Align::END);
  m_btnQuit.signal_clicked().connect(
      sigc::mem_fun(*this, &GridExample::onBtnQuit));

  // Create the Data Model
  m_dataModel = Gio::ListStore<ModelColumns>::create();
  m_selectionModel = Gtk::SingleSelection::create(m_dataModel);
  m_selectionModel->set_autoselect(false);

  // create the factory
  m_factory = Gtk::SignalListItemFactory::create();
  m_factory->signal_setup().connect(
      sigc::mem_fun(*this, &GridExample::onSetupListItem));
  m_factory->signal_bind().connect(
      sigc::mem_fun(*this, &GridExample::onBindListItem));

  // Fill the Gio::ListStore's data model and sort it.
  for (const auto &entry : entries)
    addEntry(entry.m_fileName, entry.m_description);
  m_dataModel->sort(sigc::mem_fun(*this, &GridExample::onModelSort));

  m_gridView.set_model(m_selectionModel);
  m_gridView.set_factory(m_factory);
  m_gridView.signal_activate().connect(
      sigc::mem_fun(*this, &GridExample::onItemActivated));

  m_selectionModel->property_selected().signal_changed().connect(
      sigc::mem_fun(*this, &GridExample::onSelectionChanged));
}

GridExample::~GridExample() {}

void GridExample::onBtnQuit() { set_visible(false); }

void GridExample::onSetupListItem(const Glib::RefPtr<Gtk::ListItem> &listItem) {

  // Each list item contains a verticle box with an image and a label.
  auto vBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);
  auto picture = Gtk::make_managed<Gtk::Picture>();
  picture->set_can_shrink(false);
  picture->set_halign(Gtk::Align::CENTER);
  picture->set_valign(Gtk::Align::END);
  vBox->append(*picture);
  vBox->append(*Gtk::make_managed<Gtk::Label>());
  listItem->set_child(*vBox);
}

void GridExample::onBindListItem(const Glib::RefPtr<Gtk::ListItem> &listItem) {
  auto col = std::dynamic_pointer_cast<ModelColumns>(listItem->get_item());
  if (!col)
    return;
  auto vBox = dynamic_cast<Gtk::Box *>(listItem->get_child());
  if (!vBox)
    return;
  auto picture = dynamic_cast<Gtk::Picture *>(vBox->get_first_child());
  if (!picture)
    return;
  auto label = dynamic_cast<Gtk::Label *>(picture->get_next_sibling());
  if (!label)
    return;
  picture->set_paintable(col->m_texture);
  label->set_markup(col->m_description);
}

void GridExample::onItemActivated(unsigned int position) {
  auto col = m_dataModel->get_item(position);
  if (!col)
    return;

  const std::string filename = col->m_fileName;
  const Glib::ustring description = col->m_description;

  std::cout << "Item activated: filename= " << filename
            << ", description= " << std::endl;
}

void GridExample::onSelectionChanged() {
  auto position = m_selectionModel->get_selected();
  auto col = m_dataModel->get_item(position);
  if (!col)
    return;

  const std::string fileName = col->m_fileName;
  const Glib::ustring description = col->m_description;

  std::cout << "Selection changed to: filename= " << fileName
            << ", description= " << description << std::endl;
}

int GridExample::onModelSort(const Glib::RefPtr<const ModelColumns> &a,
                             const Glib::RefPtr<const ModelColumns> &b) {
  return (a->m_description < b->m_description)
             ? -1
             : ((a->m_description > b->m_description) ? 1 : 0);
}

void GridExample::addEntry(const std::string &filename,
                           const Glib::ustring &description) {
  try {
    auto pixbuf = Gdk::Pixbuf::create_from_file(filename);
    auto texture = Gdk::Texture::create_for_pixbuf(pixbuf);
    m_dataModel->append(ModelColumns::create(filename, description, texture));
  } catch (const Gdk::PixbufError &ex) {
    std::cerr << "Gdk::PixbufError: " << ex.what() << std::endl;
  } catch (const Glib::FileError &ex) {
    std::cerr << "Glib::FileError: " << ex.what() << std::endl;
  }
}
