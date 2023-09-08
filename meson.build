project(
    'conjugateur', 
    'cpp',
    default_options: [ 'cpp_std=c++17' ],
    license: 'GPL-3.0-or-later',
    license_files: 'LICENSE',
    version: 'dev-1.0.0-alpha'
)

incdir = include_directories([ 'include' ])

srcs = [
    'src/conjugateur.cpp',
    'src/main.cpp',
    'src/mainframe.cpp',
    'src/quizitem.cpp',
    'src/toppanel.cpp',
    'src/verb.db.cpp'
]

wx = dependency('wxwidgets')

deps = [ wx ]

executable(
    'conjugateur',
    srcs,
    dependencies: deps,
    include_directories: incdir
)
