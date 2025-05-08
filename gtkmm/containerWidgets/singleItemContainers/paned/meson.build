project('Paned Widget', 'cpp',
  version: '1.0.0',
  default_options: [
    'cpp_std=c++23',
    'warning_level=3',
    'debug=true',
    ],
  meson_version: '1.8.0',
  )
src=[
  'main.cpp',
  'exampleWindow.cpp',
  'exampleWindow.hpp',
  'messageList.cpp',
  'messageList.hpp',
  'messageText.cpp',
  'messageText.hpp'
  ]
gtkdeps = dependency('gtkmm-4.0')
executable('demo', src, dependencies: gtkdeps)
