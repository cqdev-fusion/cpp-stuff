#include "exampleFrame.hpp"
#include <gtkmm/application.h>

int main (int argc, char *argv[]) {
 auto app = Gtk::Application::create("org.app.example"); 
  return app->make_window_and_run<SingleFrameExample>(argc, argv);
}
