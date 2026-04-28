project(
  'Basic Window',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++26', 'warning_level=3', 'debug=true'],
  meson_version: '1.11.1',
)

deps = dependency('gtkmm-4.0')
src_file = executable('demo', 'main.cpp', 'basicwindow.cpp', 'basicwindow.hpp', dependencies: deps)
