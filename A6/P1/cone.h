
#ifndef CONE_H
#define CONE_H

#include<string>
#include "shape.h"

class Cone : public Shape
{
public:
  Cone(int _x, int _y, int _z, int _rad, int _h);

  void scale(int factor);
	int volume() const;
  std::string get_type() const;
private:
  int radius;
  int height;
};

#endif
