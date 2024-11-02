project(
  'Hello World',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++26', 'warning_level=3', 'debug=true'],
  meson_version: '1.6.0',
)
src = ['main.cpp', 'helloworld.cpp', 'helloworld.hpp']
gtk_deps = dependency('gtkmm-4.0')
executable('demo', src, dependencies: gtk_deps)
