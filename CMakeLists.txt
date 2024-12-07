cmake_minimum_required(VERSION 3.27)
project(PADHLS_lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(PADHLS_lab1 main.cpp)

find_package(OpenMP REQUIRED)
target_link_libraries(PADHLS_lab1 PRIVATE OpenMP::OpenMP_C)