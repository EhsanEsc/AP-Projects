
#include "sphere.h"

using namespace std;

Sphere::Sphere(int _x, int _y, int _z, int _rad)
: Shape(_x,_y,_z)
{
  if(_rad <= 0)
    throw "Radius must be greater than 0";
  radius = _rad;
}

void Sphere::scale(int factor)
{
  if(factor <= 0)
    throw "Scale number must be greater than 0";
  radius *= factor;
}

int Sphere::volume() const
{
  return radius*radius*radius*P*4/3;
}

string Sphere::get_type() const
{
  return "Sphere";
}
