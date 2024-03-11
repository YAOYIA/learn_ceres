cmake_minimum_required(VERSION 3.0)
project(powell)

find_package(Ceres REQUIRED)

include_directories(${CERES_INCLUDE_DIRS})
add_executable(powell powell.cc)
target_link_libraries(powell ${CERES_LIBRARIES})

