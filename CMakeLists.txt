project(Spectral_Defense)
set(EXECUTABLE_OUTPUT_PATH bin/)
cmake_minimum_required( VERSION 2.8)
add_definitions(-std=c++11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML2 REQUIRED sfml-graphics>=2.1)


file(
GLOB_RECURSE

src_file 

src/*.cpp
include/*.hpp
)

include_directories(
include
)

add_executable(

Spectral_Defense

${src_file}
)

target_link_libraries(

Spectral_Defense

sfml-graphics
sfml-window
sfml-system
)
