#include "Vector2.cpp"
#include "gtest/gtest.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace fuzzyTelegram {

TEST(VoidConstructor, Integer) {
  Vector2i v;
  EXPECT_EQ(0, v.x);
  EXPECT_EQ(0, v.y);
}

TEST(VoidConstructor, Floats) {
  Vector2f v;
  EXPECT_EQ(0.0f, v.x);
  EXPECT_EQ(0.0f, v.y);
}

TEST(ValuesConstructor, Integer) {
  Vector2i v(2, 4);
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(4, v.y);
}

TEST(ValuesConstructor, Float) {
  Vector2f v(-50, 0);
  EXPECT_EQ(-50.0f, v.x);
  EXPECT_EQ(0.0f, v.y);
}

TEST(CopyConstructor, Integer) {
  Vector2i v(-4, 60);
  Vector2i v2(v);
  EXPECT_EQ(v2.x, v.x);
  EXPECT_EQ(v2.y, v.y);
}

TEST(CopyConstructor, Float) {
  Vector2f v(-3500, 9371);
  Vector2f v2(v);
  EXPECT_EQ(v2.x, v.x);
  EXPECT_EQ(v2.y, v.y);
}

TEST(CopyConstructor, IntToFloat) {
  Vector2f v(-3500, 9371);
  Vector2i v2(v);
  EXPECT_EQ(v2.x, v.x);
  EXPECT_EQ(v2.y, v.y);
}

TEST(ValueConstructor, SameType) {
  Vector2i v(2);
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(2, v.y);
}

TEST(ValueConstructor, DifferentType) {
  Vector2i v(2.0f);
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(2, v.y);
}

TEST(Stream, StreamInsertion) {
  Vector2i v(2, 5);
  std::stringstream s;
  s << v;
  EXPECT_STREQ("(2, 5)", s.str().c_str());
}

TEST(Stream, StreamExtraction) {
  Vector2i v;
  std::stringstream s("2 5");
  s >> v;
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(5, v.y);
}

TEST(ArraySubscriptOperator, InRange) {
  Vector2i v(3, 4);
  int x = v.x;
  int y = v.y;
  EXPECT_EQ(x, v[0]);
  EXPECT_EQ(y, v[1]);
}

TEST(ArraySubscriptOperator, OutOfRange) {
  Vector2i v(3, 4);
  EXPECT_THROW(v[5], std::out_of_range);
  EXPECT_THROW(v[-1], std::out_of_range);
}

TEST(AssignmentOperator, FromVectorSameType) {
  Vector2i v(80, 65);
  Vector2i v2 = v;
  EXPECT_EQ(v2.x, v.x);
  EXPECT_EQ(v2.y, v.y);
}

// TODO operator= on vectors of diferent type. Learn about user-defined
// conversion.
TEST(DISABLED_AssignmentOperator, FromVectorDifferentType) {
  Vector2i v(80, 65);
  // Vector2f v2 = v;
  // EXPECT_EQ(v2.x, v.x);
  // EXPECT_EQ(v2.y, v.y);
}

TEST(AssignmentOperator, FromValueSameType) {
  Vector2i v(80, 65);
  v = 2;
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(2, v.y);
}

TEST(AssignmentOperator, FromValueDifferentType) {
  Vector2i v(80, 65);
  v = 2.0f;
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(2, v.y);
}

TEST(UnaryMinusOperator, PositiveVector) {
  Vector2i v(20, 679);
  EXPECT_EQ((-v).x, -20);
  EXPECT_EQ((-v).y, -679);
}

TEST(UnaryMinusOperator, NegativeVectorWithZero) {
  Vector2i v(0, -50);
  EXPECT_EQ((-v).x, 0);
  EXPECT_EQ((-v).y, 50);
}

TEST(EqualityOperator, VectorsSameType) {
  Vector2i v(30, 25);
  Vector2i v2(30, 25);
  EXPECT_TRUE(v == v2);
}

TEST(EqualityOperator, VectorsDifferentType) {
  Vector2i v(30, 25);
  Vector2f v2(30.0f, 25.0f);
  EXPECT_TRUE(v == v2);
}

TEST(EqualityOperator, VectorsNotEqual) {
  Vector2i v(30, 25);
  Vector2i v2(3, 2);
  EXPECT_FALSE(v == v2);
}

TEST(NotEqualOperator, VectorsSameType) {
  Vector2i v(30, 25);
  Vector2i v2(2, 25);
  EXPECT_TRUE(v != v2);
}

TEST(NotEqualOperator, VectorsDifferentType) {
  Vector2i v(30, 25);
  Vector2f v2(31.0f, 22.0f);
  EXPECT_TRUE(v != v2);
}

TEST(NotEqualOperator, VectorsEqual) {
  Vector2i v(30, 25);
  Vector2i v2(30, 25);
  EXPECT_FALSE(v != v2);
}

TEST(BinaryArithmeticOperatorPlusWithVector, VectorsSameType) {
  Vector2i v(20, 30);
  Vector2i v2(30, 400);
  EXPECT_EQ(50, (v + v2).x);
  EXPECT_EQ(430, (v + v2).y);
}

// TODO Would be nice to add two different vectors, but of which type should be
// the result ? (maybe the larger type ?(the one which can contains without loss
// the result))
TEST(DISABLED_BinaryArithmeticOperatorPlusWithVector, VectorsDifferentType) {
  Vector2i v(20, 30);
  Vector2f v2(30.0, 400.0);
  // EXPECT_EQ(50.0, (v + v2).x);
  // EXPECT_EQ(430.0, (v + v2).y);
}

TEST(BinaryArithmeticOperatorMinusWithVector, VectorsSameType) {
  Vector2i v(20, 30);
  Vector2i v2(30, 400);
  EXPECT_EQ(-10, (v - v2).x);
  EXPECT_EQ(-370, (v - v2).y);
}

// TODO Would be nice to substract two different vectors, but of which type
// should be Same with all other operators.
// the result ? (maybe the larger type (the one which can contains without loss
// the result)?)
TEST(DISABLED_BinaryArithmeticOperatorMinusWithVector, VectorsDifferentType) {
  Vector2i v(20, 30);
  Vector2f v2(30.0, 400.0);
  // EXPECT_EQ(-10.0, (v - v2).x);
  // EXPECT_EQ(-370.0, (v - v2).y);
}

TEST(BinaryArithmeticOperatorMultiplyWithVector, VectorsSameType) {
  Vector2i v(2, 3);
  Vector2i v2(3, 4);
  EXPECT_EQ(6, (v * v2).x);
  EXPECT_EQ(12, (v * v2).y);
}

TEST(BinaryArithmeticOperatorDivideWithVector, VectorsSameType) {
  Vector2i v(6, 16);
  Vector2i v2(3, 4);
  EXPECT_EQ(2, (v / v2).x);
  EXPECT_EQ(4, (v / v2).y);
}

TEST(CompoundAssignmentOperatorPlusWithVector, VectorsSameType) {
  Vector2i v(20, 30);
  Vector2i v2(40, 20);
  v += v2;
  EXPECT_EQ(60, v.x);
  EXPECT_EQ(50, v.y);
}

TEST(CompoundAssignmentOperatorPlusWithVector, VectorsDifferentType) {
  Vector2i v(20, 30);
  Vector2f v2(40.0, 20.0);
  v += v2;
  EXPECT_EQ(60, v.x);
  EXPECT_EQ(50, v.y);
}

TEST(CompoundAssignmentOperatorMinusWithVector, VectorsSameType) {
  Vector2i v(20, 30);
  Vector2i v2(40, 20);
  v -= v2;
  EXPECT_EQ(-20, v.x);
  EXPECT_EQ(10, v.y);
}

TEST(CompoundAssignmentOperatorMinusWithVector, VectorsDifferentType) {
  Vector2i v(20, 30);
  Vector2f v2(40.0f, 20.0f);
  v -= v2;
  EXPECT_EQ(-20, v.x);
  EXPECT_EQ(10, v.y);
}

TEST(CompoundAssignmentOperatorMultiplyWithVector, VectorsSameType) {
  Vector2i v(2, 3);
  Vector2i v2(0, 2);
  v *= v2;
  EXPECT_EQ(0, v.x);
  EXPECT_EQ(6, v.y);
}

TEST(CompoundAssignmentOperatorMultiplyWithVector, VectorsDifferentType) {
  Vector2i v(2, 3);
  Vector2f v2(0.0f, 2.0f);
  v *= v2;
  EXPECT_EQ(0, v.x);
  EXPECT_EQ(6, v.y);
}

TEST(CompoundAssignmentOperatorDivideWithVector, VectorsSameType) {
  Vector2i v(2, 4);
  Vector2i v2(1, 2);
  v /= v2;
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(2, v.y);
}

TEST(CompoundAssignmentOperatorDivideWithVector, VectorsDifferentType) {
  Vector2i v(2, 4);
  Vector2f v2(1.0f, 2.0f);
  v /= v2;
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(2, v.y);
}

TEST(BinaryArithmeticOperatorPlusWithValue, ValueSameType) {
  Vector2i v(99, 23);
  EXPECT_EQ(100, (v + 1).x);
  EXPECT_EQ(24, (v + 1).y);
}

TEST(BinaryArithmeticOperatorPlusWithValue, ValueDifferentType) {
  Vector2i v(99, 23);
  EXPECT_EQ(100, (v + 1.0f).x);
  EXPECT_EQ(24, (v + 1.0f).y);
}

TEST(BinaryArithmeticOperatorMinusWithValue, ValueSameType) {
  Vector2i v(99, 23);
  EXPECT_EQ(98, (v - 1).x);
  EXPECT_EQ(22, (v - 1).y);
}

TEST(BinaryArithmeticOperatorMinusWithValue, ValueDifferentType) {
  Vector2i v(99, 23);
  EXPECT_EQ(98, (v - 1.0f).x);
  EXPECT_EQ(22, (v - 1.0f).y);
}

TEST(BinaryArithmeticOperatorMultiplyWithValue, ValueSameType) {
  Vector2i v(100, 25);
  EXPECT_EQ(200, (v * 2).x);
  EXPECT_EQ(50, (v * 2).y);
}

TEST(BinaryArithmeticOperatorMultiplyWithValue, ValueDifferentType) {
  Vector2i v(100, 25);
  EXPECT_EQ(200, (v * 2.0f).x);
  EXPECT_EQ(50, (v * 2.0f).y);
}

TEST(BinaryArithmeticOperatorDivideWithValue, ValueSameType) {
  Vector2i v(100, 25);
  EXPECT_EQ(50, (v / 2).x);
  EXPECT_EQ(5, (v / 5).y);
}

TEST(BinaryArithmeticOperatorDivideWithValue, ValueDifferentType) {
  Vector2i v(100, 25);
  EXPECT_EQ(50, (v / 2.0f).x);
  EXPECT_EQ(5, (v / 5.0f).y);
}

TEST(CompoundAssignmentOperatorPlusWithValue, ValueSameType) {
  Vector2i v(2, 4);
  v += 2;
  EXPECT_EQ(4, v.x);
  EXPECT_EQ(6, v.y);
}

TEST(CompoundAssignmentOperatorPlusWithValue, ValueDifferentType) {
  Vector2i v(2, 4);
  v += 3.0f;
  EXPECT_EQ(5, v.x);
  EXPECT_EQ(7, v.y);
}

TEST(CompoundAssignmentOperatorMinusWithValue, ValueSameType) {
  Vector2i v(2, 4);
  v -= 2;
  EXPECT_EQ(0, v.x);
  EXPECT_EQ(2, v.y);
}

TEST(CompoundAssignmentOperatorMinusWithValue, ValueDifferentType) {
  Vector2i v(2, 4);
  v -= 3.0f;
  EXPECT_EQ(-1, v.x);
  EXPECT_EQ(1, v.y);
}

TEST(CompoundAssignmentOperatorMultiplyWithValue, ValueSameType) {
  Vector2i v(2, 4);
  v *= 2;
  EXPECT_EQ(4, v.x);
  EXPECT_EQ(8, v.y);
}

TEST(CompoundAssignmentOperatorMultiplyWithValue, ValueDifferentType) {
  Vector2i v(2, 4);
  v *= 3.0f;
  EXPECT_EQ(6, v.x);
  EXPECT_EQ(12, v.y);
}

TEST(CompoundAssignmentOperatorDivideWithValue, ValueSameType) {
  Vector2i v(6, 4);
  v /= 2;
  EXPECT_EQ(3, v.x);
  EXPECT_EQ(2, v.y);
}

TEST(CompoundAssignmentOperatorDivideWithValue, ValueDifferentType) {
  Vector2i v(6, 4);
  v /= 3.0f;
  EXPECT_EQ(2, v.x);
  EXPECT_EQ(1, v.y);
}
};
