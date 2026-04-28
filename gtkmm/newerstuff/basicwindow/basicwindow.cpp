#include "basicwindow.hpp"

BasicWindow::BasicWindow() {

  static int WINDOW_WIDTH{800};
  static int WINDOW_HEIGHT{600};

  set_title("Basic Window");
  set_default_size(WINDOW_WIDTH, WINDOW_HEIGHT);
}

BasicWindow::~BasicWindow() {}
