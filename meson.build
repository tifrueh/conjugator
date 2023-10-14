project(
    'conjugateur', 
    'cpp',
    default_options: [ 'cpp_std=c++17' ],
    license: 'GPL-3.0-or-later',
    license_files: 'LICENSE.txt',
    version: '1.0.0-beta'
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

bundle_mac = run_target(
    'bundle_mac',
    command: 'dist/macOS/bundle.sh',
    depends: [ conjugateur ]
)
