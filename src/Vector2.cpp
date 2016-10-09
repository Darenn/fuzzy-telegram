#include "Vector2.hpp"
#include <stdexcept>

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
const T Vector2<T>::operator[](const std::size_t i) const {
  if (i == 0)
    return x;
  else if (i == 1)
    return y;
  else
    throw std::out_of_range("Index should be 0 or 1.");
}

// template class Vector2<int>;
// template class Vector2<float>;
};
