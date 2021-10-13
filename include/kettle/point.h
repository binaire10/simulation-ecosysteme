#ifndef POINT_H
#define POINT_H

#include "vec.h"

namespace kettle {
template<typename T, std::size_t n>
struct point {
  using value_type = T;
  std::array<T, n> data;

  constexpr typename std::array<T, 2>::iterator begin() {
    return data.begin();
  }

  constexpr typename std::array<T, 2>::iterator end() {
    return data.end();
  }

  constexpr typename std::array<T, 2>::const_iterator begin() const {
    return data.begin();
  }

  constexpr typename std::array<T, 2>::const_iterator end() const {
    return data.end();
  }
};

template<typename T>
struct point<T, 2> {
  using value_type = T;
  union {
    struct {T x, y;};
    std::array<T, 2> data;

  };
  static_assert(std::is_trivial_v<std::array<T, 2>>, "require trivial type");

  constexpr point() = default;
  constexpr point(const point&) = default;
  constexpr point(T x_, T y_) : x{x_}, y{y_}
  {}

  constexpr T &operator[](std::size_t i) noexcept {
    return data[i];
  }

  constexpr const T &operator[](std::size_t i) const noexcept {
    return data[i];
  }

  constexpr typename std::array<T, 2>::iterator begin() {
    return data.begin();
  }

  constexpr typename std::array<T, 2>::iterator end() {
    return data.end();
  }

  constexpr typename std::array<T, 2>::const_iterator begin() const {
    return data.begin();
  }

  constexpr typename std::array<T, 2>::const_iterator end() const {
    return data.end();
  }
};

template<typename T, std::size_t n>
point<T, n> apply(const point<T, n> &a, const vec<T, n> &b) {
  point<T, n> result;
  std::transform(a.begin(),  a.end(), b.begin(), result.begin(), std::plus<T>{});
  return result;
}

using point2 = point<float, 2>;
using uipoint2 = point<uint32_t, 2>;

}

#endif //POINT_H
