project(
  'Pixmap',
  'cpp',
  version: '1.0.0',
  default_options: [
    'cpp_std=c++23',
    'warning_level=3',
    'debug=true',
  ],
  meson_version: '1.6.1',
)
src = ['main.cpp', 'buttons.cpp', 'buttons.hpp']
gtkdeps = dependency('gtkmm-4.0')
executable('demo', src, dependencies: gtkdeps)
