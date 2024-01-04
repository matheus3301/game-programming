#include <iostream>

class Vec2
{
public:
  float x = 0;
  float y = 0;

  Vec2() {}
  Vec2(float xi, float yi)
      : x(xi), y(yi)
  {
  }

  Vec2 operator+(const Vec2 &rhs) const
  {
    return Vec2(x + rhs.x, y + rhs.y);
  }

  void operator+=(const Vec2 &v)
  {
    x += v.x;
    y += v.y;
  }
};

int main(int argc, char *argv[])
{

  return 0;
}