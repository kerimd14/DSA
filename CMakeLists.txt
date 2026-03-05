cmake_minimum_required(VERSION 3.16)

project(DSA LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dsa_app
    main.cpp
    datastruct/dynarray/dynarray.cpp
    datastruct/dynarray/dynarray_tests.cpp
    datastruct/stack/stack.cpp
    datastruct/stack/stack_tests.cpp
)

target_include_directories(dsa_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/datastruct
    ${CMAKE_CURRENT_SOURCE_DIR}/datastruct/dynarray
    ${CMAKE_CURRENT_SOURCE_DIR}/datastruct/stack
)
