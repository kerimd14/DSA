cmake_minimum_required(VERSION 3.16)

project(DSA LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dsa_app
    main.cpp
    dynvec/dynvector.cpp
    dynvec/dynvector_tests.cpp
)

target_include_directories(dsa_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dynvec
)
