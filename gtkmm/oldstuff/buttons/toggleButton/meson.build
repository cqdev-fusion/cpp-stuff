project(
  'Toggle Widgets',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++23', 'warning_level=3', 'debug=true'],
  meson_version: '1.6.0',
)
src = ['main.cpp', 'toggleWidget.cpp', 'toggleWidget.hpp']
deps = dependency('gtkmm-4.0')
executable('demo', src, dependencies: deps)
