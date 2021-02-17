#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

class Triangle {
public:
  enum class Kind { ISOSCELES, EQUILATERAL, SCALENE };

protected:
  int side1;
  int side2;
  int side3;
  bool is_isosceles() const;
  bool is_equilateral() const;

public:
  Triangle(int side1, int side2, int side3);
  int get_perimeter() const;
  double get_area() const;
  Kind get_kind() const;
};

#endif
