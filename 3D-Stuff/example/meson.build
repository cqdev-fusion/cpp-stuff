project(
  'Example Project',
  'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++23', 'warning_level=3', 'debug=true'],
  meson_version: '>=1.8.0',
)
src = ['main.cpp']
glfwdeps = dependency('glfw3')
glewdepd = dependency('glew')
executable('demo', src, dependencies: [glfwdeps, glewdepd])
