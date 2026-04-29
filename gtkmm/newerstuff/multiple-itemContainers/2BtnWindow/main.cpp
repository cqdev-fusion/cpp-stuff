#include "hellogtkmm.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("app.exe.app");
  return app->make_window_and_run<Hellogtkmm>(argc, argv);
}
