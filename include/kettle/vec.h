#ifndef VEC_H
#define VEC_H

#include <algorithm>

namespace kettle {
template<typename T, std::size_t n>
struct vec {
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
struct vec<T, 2> {
  using value_type = T;
  union {
    struct {T x, y;};
    std::array<T, 2> data;

  };
  static_assert(std::is_trivial_v<std::array<T, 2>>, "require trivial type");

  constexpr vec() = default;
  constexpr vec(const vec&) = default;
  constexpr vec(T x_, T y_) : x{x_}, y{y_}
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

namespace operand {
template<typename T, std::size_t n>
vec<T, n> operator+(const vec<T, n> &a, const vec<T, n> &b) {
  vec<T, n> result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::plus<T>{});
  return result;
}

template<typename T, std::size_t n>
vec<T, n> operator-(const vec<T, n> &a, const vec<T, n> &b) {
  vec<T, n> result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::minus<T>{});
  return result;
}

template<typename T, std::size_t n>
vec<T, n> operator*(const vec<T, n> &a, const vec<T, n> &b) {
  vec<T, n> result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::multiplies<T>{});
  return result;
}

template<typename T, std::size_t n>
vec<T, n> operator/(const vec<T, n> &a, const vec<T, n> &b) {
  vec<T, n> result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::divides<T>{});
  return result;
}
}
}

#endif //VEC_H
