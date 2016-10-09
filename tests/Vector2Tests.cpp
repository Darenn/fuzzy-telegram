#include "Vector2.cpp"
#include "gtest/gtest.h"

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
};
