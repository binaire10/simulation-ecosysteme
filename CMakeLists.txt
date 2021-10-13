cmake_minimum_required(VERSION 3.20)
project(kettle)

set(CMAKE_CXX_STANDARD 17)

include(cmake/AutoImport.cmake)
add_subdirectory(engine)
add_library(kettle INTERFACE)
target_include_directories(kettle INTERFACE include)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE kettle BongoCore)

add_subdirectory(test)