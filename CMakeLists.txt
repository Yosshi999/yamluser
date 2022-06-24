cmake_minimum_required(VERSION 3.12)

project(mainProject)

add_executable(main src/main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 17)
target_compile_options(main PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>: /W4 /utf-8>
    $<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
)

add_subdirectory(external/yaml-cpp)
target_link_libraries(main yaml-cpp)