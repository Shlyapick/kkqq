cmake_minimum_required(VERSION 3.0.0)
project(lab3.2.a VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(lab3.2.a lab3.2.a.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
