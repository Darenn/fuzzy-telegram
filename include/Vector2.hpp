#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>

class Vector2 {

public:
  float x, y;

  /*!
  * \brief Initialize to a Vector2(0, 0).
  */
  Vector2(void);

  /*!
  * \brief Initiliaze to a Vector2(x, y).
  * \param x The x value of the vector.
  * \param y The y value of the vector;
  */
  Vector2(float x, float y);

  /*!
  * \brief Make a copy of the vector given.
  * \param v A pointer to the vector to copy.
  */
  Vector2(Vector2 const *v);

  /*!
  * \brief Make a copy of the vector given.
  * \param v A reference to the vector to copy.
  */
  Vector2(Vector2 const &v);

  ~Vector2(void);

  /*!
  * \brief Normalize this vector.
  */
  void Normalize();

  /*!
  * \return A string representation of a vector : "(x, y)".
  */
  std::string ToString() const;

  /*!
  * \brief Set the x and y value of this vector.
  * \param xValue The x value of the vector.
  * \param yValue The y value of the vector.
  */
  inline void Set(float xValue, float yValue);

  /*!
  * \return A Vector2(0, 1).
  */
  static Vector2 Up();

  /*!
  * \return A Vector2(0, -1).
  */
  static Vector2 Down();

  /*!
  * \return A Vector2(-1, 0).
  */
  static Vector2 Left();

  /*!
  * \return A Vector2(1, 0).
  */
  static Vector2 Right();

  /*!
  * \return A Vector2(0, 0).
  */
  static Vector2 Zero();

  /*!
  * \return A Vector2(1, 1).
  */
  static Vector2 One();

  /*!
  * \return This vector with a magnitude of 1.
  */
  static Vector2 Normalized();

  /*!
  * \return The length of this vector.
  */
  static float Magnitude();

  /*!
  * \return The square length of this vector.
  */
  static Vector2 SquareMagnitude();

  /*!
  * \param from Where the angle starts.
  * \param to Where the angle ends.
  * \return The angle in degrees between from and to.
  */
  static float Angle(Vector2 from, Vector2 to);

  /*!
  * \param vector The vector we want to clamp.
  * \param maxLength The maximum length magnitude.
  * \return A copy of vector with its magnitude clamped to maxLength.
  */
  static Vector2 ClampMagnitude(Vector2 vector, float maxLength);

  /*!
  * \param from The first vector.
  * \param to The second vector.
  * \return The distance between from and to.
  */
  static float Distance(Vector2 from, Vector2 to);

  /*!
  * \param vector1 The first vector.
  * \param vector2 The second vector.
  * \return The dot product of vector1 and vector 2
  */
  static float Dot();

  /*!
  * \brief Linearly interpolate between vectorA and vectorB by t.
  * \param vectorA The first vector.
  * \param vectorB The second vector.
  * \param t How far interpolation is done. Clamped between 0 and 1. When t = 0,
  * return vectorA,  when t = 1 return vectorB, when t = 0.5 return the midpoint
  * of vectorA and vectorB.
  * \return A vector interpolated.
  */
  static Vector2 Lerp(Vector2 vectorA, Vector2 vectorB, float t);

  /*!
  * \param i L'index.
  * \return The x component if i == 0, y if i == 1.
  * \exception std::out_of_range parameter is out of range if i > 1.
  */
  float operator[](int i);

  /*!
  * \brief Set x and y of this to x and y of the given vector.
  * \param v The vector this is assigned.
  */
  inline Vector2 &operator=(const Vector2 &v);

  /*!
  * \brief Set x and y of this to the given value.
  * \param f The new value of x and y of this.
  */
  inline Vector2 &operator=(const float &f);

  /*!
  * \brief Inverse this vector.
  */
  inline Vector2 &operator-(void);

  /*!
  * \brief Check if this vector is equal to another.
  * \return true if x and y components of both vectors are equal.
  */
  inline bool operator==(const Vector2 &v) const;

  /*!
  * \brief Check if this vector is different from another.
  * \return true if x and y components of both vectors are different.
  */
  inline bool operator!=(const Vector2 &v) const;

  // Vector2 to Vector2 operators
  /*!
  * \brief Add this vector to another.
  * \return A vector with x and y components of this vector added to x and y
  * components of the other.
  */
  inline const Vector2 operator+(const Vector2 &v) const;

  /*!
  * \brief Substract this vector to another.
  * \return A vector with x and y components of this vector substracted from x
  * and y components of the other.
  */
  inline const Vector2 operator-(const Vector2 &v) const;

  /*!
  * \brief Multiply this vector to another.
  * \return A vector with x and y components of this vector multiplied by x
  * and y components of the other.
  */
  inline const Vector2 operator*(const Vector2 &v) const;

  /*!
  * \brief Divide this vector to another.
  * \return A vector with x and y components of this vector divided by x
  * and y components of the other.
  */
  inline const Vector2 operator/(const Vector2 &v) const;

  /*!
  * \brief Add x and y components of the other vector to x and y components of
  * this vector.
  */
  inline Vector2 &operator+=(const Vector2 &v);

  /*!
  * \brief Substract x and y components of the other vector from x and y
  * components of this vector.
  */
  inline Vector2 &operator-=(const Vector2 &v);

  /*!
  * \brief Multiply x and y components of the this vector by x and y
  * components of the other vector.
  */
  inline Vector2 &operator*=(const Vector2 &v);

  /*!
  * \brief Divide x and y components of the this vector by x and y
  * components of the other vector.
  */
  inline Vector2 &operator/=(const Vector2 &v);

  /*!
  * \return A copy of this vector with v added to x and y components.
  */
  inline const Vector2 operator+(float v) const;

  /*!
  * \return A copy of this vector with v substracted from x and y components.
  */
  inline const Vector2 operator-(float v) const;

  /*!
  * \return A copy of this vector with x and y components multiplied by v.
  */
  inline const Vector2 operator*(float v) const;

  /*!
  * \return A copy of this vector with x and y components divided by v.
  */
  inline const Vector2 operator/(float v) const;

  /*!
  * \brief Add the given value to x and y components of this vector.
  */
  inline Vector2 &operator+=(float v);

  /*!
  * \brief Substract the given value from x and y components of this vector.
  */
  inline Vector2 &operator-=(float v);

  /*!
  * \brief Multiply x and y components of this vector by the given value.
  */
  inline Vector2 &operator*=(float v);

  /*!
  * \brief Divide x and y components of this vector by the given value.
  */
  inline Vector2 &operator/=(float v);
};

#endif
