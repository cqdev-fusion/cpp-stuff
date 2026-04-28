#include "exampleFrame.hpp"
#include "gtkmm/enums.h"

SingleFrameExample::SingleFrameExample() {
  const int WINDOW_WIDTH{800};
  const int WINDOW_HEIGHT{600};

  set_title("GTK::Frame");
  set_size_request(WINDOW_WIDTH, WINDOW_HEIGHT);

  m_frame.set_margin(10);
  set_child(m_frame);

  // Set the lable for the frame.
  m_frame.set_label("GTK::Frame::Widget");
  m_frame.set_label_align(Gtk::Align::CENTER);
}

SingleFrameExample::~SingleFrameExample(){}
