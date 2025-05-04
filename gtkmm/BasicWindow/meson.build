project(
  'Basic Window',
  'cpp',
  version: '4.12.0',
  default_options: ['cpp_std=c++23', 'warning_level=3'],
  meson_version: '>=1.8.0',
)

src = ['main.cpp', 'basicWindow.cpp', 'basicWindow.hpp']
deps = dependency('gtkmm-4.0')
executable('demo', src, dependencies: deps)
