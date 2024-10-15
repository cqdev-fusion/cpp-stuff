#include "basicWindow.hpp"

const int SCREEN_WIDTH{800};
const int SCREEN_HEIGHT{600};

BasicWindow::BasicWindow() {
  set_title("A Basic Window");
  set_default_size(SCREEN_WIDTH, SCREEN_HEIGHT);
}

BasicWindow::~BasicWindow() {}
