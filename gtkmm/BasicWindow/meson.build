project(
  'Basic Window',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++23', 'warning_level=3', 'debug=true'],
  meson_version: '1.5.2',
)
src = ['main.cpp', 'basicWindow.cpp', 'basicWindow.hpp']
deps = dependency('gtkmm-4.0')
executable('demo', src, dependencies: deps)
