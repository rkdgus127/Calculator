cmake_minimum_required(VERSION 3.20)
project(Calculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

add_executable(Calculator main.cpp)

target_link_libraries(Calculator PRIVATE OpenMP::OpenMP_CXX)

if(MSVC)
    target_compile_options(Calculator PRIVATE /O2)
else()
    target_compile_options(Calculator PRIVATE -O3 -march=native)
endif()