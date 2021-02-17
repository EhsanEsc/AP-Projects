
#include "Triangle.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include<vector>
#include<algorithm>
using namespace std;

constexpr double EPS = 1e-3;

// ISOSCELES -> motesavi saghein
// EQUILATERAL -> motesavi azla
// SCALENE -> na mosavi azla

class TriangleUnderTest : public Triangle
{
public:
  TriangleUnderTest(int x,int y,int z)
  : Triangle(x,y,z){}
  bool check_is_iso() { return is_isosceles(); }
  bool check_is_equ() { return is_equilateral(); }
  int get_biggest_side() { return side1; }
  bool is_same(int s1,int s2,int s3)
  {
    vector<int>v1{s1,s2,s3};
    sort(v1.begin(),v1.end());
    vector<int>v2{side1,side2,side3};
    sort(v2.begin(),v2.end());
    return v1==v2;
  }
};

TEST_CASE("constructor check!")
{
  SECTION("invalid arguments")
  {
    REQUIRE_THROWS(Triangle(0,10,10));
    REQUIRE_THROWS(Triangle(5,-110,10));
    REQUIRE_THROWS(Triangle(5,0,-1));
  }

  SECTION("invalid triangle sides length")
  {
    REQUIRE_THROWS(Triangle(5,22,1110));
  }

  SECTION("normal")
  {
    REQUIRE_NOTHROW(Triangle(10,6,12));
    REQUIRE_NOTHROW(Triangle(100,600,552));
    REQUIRE_NOTHROW(Triangle(14,14,28));
  }
}

TEST_CASE("perimeter check!")
{
  Triangle tr(22,130,110) , huge_tr(1000001,2000000,3000000);
  REQUIRE(tr.get_perimeter() == 262);
  REQUIRE(huge_tr.get_perimeter() == 6000001);
}

TEST_CASE("area check!")
{
  SECTION("ghaem triangle")
  {
    Triangle tr(3,4,5);
    REQUIRE(abs(tr.get_area() - 6) < EPS);
  }

  SECTION("normal")
  {
    Triangle tr(10,5,14);
    REQUIRE(abs(tr.get_area() - 17.605) < EPS);

    Triangle tr2(100,22,109);
    REQUIRE(abs(tr2.get_area() - 1043.0841) < EPS);

    Triangle tr3(22,22,32);
    REQUIRE(abs(tr3.get_area() - 241.5947) < EPS);
  }
}

TEST_CASE("kind check!")
{
  SECTION("ISOSCELES check")
  {
    Triangle tr(12,12,10);
    REQUIRE(tr.get_kind() == Triangle::Kind::ISOSCELES);

    Triangle tr2(22,22,32);
    REQUIRE(tr2.get_kind() == Triangle::Kind::ISOSCELES);

    Triangle tr3(10,10,10);
    REQUIRE(tr3.get_kind() != Triangle::Kind::ISOSCELES);
  }

  SECTION("EQUILATERAL check")
  {
    Triangle tr(12,12,12);
    REQUIRE(tr.get_kind() == Triangle::Kind::EQUILATERAL);

    Triangle tr2(22,22,32);
    REQUIRE(tr2.get_kind() != Triangle::Kind::EQUILATERAL);
  }

  SECTION("SCALENE check")
  {
    Triangle tr(10,5,7);
    REQUIRE(tr.get_kind() == Triangle::Kind::SCALENE);

    Triangle tr2(12,12,10);
    REQUIRE(tr2.get_kind() != Triangle::Kind::SCALENE);

    Triangle tr3(32,32,32);
    REQUIRE(tr3.get_kind() != Triangle::Kind::SCALENE);
  }
}

TEST_CASE("private and protected things check")
{
  SECTION("check is_equ and is_iso")
  {
    TriangleUnderTest tr(10,10,12);
    REQUIRE(tr.check_is_equ() == false);
    REQUIRE(tr.check_is_iso() == true);

    TriangleUnderTest tr2(12,12,12);
    REQUIRE(tr2.check_is_equ() == true);
    REQUIRE(tr2.check_is_iso() == true);

    TriangleUnderTest tr3(10,9,12);
    REQUIRE(tr3.check_is_equ() == false);
    REQUIRE(tr3.check_is_iso() == false);
  }

  SECTION("check biggest side")
  {
    TriangleUnderTest tr(5,8,10);
    REQUIRE(tr.get_biggest_side() == 10);

    TriangleUnderTest tr2(18,9,17);
    REQUIRE(tr2.get_biggest_side() == 18);
  }

  SECTION("saving sides")
  {
    TriangleUnderTest tr(17,20,30);
    REQUIRE(tr.is_same(17,20,30) == true);

    TriangleUnderTest tr2(100,101,89);
    REQUIRE(tr2.is_same(100,101,89) == true);
  }
}
