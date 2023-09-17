project(
    'conjugateur', 
    'cpp',
    default_options: [ 'cpp_std=c++17' ],
    license: 'GPL-3.0-or-later',
    license_files: 'LICENSE',
    version: '1.0.0-dev'
)

incdir = include_directories([ 'include' ])

srcs = files()

subdir('src')

wx = dependency('wxwidgets')

deps = [ wx ]

executable(
    'conjugateur',
    srcs,
    dependencies: deps,
    include_directories: incdir
)

run_target(
    'bundleMacOS',
    command: 'dist/macOS/bundle.sh'
)