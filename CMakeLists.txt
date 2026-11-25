cmake_minimum_required(VERSION 3.20)
project(Lab11)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

foreach(target_name zavd1 zavd2 zavd3 zavd4 zavd5 zavd6)
    add_executable(${target_name} src/${target_name}.cpp)
    if(MSVC)
        target_compile_options(${target_name} PRIVATE /W4 /permissive-)
    endif()
endforeach()