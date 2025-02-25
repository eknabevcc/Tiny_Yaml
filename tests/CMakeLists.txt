# in a bash terminal from Tiny_Yaml/tests folder:
#   cmake -B build
#   cmake --build build

cmake_minimum_required(VERSION 3.15)

project(test)

set(TARGET test)

file(GLOB tests
     "*.hpp"
)

add_executable(${TARGET} main.cpp ../yaml/yaml.cpp ../yaml/yaml.hpp ${tests})
