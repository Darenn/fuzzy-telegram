#include "Vector2.hpp"
#include <cassert>
#include <stdexcept>

namespace fuzzyTelegram {

template <typename T> Vector2<T>::Vector2(void) : x(0), y(0) {}

template <typename T>
Vector2<T>::Vector2(const T xValue, const T yValue) : x(xValue), y(yValue) {}

template <typename T> Vector2<T>::Vector2(const T xy) : x(xy), y(xy) {}

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

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator=(const Vector2<U> &v) {
  assert(v != NULL);
  x = static_cast<T>(v.x);
  y = static_cast<T>(v.y);
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator=(const U &value) {
  x = static_cast<T>(value);
  y = static_cast<T>(value);
  return *this;
}

template <typename T> Vector2<T> Vector2<T>::operator-(void) const {
  return Vector2<T>(-x, -y);
}

template <typename T>
template <typename U>
bool Vector2<T>::operator==(const Vector2<U> &v) const {
  return static_cast<T>(v.x) == x && static_cast<T>(v.y) == v.y;
}

template <typename T>
template <typename U>
bool Vector2<T>::operator!=(const Vector2<U> &v) const {
  return static_cast<T>(v.x) != x || static_cast<T>(v.y) != v.y;
}

template <typename T>
const Vector2<T> Vector2<T>::operator+(const Vector2<T> &v) const {
  return Vector2<T>(x + v.x, y + v.y);
}

template <typename T>
const Vector2<T> Vector2<T>::operator-(const Vector2<T> &v) const {
  return Vector2<T>(x - v.x, y - v.y);
}

template <typename T>
const Vector2<T> Vector2<T>::operator*(const Vector2<T> &v) const {
  return Vector2<T>(x * v.x, y * v.y);
}

template <typename T>
const Vector2<T> Vector2<T>::operator/(const Vector2<T> &v) const {
  return Vector2<T>(x / v.x, y / v.y);
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator+=(const Vector2<U> &v) {
  x += v.x;
  y += v.y;
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator-=(const Vector2<U> &v) {
  x -= v.x;
  y -= v.y;
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator*=(const Vector2<U> &v) {
  x *= v.x;
  y *= v.y;
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator/=(const Vector2<U> &v) {
  x /= v.x;
  y /= v.y;
  return *this;
}

template <typename T>
template <typename U>
const Vector2<T> Vector2<T>::operator+(U value) const {
  return Vector2<T>(x + static_cast<T>(value), y + static_cast<T>(value));
}

template <typename T>
template <typename U>
const Vector2<T> Vector2<T>::operator-(U value) const {
  return Vector2<T>(x - static_cast<T>(value), y - static_cast<T>(value));
}

template <typename T>
template <typename U>
const Vector2<T> Vector2<T>::operator*(U value) const {
  return Vector2<T>(x * static_cast<T>(value), y * static_cast<T>(value));
}

template <typename T>
template <typename U>
const Vector2<T> Vector2<T>::operator/(U value) const {
  assert(value != 0);
  return Vector2<T>(x / static_cast<T>(value), y / static_cast<T>(value));
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator+=(const U value) {
  x += static_cast<T>(value);
  y += static_cast<T>(value);
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator-=(const U value) {
  x -= static_cast<T>(value);
  y -= static_cast<T>(value);
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator*=(const U value) {
  x *= static_cast<T>(value);
  y *= static_cast<T>(value);
  return *this;
}

template <typename T>
template <typename U>
Vector2<T> &Vector2<T>::operator/=(const U value) {
  x /= static_cast<T>(value);
  y /= static_cast<T>(value);
  return *this;
}

// template class Vector2<int>;
// template class Vector2<float>;
};
