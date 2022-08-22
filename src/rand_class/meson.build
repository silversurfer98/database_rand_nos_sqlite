subdir('power_func')
subdir('trig_func')

inc1 = include_directories('power_func')
inc2 = include_directories('trig_func')

src = ['rand.h', 'rand_class.cpp', 'gen_rand_driver.cpp']
rand = static_library('rand', src, link_with:[power, trig], include_directories: [inc1, inc2])