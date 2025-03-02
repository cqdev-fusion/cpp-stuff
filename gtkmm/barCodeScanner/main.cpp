#include "mainWindow.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.app.barcodeScanner");

  return app->make_window_and_run<MainWindow>(argc, argv);
}
