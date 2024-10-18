#include "helloworld.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("app.org.example");
  return app->make_window_and_run<HelloWorld>(argc, argv);
}
