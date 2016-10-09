#include "Vector2.hpp"

namespace fuzzyTelegram {

template <typename T> Vector2<T>::Vector2(void) : x(0), y(0) {}

template <typename T>
Vector2<T>::Vector2(const T xValue, const T yValue) : x(xValue), y(yValue) {}

template <typename T> Vector2<T>::Vector2(const Vector2 &v) : x(v.x), y(v.y) {}

template <typename T> Vector2<T>::~Vector2<T>() {}

// template class Vector2<int>;
// template class Vector2<float>;
};
