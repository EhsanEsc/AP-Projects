
#include "cone.h"

using namespace std;

Cone::Cone(int _x, int _y, int _z, int _rad, int _h)
: Shape(_x,_y,_z)
{
  if(_rad <= 0)
    throw "Radius must be greater than 0";
  if(_h <= 0)
    throw "Height must be greater than 0";
  radius = _rad;
  height = _h;
}

void Cone::scale(int factor)
{
  if(factor <= 0)
    throw "Scale number must be greater than 0";
  radius *= factor;
  height *= factor;
}

int Cone::volume() const
{
  return radius*radius*P*height/3;
}

string Cone::get_type() const
{
  return "Cone";
}
