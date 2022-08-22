project('store_rand_no.', 'c', 'cpp', default_options: ['c_std=c11', 'cpp_std=c++17'])

subdir('rand_class')
subdir('sqlite_funcs')
inc = include_directories('rand_class')
inc1 = include_directories('sqlite_funcs')
src = ['main.cpp']
executable('out', src, link_with: [rand, sqlite], include_directories: [inc, inc1])