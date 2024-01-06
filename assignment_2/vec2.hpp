#ifndef VEC2
#define VEC2

class Vec2
{
public:
  double x = 0, y = 0;

  bool operator==(const Vec2 &rhs) const;
  bool operator!=(const Vec2 &rhs) const;

  Vec2 operator+(const Vec2 &rhs) const;
  Vec2 operator-(const Vec2 &rhs) const;
  Vec2 operator*(const Vec2 &rhs) const;
  Vec2 operator/(const Vec2 &rhs) const;

  void operator+=(const Vec2 &rhs);
  void operator-=(const Vec2 &rhs);
  void operator*=(const Vec2 &rhs);
  void operator/=(const Vec2 &rhs);

  void normalize();
  double length();

  Vec2();
  Vec2(double xin, double yin);
};

#endif