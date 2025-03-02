#include "mainWindow.hpp"

const int SCREEN_WIDTH{800};
const int SCREEN_HEIGHT{600};

MainWindow::MainWindow() {
  set_title("Main Window");
  set_default_size(SCREEN_WIDTH, SCREEN_HEIGHT);
}

MainWindow::~MainWindow() {}
