project(
    'conjugateur', 
    'cpp',
    default_options: [ 'cpp_std=c++17' ],
    license: 'GPL-3.0-or-later',
    license_files: 'LICENSE',
    version: 'dev'
)

incdir = include_directories([ 'include' ])

srcs = [
    'src/conjugateur.cpp'
    'src/main.cpp',
    'src/verb.db.cpp',
]

wx = dependency('wxwidgets')

deps = [ wx ]

executable(
    'conjugateur',
    srcs,
    dependencies: deps,
    include_directories: incdir
)
