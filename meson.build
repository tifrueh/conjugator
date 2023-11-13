project(
    'conjugateur', 
    'cpp',
    default_options: [ 'cpp_std=c++17' ],
    license: 'GPL-3.0-or-later',
    license_files: 'LICENSE.txt',
    version: 'v1.0.0-beta-3'
)

incdir = include_directories([ 'include' ])

srcs = files()

subdir('src')

wx = dependency('wxwidgets')

deps = [ wx ]

if build_machine.system() == 'windows' 

  raw_wx_windres_args = wx.get_variable(configtool: 'rescomp').split()

  wx_windres_args = []

  foreach a : raw_wx_windres_args
    if a != 'windres'
      wx_windres_args += a
    endif
  endforeach

  windows = import('windows')

  srcs += windows.compile_resources(
    'resources/resources.rc',
    args: wx_windres_args,
    depend_files: [ 'resources/conjugateur.ico' ]) 

endif

install_data('resources/conjugateur.png')
install_data('resources/conjugateur.desktop')

conjugateur = executable(
    'conjugateur',
    srcs,
    dependencies: deps,
    include_directories: incdir,
    win_subsystem: 'windows',
    install: true
)

run_target(
    'bundle_mac',
    command: 'scripts/bundle_mac.sh',
    depends: [ conjugateur ]
)

run_target(
    'package_mac',
    command: [ 
      'scripts/package_mac.sh', meson.project_version().substring(1)],
    depends: [ conjugateur ]
)
