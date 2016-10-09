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
};
