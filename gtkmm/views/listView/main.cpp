#include "viewExample.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.app.app");
  return app->make_window_and_run<ViewWindow>(argc, argv);
}
