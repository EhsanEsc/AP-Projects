
#ifndef SPHERE_H
#define SPHERE_H

#include<string>
#include "shape.h"

class Sphere : public Shape
{
public:
  Sphere(int _x, int _y, int _z, int _rad);

  void scale(int factor);
	int volume() const;
  std::string get_type() const;
private:
  int radius;
};

#endif
