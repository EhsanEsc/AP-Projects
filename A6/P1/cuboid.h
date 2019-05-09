
#ifndef CUBOID_H
#define CUBOID_H

#include<string>
#include "shape.h"

class Cuboid : public Shape
{
public:
  Cuboid(int _x, int _y, int _z, int _w, int _h, int _d);

  void scale(int factor);
	int volume() const;
  std::string get_type() const;
private:
  int height;
  int width;
  int depth;
};

#endif
