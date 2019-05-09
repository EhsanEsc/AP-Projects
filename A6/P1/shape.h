#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <iostream>
#include <string>

const double P = 3.14;

class Shape
{
protected:
	int x;
	int y;
	int z;
public:
	Shape(int _x, int _y, int _z);

	void move(int dx, int dy, int dz);

	virtual void scale(int factor) = 0;
	virtual int volume() const = 0;
	virtual std::string get_type() const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape* shape);
};

#endif
