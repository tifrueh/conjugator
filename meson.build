# Define the project.
project(
    'conjugator', 
    'cpp',
    default_options: [ 'cpp_std=c++17' ],
    license: 'GPL-3.0-or-later',
    license_files: 'LICENSE.md',
    version: '1.0.3-git'
)

# Try to get version string from git or use project version if that fails.
git_describe = run_command('git', 'describe', '--tags', check: false)
git_describe_out = git_describe.stdout().strip()

version = meson.project_version()

if git_describe_out != ''
  version = git_describe_out.substring(1)
endif

# Specify the include directories.
incdir = include_directories([ 'include' , 'configuration-files' ])

# Initialise a list of files which will hold all source files.
srcs = files()

# Initialise a environment for later use with custom targets.
env = environment()

# Initialise a configuration data object.
conf_data = configuration_data()

# Set configuration variables.
conf_data.set(
  'version', version
)
conf_data.set(
  'tag', 'v' + version
)
conf_data.set(
  'project_source_root', meson.project_source_root()
)
conf_data.set(
  'resources_dir', meson.project_source_root() + '/resources'
)
conf_data.set(
  'config_filename', 'conjugator.conf'
)

# Define the wxWidgets dependency depending on the 'static_wxwidgets' option.
if get_option('static_wxwidgets') == 'auto'
  wx = dependency('wxwidgets')
elif get_option('static_wxwidgets') == 'enabled'
  wx = dependency('wxwidgets', modules: '--static')
endif

# Configuration only needed on macOS.
if host_machine.system() == 'darwin'
  
  # Add the necessary compiler arguments and env variables depending on the
  # 'macos_min' option.
  env.set('MACOSX_DEPLOYMENT_TARGET', get_option('macos_min'))
  macos_min_arg = '-mmacosx-version-min=@0@'
  add_global_arguments(macos_min_arg.format(get_option('macos_min')), language: 'cpp')
  add_global_link_arguments(macos_min_arg.format(get_option('macos_min')), language: 'cpp')

  # Add the necessary compiler arguments and configuration variables depending
  # on the 'macos_universal' option.
  if get_option('macos_universal') == 'true'
    add_project_arguments('-arch', 'x86_64', '-arch', 'arm64', language: 'cpp')
    add_project_link_arguments('-arch', 'x86_64', '-arch', 'arm64', language: 'cpp')
    conf_data.set(
      'mac_bundle_version', conf_data.get('version') + '-universal'
    )
  else
    conf_data.set(
      'mac_bundle_version', conf_data.get('version') + '-' + host_machine.cpu()
    )
  endif

  # Set a different configuration filename
  conf_data.set(
    'config_filename', 'ch.tifrueh.conjugator.conf'
  )

# Configuration only needed on Windows.
elif host_machine.system() == 'windows' 
  
  # Initialise variable to hold the necessary resource compiler arguments for
  # wxWidgets.
  raw_wx_windres_args = wx.get_variable(configtool: 'rescomp').split()

  wx_windres_args = []

  foreach a : raw_wx_windres_args
    if a != 'windres'
      wx_windres_args += a
    endif
  endforeach

  windows = import('windows')

  # Configure the windows resource compiler.
  resources = windows.compile_resources(
    meson.current_build_dir() + '/configuration-files/resources.rc',
    args: wx_windres_args,
    depend_files: [ meson.project_source_root() + '/resources/conjugator.ico', 
      meson.project_source_root() + '/resources/inspecteur.ico' ]
  )

  srcs += resources

# Configuration only needed on Linux.
elif host_machine.system() == 'linux'
  install_data('resources/conjugator.png', install_dir : 'share/icons/hicolor/512x512/apps/')
  install_data('resources/conjugator.desktop', install_dir : 'share/applications/')

endif

# Execute meson.build in the 'configuration-files' subdir.
subdir('configuration-files')

# Execute meson.build in  the 'src' subdir.
subdir('src')

# Put wxWidgets in the dependency list.
deps = [ wx ]

# Handle i18n in the 'po' subdir.
subdir('po')

## Install the logo as svg.
install_data('resources/conjugator.svg')

# Configure the main executable.
conjugator = executable(
    'conjugator',
    srcs,
    dependencies: deps,
    include_directories: incdir,
    win_subsystem: 'windows',
    install: true
)

# MacOS-exclusive custom targets (see scripts/).
if host_machine.system() == 'darwin'
  run_target(
      'bundle_mac',
      command: 'scripts/bundle_mac.sh',
      depends: [ conjugator, gettext_return[0] ],
      env: env
  )

  run_target(
      'package_mac',
      command: [ 
        'scripts/package_mac.sh', conf_data.get('version')],
      depends: [ conjugator, gettext_return[0] ],
      env: env
  )

  run_target(
      'dmg_mac',
      command: [ 
        'scripts/dmg_mac.sh', conf_data.get('version')],
      depends: [ conjugator, gettext_return[0] ],
      env: env
  )
endif

# Windows-exclusive custom targets (see scripts/).
if host_machine.system() == 'windows'
  run_target(
      'package_win',
      command: 'scripts/package_win.sh',
      depends: [ conjugator, gettext_return[0] ],
      env: env
  )
endif
