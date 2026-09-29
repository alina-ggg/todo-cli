cmake_minimum_required(VERSION 3.16)

project(TodoList 
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(todo main.cpp ${SOURCES})

if(MSVC)
    target_compile_options(todo PRIVATE /W4)
else()
    target_compile_options(todo PRIVATE -Wall -Wextra -Wpedantic)
endif()
