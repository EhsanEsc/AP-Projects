
#include "shape.h"
using namespace std;

Shape::Shape(int _x, int _y, int _z)
{
  x = _x;
  y = _y;
  z = _z;
}

void Shape::move(int dx, int dy, int dz)
{
  x += dx;
  y += dy;
  z += dz;
}

ostream& operator<<(ostream& out, const Shape* shape)
{
  out << "type: ";
  out << shape->get_type() << ", ";
  out << "center: " << "(" << shape->x << ", " << shape->y << ", " << shape->z << "), ";
  out << "volume: " << shape->volume();
  return out;
}
