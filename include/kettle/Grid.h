#ifndef GRID_H
#define GRID_H

#include <memory>

namespace kettle
{
template<typename T>
class Grid
{
public:
  Grid(std::size_t column, std::size_t row)
    : m_column{column}, m_row{row}, m_grid{std::make_unique<T[]>(column * row)}
  {}

  T &operator()(std::size_t x, std::size_t y)
  {
    return m_grid[x + y * m_column];
  }

  const T &operator()(std::size_t x, std::size_t y) const
  {
    return m_grid[x + y * m_column];
  }

  [[nodiscard]] size_t getColumn() const noexcept
  {
    return m_column;
  }

  [[nodiscard]] size_t getRow() const noexcept
  {
    return m_row;
  }

  const std::unique_ptr<T[]> &getGrid() const
  {
    return m_grid;
  }

private:
  std::size_t m_column;
  std::size_t m_row;
  std::unique_ptr<T[]> m_grid;
};
}

#endif //GRID_H
