
#include "cuboid.h"

using namespace std;

Cuboid::Cuboid(int _x, int _y, int _z, int _w, int _h, int _d)
: Shape(_x,_y,_z)
{
  if(_w <= 0 || _h <= 0 || _d <= 0)
    throw "Numbers must be greater than 0";
  width = _w;
  height = _h;
  depth = _d;
}

void Cuboid::scale(int factor)
{
  if(factor <= 0)
    throw "Scale number must be greater than 0";
  width *= factor;
  height *= factor;
  depth *= factor;
}

int Cuboid::volume() const
{
  return width*height*depth;
}

string Cuboid::get_type() const
{
  return "Cuboid";
}
