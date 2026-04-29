project(
  '2 Button Window',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++26', 'warning_level=3', 'debug=true'],
  meson_version: '1.11.1',
)

src = ['main.cpp', 'hellogtkmm.cpp', 'hellogtkmm.hpp']
deps = dependency('gtkmm-4.0')
executable('demo', src, dependencies: deps)
