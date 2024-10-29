project(
  'Toggle Button Widget',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++23', 'warning_level=3', 'debug=true'],
  meson_version: '1.4.1',
)
src = ['main.cpp', 'checkBtn.cpp', 'checkBtn.hpp']
gtkmm_deps = dependency('gtkmm-4.0')
executable('demo', src, dependencies: gtkmm_deps)
