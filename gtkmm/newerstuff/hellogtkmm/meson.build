project(
  'Hello GTKMM',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++26', 'warning_level=3', 'debug=true'],
  meson_version: '1.11.1',
)
deps = dependency('gtkmm-4.0')
src = ['main.cpp', 'hellogtkmm.cpp', 'hellogtkmm.hpp']
executable('demo', src, dependencies: deps)
