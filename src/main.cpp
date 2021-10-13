#include <iostream>
#include <kettle/Grid.h>
#include <kettle/FunctionUnion.h>
#include <kettle/point.h>
#include <kettle/vec.h>

int main()
{
  kettle::point2 p{2,2};
  std::cout << sizeof(p) << std::endl;

  kettle::Grid<int> grid{10, 11};
  auto u = kettle::function_union(
    [](char c){ std::cout << c << '\n'; },
    [](const kettle::point2 &p){ std::cout << '(' << p.x << ' ' << p.y << ')' << '\n'; },
    [](int i){ std::cout << i << '\n'; });
  u(10);
  u('c');
  u(p);
  return 0;
}
