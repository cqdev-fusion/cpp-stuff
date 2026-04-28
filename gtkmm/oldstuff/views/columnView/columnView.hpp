#pragma once

#include "giomm/liststore.h"
#include "glibmm/object.h"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtkmm/listitem.h"
#include "gtkmm/scrolledwindow.h"
#include <gtkmm.h>

class ColumnView : public Gtk::Window {
public:
  ColumnView();
  ~ColumnView();

protected:
  // Signal handlers
  void onBtnQuit();
  void onSetupLabel(const Glib::RefPtr<Gtk::ListItem> &listItem,
                    Gtk::Align halign);
  void onSetupProgressBar(const Glib::RefPtr<Gtk::ListItem> &listItem);
  void onBindId(const Glib::RefPtr<Gtk::ListItem> &listItem);
  void onBindName(const Glib::RefPtr<Gtk::ListItem> &listItem);
  void onBindnumber(const Glib::RefPtr<Gtk::ListItem> &listItem);
  void onBindPercentage(const Glib::RefPtr<Gtk::ListItem> &listItem);

  // A Gio::ListStore item
  class ModelColumns : public Glib::Object {
  public:
    unsigned int m_colID;
    Glib::ustring m_colName;
    short m_colNumber;
    int m_colPercentage;

    static Glib::RefPtr<ModelColumns> create(unsigned int colID,
                                             const Glib::ustring colName,
                                             short colNumber,
                                             int colPercentage) {
      return Glib::make_refptr_for_instance<ModelColumns>(
          new ModelColumns(colID, colName, colNumber, colPercentage));
    }

  protected:
    ModelColumns(unsigned int colID, const Glib::ustring &colName,
                 short colNumber, int colPercentage)
        : m_colID(colID), m_colName(colName), m_colNumber(colNumber),
          m_colPercentage(colPercentage) {}
  };

  Gtk::Box m_mainBox;
  Gtk::ScrolledWindow m_scrolledWindow;
  Gtk::ColumnView m_columnView;
  Gtk::Box m_btnBox;
  Gtk::Button m_btnQuit;

  Glib::RefPtr<Gio::ListStore<ModelColumns>> m_listStore;
};
