#include "messageList.hpp"
#include "glibmm/refptr.h"
#include "glibmm/ustring.h"
#include "gtkmm/enums.h"
#include "gtkmm/listitem.h"
#include "gtkmm/signallistitemfactory.h"
#include "gtkmm/singleselection.h"
#include "gtkmm/stringlist.h"
#include <gtkmm/label.h>
#include "sigc++/functors/mem_fun.h"

MessageList::MessageList(){
  set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  set_child(m_listView);

  m_refStringList = Gtk::StringList::create({});
  auto selection_model = Gtk::SingleSelection::create(m_refStringList);
  m_listView.set_model(selection_model);

  for (int i = 1; i <= 10; i++) {
  m_refStringList->append(Glib::ustring::format("message #", i));

    auto factory = Gtk::SignalListItemFactory::create();
    factory->signal_setup().connect(sigc::mem_fun(*this, &MessageList::on_setup_message));
    factory->signal_bind().connect(sigc::mem_fun(*this, &MessageList::on_bind_message));
    m_listView.set_factory(factory);
  }
}

MessageList::~MessageList(){}

void MessageList::on_setup_message(const Glib::RefPtr<Gtk::ListItem>& list_item){
  auto label = Gtk::make_managed<Gtk::Label>();
  label->set_halign(Gtk::Align::START);
  list_item->set_child(*label);
}

void MessageList::on_bind_message(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
  auto pos = list_item->get_position();
  if (pos == GTK_INVALID_LIST_POSITION)
    return;
  auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
  if (!label)
    return;
  label->set_text(m_refStringList->get_string(pos));
}
