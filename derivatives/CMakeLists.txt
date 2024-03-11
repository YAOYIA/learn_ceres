cmake_minimum_required(VERSION 3.0)
project(diff)


find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

add_executable(numeric helloworld_numeric_diff.cpp)
add_executable(analytic helloworld_analytic_diff.cpp)

target_link_libraries(numeric ${CERES_LIBRARIES})
target_link_libraries(analytic ${CERES_LIBRARIES})