project(
    'conjugateur', 
    'cpp',
    default_options: [ 'cpp_std=c++17' ],
    license: 'GPL-3.0-or-later',
    license_files: 'LICENSE.md',
    version: 'v1.0.0-dev'
)

incdir = include_directories([ 'include' , 'configuration-files' ])

srcs = files()

env = environment()

subdir('src')

if get_option('static_wxwidgets') == 'auto'
  wx = dependency('wxwidgets')
elif get_option('static_wxwidgets') == 'enabled'
  wx = dependency('wxwidgets', modules: '--static')
endif

conf_data = configuration_data()
conf_data.set(
  'version', meson.project_version()
)
conf_data.set(
  'mac_version', meson.project_version().substring(1)
)
conf_data.set(
  'mac_bundle_version', conf_data.get('mac_version') + '-' + host_machine.system() + '-' + host_machine.cpu()
)
conf_data.set(
  'project_source_root', meson.project_source_root()
)
conf_data.set(
  'resources_dir', meson.project_source_root() + '/resources'
)

subdir('configuration-files')

deps = [ wx ]

if host_machine.system() == 'darwin'
  
  env.set('MACOSX_DEPLOYMENT_TARGET', get_option('macos_min'))
  macos_min_arg = '-mmacosx-version-min=@0@'
  add_global_arguments(macos_min_arg.format(get_option('macos_min')), language: 'cpp')
  add_global_link_arguments(macos_min_arg.format(get_option('macos_min')), language: 'cpp')

elif host_machine.system() == 'windows' 
  
  raw_wx_windres_args = wx.get_variable(configtool: 'rescomp').split()

  wx_windres_args = []

  foreach a : raw_wx_windres_args
    if a != 'windres'
      wx_windres_args += a
    endif
  endforeach

  windows = import('windows')

  resources = windows.compile_resources(
    meson.current_build_dir() + '/configuration-files/resources.rc',
    args: wx_windres_args,
    depend_files: [ meson.project_source_root() + '/resources/conjugateur.ico', 
      meson.project_source_root() + '/resources/inspecteur.ico' ]
  )

  srcs += resources
    
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

if host_machine.system() == 'darwin'
  run_target(
      'bundle_mac',
      command: 'scripts/bundle_mac.sh',
      depends: [ conjugateur ],
      env: env
  )

  run_target(
      'package_mac',
      command: [ 
        'scripts/package_mac.sh', conf_data.get('mac_version')],
      depends: [ conjugateur ],
      env: env
  )
endif
