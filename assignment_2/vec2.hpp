#ifndef VEC2
#define VEC2

class Vec2
{
public:
  double x, y;

  bool operator==(const Vec2 &rhs) const;
  bool operator!=(const Vec2 &rhs) const;
  Vec2 operator+(const Vec2 &rhs) const;
  Vec2 operator-(const Vec2 &rhs) const;
  Vec2 operator*(const Vec2 &rhs) const;
  Vec2 operator/(const Vec2 &rhs) const;

  void normalize();
  double length();
};

#endif