add_executable(test_grid test_grid.cpp)
target_link_libraries(test_grid PRIVATE kettle)

add_test(NAME test_grid COMMAND test_grid)