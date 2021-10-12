#include <kettle/Grid.h>

constexpr struct { unsigned width, height;} grid_size{10, 15};

unsigned compute(unsigned i, unsigned j) {
  return i + j * grid_size.width;
}

int main() {
  kettle::Grid<unsigned> grid{grid_size.width, grid_size.height};

  for (unsigned i{} ; i < grid_size.width ; ++i)
    for (unsigned j{} ; j < grid_size.height ; ++j)
      grid(i, j) = i + j * grid_size.width;

  for (unsigned i{} ; i < grid_size.width ; ++i)
    for (unsigned j{} ; j < grid_size.height ; ++j)
      if(grid(i, j) != (i + j * grid_size.width))
        return -1;

  return 0;
}