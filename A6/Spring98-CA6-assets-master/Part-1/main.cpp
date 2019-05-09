#include <vector>
#include <iostream>

#include "shape.h"
#include "sphere.h"
#include "cone.h"
#include "cuboid.h"

using namespace std;

int main()
{
    vector<Shape*> shapes;
    shapes.push_back(new Sphere(10, 10, 10, 2));
    shapes.push_back(new Cuboid(10, 10, 10, 1, 2, 3));
    shapes.push_back(new Cone(10, 10, 10, 2, 5));

    for (int i = 0; i < shapes.size(); ++i)
        cout << shapes[i] << endl;

    for (int i = 0; i < shapes.size(); ++i) {
        shapes[i]->move(-5, -10, 0);
        shapes[i]->scale(2);
    }

    for (int i = 0; i < shapes.size(); ++i)
        cout << shapes[i] << endl;
}