#include "Vector2.hpp"

namespace fuzzyTelegram {

template <typename T> Vector2<T>::Vector2(void) : x(0), y(0) {}

template <typename T>
Vector2<T>::Vector2(const T xValue, const T yValue) : x(xValue), y(yValue) {}

template <typename T>
template <typename U>
Vector2<T>::Vector2(const Vector2<U> &vector)
    : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)) {}

template <typename T> Vector2<T>::~Vector2<T>() {}

template <typename T> Vector2<T> Vector2<T>::magnitude() {}

template <typename T>
std::ostream &operator<<(std::ostream &output, const Vector2<T> &v) {
  output << '(' << v.x << ", " << v.y << ')';
  return output;
}

template <typename T>
std::istream &operator>>(std::istream &input, Vector2<T> &v) {
  input >> v.x >> v.y;
  return input;
}

// template class Vector2<int>;
// template class Vector2<float>;
};
