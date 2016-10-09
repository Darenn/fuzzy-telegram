#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

namespace fuzzyTelegram {

template <typename T> class Vector2 {

public:
  T x;
  T y;

  /*!
  * \brief Initialize to a Vector2(0, 0).
  */
  Vector2(void);

  /*!
  * \brief Initiliaze to a Vector2(x, y).
  * \param x The x value of the vector.
  * \param y The y value of the vector;
  */
  Vector2(const T x, const T y);

  /*!
  * \brief Make a copy of the vector given.
  * \param v A reference to the vector to copy.
  */
  Vector2(const Vector2 &v);

  ~Vector2(void);

  /*!
  * \brief Normalize this vector.
  */
  void normalize();

  /*!
  * \brief Return a string representation of a vector : "(x, y)".
  * \return A string representation of a vector : "(x, y)".
  */
  std::string toString() const;

  /*!
  * \brief Set the x and y value of this vector.
  * \param xValue The x value of the vector.
  * \param yValue The y value of the vector.
  */
  void set(T xValue, T yValue);

  /*!
  * \brief Return a Vector2(0, 1).
  * \return A Vector2(0, 1).
  */
  static Vector2 up();

  /*!
  * \brief Return a Vector2(0, -1).
  * \return A Vector2(0, -1).
  */
  static Vector2 down();

  /*!
  * \brief Return a Vector2(-1, 0).
  * \return A Vector2(-1, 0).
  */
  static Vector2 left();

  /*!
  * \brief Return a Vector2(1, 0).
  * \return A Vector2(1, 0).
  */
  static Vector2 right();

  /*!
  * \brief Return a Vector(0, 0).
  * \return A Vector2(0, 0).
  */
  static Vector2 zero();

  /*!
  * \brief Return a Vector2(1, 1).
  * \return A Vector2(1, 1).
  */
  static Vector2 one();

  /*!
  * \brief Return A copy of this vector with a magnitude of 1.
  * \return A copy of this vector with a magnitude of 1.
  */
  Vector2 normalized();

  /*!
  * \brief Return the length of this vector.
  * \return The length of this vector.
  */
  float magnitude();

  /*!
  * \brief Return the square length of this vector.
  * \return The square length of this vector.
  */
  Vector2 squareMagnitude();

  /*!
  * \brief Return the angle in degrees between two vectors.
  * \param from Where the angle starts.
  * \param to Where the angle ends.
  * \return The angle in degrees between from and to.
  */
  static float angle(const Vector2 &from, const Vector2 &to);

  /*!
  * \brief Return A copy of the vector with its magnitude clamped to
  * maxLength.
  * \param vector The vector we want to clamp.
  * \param maxLength The maximum length magnitude.
  * \return A copy of vector with its magnitude clamped to maxLength.
  */
  static Vector2 clampMagnitude(const Vector2 &vector, float maxLength);

  /*!
  * \brief Return the distance between two vectors.
  * \param from The first vector.
  * \param to The second vector.
  * \return The distance between from and to.
  */
  static float distance(const Vector2 &from, const Vector2 &to);

  /*!
  * \brief Return the dot product of two vectors.
  * \param vector1 The first vector.
  * \param vector2 The second vector.
  * \return The dot product of vector1 and vector 2
  */
  static float dot(const Vector2 &vector1, const Vector2 &vector2);

  /*!
  * \brief Linearly interpolate between vectorA and vectorB by t.
  * \param vectorA The first vector.
  * \param vectorB The second vector.
  * \param t How far interpolation is done. Clamped between 0 and 1. When t =
  * 0,
  * return vectorA,  when t = 1 return vectorB, when t = 0.5 return the
  * midpoint
  * of vectorA and vectorB.
  * \return A vector interpolated.
  */
  static Vector2 lerp(const Vector2 &vectorA, const Vector2 &vectorB, float t);

  /*!
  * \brief Insert into the output stream the vector's representation "(x, y)".
  * \param output The output stream.
  * \param v The vector to insert into output.
  * \return A The output stream.
  */
  friend std::ostream &operator<<(std::ostream &output, const Vector2 &v) {
    output << '(' << v.x << ", " << v.y << ')';
    return output;
  }

  /*!
  * \brief Extract the x and y components from the input stream into v.
  * \param input The input stream.
  * \param v The vector in which we insert x and y components.
  * \return The input stream.
  */
  friend std::istream &operator>>(std::istream &input, Vector2 &v) {
    input >> v.x >> v.y;
    return input;
  }

  /*!
  * \brief Return the x (i == 0) or y (i == 1) components.
  * \param i L'index.
  * \return The x component if i == 0, y if i == 1.
  * \exception std::out_of_range Index i is out of range if i > 1 or i < 0.
  */
  float operator[](int i);

  /*!
  * \brief Set x and y of this to x and y of the given vector.
  * \param v The vector this is assigned.
  * \return This vector.
  */
  Vector2 &operator=(const Vector2 &v);

  /*!
  * \brief Set x and y of this to the given value.
  * \param f The new value of x and y of this.
  * \return This vector.
  */
  Vector2 &operator=(const float &f);

  /*!
  * \brief Inverse this vector.
  * \return This vector.
  */
  Vector2 &operator-(void);

  /*!
  * \brief Check if this vector is equal to another.
  * \return true if x and y components of both vectors are equal.
  */
  bool operator==(const Vector2 &v) const;

  /*!
  * \brief Check if this vector is different from another.
  * \return true if x and y components of both vectors are different.
  */
  bool operator!=(const Vector2 &v) const;

  /*!
  * \brief Add this vector to another.
  * \return A vector with x and y components of this vector added to x and y
  * components of the other.
  */
  const Vector2 operator+(const Vector2 &v) const;

  /*!
  * \brief Substract this vector to another.
  * \return A vector with x and y components of this vector substracted from x
  * and y components of the other.
  */
  const Vector2 operator-(const Vector2 &v) const;

  /*!
  * \brief Multiply this vector to another.
  * \return A vector with x and y components of this vector multiplied by x
  * and y components of the other.
  */
  const Vector2 operator*(const Vector2 &v) const;

  /*!
  * \brief Divide this vector to another.
  * \return A vector with x and y components of this vector divided by x
  * and y components of the other.
  */
  const Vector2 operator/(const Vector2 &v) const;

  /*!
  * \brief Add x and y components of the other vector to x and y components of
  * this vector.
  * \return This vector.
  */
  Vector2 &operator+=(const Vector2 &v);

  /*!
  * \brief Substract x and y components of the other vector from x and y
  * components of this vector.
  * \return This vector.
  */
  Vector2 &operator-=(const Vector2 &v);

  /*!
  * \brief Multiply x and y components of the this vector by x and y
  * components of the other vector.
  * \return This vector.
  */
  Vector2 &operator*=(const Vector2 &v);

  /*!
  * \brief Divide x and y components of the this vector by x and y
  * components of the other vector.
  * \return This vector.
  */
  Vector2 &operator/=(const Vector2 &v);

  /*!
  * \brief Return a copy of this vector with v added to x and y components.
  * \return A copy of this vector with v added to x and y components.
  */
  const Vector2 operator+(float v) const;

  /*!
  * \brief Return a copy of this vector with v substracted from x and y
  * components.
  * \return A copy of this vector with v substracted from x and y components.
  */
  const Vector2 operator-(float v) const;

  /*!
  * \brief Return a copy of this vector with x and y components multiplied by
  * v.
  * \return A copy of this vector with x and y components multiplied by v.
  */
  const Vector2 operator*(float v) const;

  /*!
  * \brief Return a copy of this vector with x and y components divided by v.
  * \return A copy of this vector with x and y components divided by v.
  */
  const Vector2 operator/(float v) const;

  /*!
  * \brief Add the given value to x and y components of this vector.
  * \return This vector.
  */
  Vector2 &operator+=(float v);

  /*!
  * \brief Substract the given value from x and y components of this vector.
  * \return This vector.
  */
  Vector2 &operator-=(float v);

  /*!
  * \brief Multiply x and y components of this vector by the given value.
  * \return This vector.
  */
  Vector2 &operator*=(float v);

  /*!
  * \brief Divide x and y components of this vector by the given value.
  * \return This vector.
  */
  Vector2 &operator/=(float v);
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
}

#endif
