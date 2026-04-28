#include "buttons.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("app.org.app");
  return app->make_window_and_run<Buttons>(argc, argv);
}
