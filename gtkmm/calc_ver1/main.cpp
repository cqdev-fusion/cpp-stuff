#include "calculator.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.app.org");
  return app->make_window_and_run<CalcWindow>(argc, argv);
}
