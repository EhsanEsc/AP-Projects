#include "Triangle.hpp"
#include <cassert>
#include <cmath>
#include <stdexcept>

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

Triangle::Triangle(int _side1, int _side2, int _side3)
    : side1(_side1), side2(_side2), side3(_side3) {
  if(side1<=0 || side2<=0 || side3<=0)
    throw std::invalid_argument("Sides must be positive!");
  if (side1 < side2)
    swap(side1, side2);
  if (side1 < side3)
    swap(side1, side3);
  if (side1 > side2 + side3)
    throw std::invalid_argument("Does not satisfy triangle inequality");
}

int Triangle::get_perimeter() const { return side1 + side2 + side3; }

double Triangle::get_area() const {
  double half_perimeter = get_perimeter() / 2.0;
  double radicand = half_perimeter * (half_perimeter - side1) *
                    (half_perimeter - side2) * (half_perimeter - side3);
  return sqrt(radicand);
}

bool Triangle::is_isosceles() const {
  return side1 == side2 || side2 == side3 || side1 == side3;
}

bool Triangle::is_equilateral() const {
  return side1 == side2 && side2 == side3;
}

Triangle::Kind Triangle::get_kind() const {
  return is_equilateral() ? Kind::EQUILATERAL :
    is_isosceles() ? Kind::ISOSCELES : Kind::SCALENE;
}
