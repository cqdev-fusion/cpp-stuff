#pragma once
#include <gdkmm.h>
#include <gtkmm.h>

class GridExample : public Gtk::Window {
public:
  GridExample();
  ~GridExample();

protected:
  class ModelColumns;

  void onBtnQuit();
  void onItemActivated(unsigned int position);
  void onSelectionChanged();
  void onSetupListItem(const Glib::RefPtr<Gtk::ListItem> &listItem);
  void onBindListItem(const Glib::RefPtr<Gtk::ListItem> &listItem);

  int onModelSort(const Glib::RefPtr<const ModelColumns> &,
                  const Glib::RefPtr<const ModelColumns> &b);

  void addEntry(const std::string &filename, const Glib::ustring &description);

  // A Gio::ListStore stores filename, description and texture
  class ModelColumns : public Glib::Object {
  public:
    std::string m_fileName;
    Glib::ustring m_description;
    Glib::RefPtr<Gdk::Texture> m_texture;

    static Glib::RefPtr<ModelColumns>
    create(const std::string &filename, const Glib::ustring &description,
           const Glib::RefPtr<Gdk::Texture> &texture) {
      return Glib::make_refptr_for_instance<ModelColumns>(
          new ModelColumns(filename, description, texture));
    }

  protected:
    ModelColumns(const std::string &filename, const Glib::ustring &description,
                 const Glib::RefPtr<Gdk::Texture> &texture)
        : m_fileName(filename), m_description(description), m_texture(texture) {
    }
  };
  // Model Columns
  Glib::RefPtr<Gio::ListStore<ModelColumns>> m_dataModel;
  Glib::RefPtr<Gtk::SingleSelection> m_selectionModel;
  Glib::RefPtr<Gtk::SignalListItemFactory> m_factory;

  // Child Widgets
  Gtk::Box m_mainBox;
  Gtk::ScrolledWindow m_scrolledWindow;
  Gtk::GridView m_gridView;
  Gtk::Box m_btnBox;
  Gtk::Button m_btnQuit;
};
