project(
    'conjugateur', 
    'cpp',
    default_options: [ 'cpp_std=c++17' ],
    version: 'dev'
)

incdir = include_directories([ 'include' ])

srcs = [
    'src/main.cpp',
    'src/verb.db.cpp',
    'src/conjugateur.cpp'
]

executable(
    'conjugateur',
    srcs,
    include_directories: incdir
)
