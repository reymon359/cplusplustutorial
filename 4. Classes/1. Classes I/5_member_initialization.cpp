/*Member initialization in constructors
When a constructor is used to initialize other members, these other members can be initialized directly, without
resorting to statements in its body. This is done by inserting, before the constructor's body, a colon (:) and
a list of initializations for class members. For example, consider a class with the following declaration:

class Rectangle {
    int width,height;
  public:
    Rectangle(int,int);
    int area() {return width*height;}
};

The constructor for this class could be defined, as usual, as:

Rectangle::Rectangle (int x, int y) { width=x; height=y; }

But it could also be defined using member initialization as:

Rectangle::Rectangle (int x, int y) : width(x) { height=y; }

Or even:

Rectangle::Rectangle (int x, int y) : width(x), height(y) { }

Note how in this last case, the constructor does nothing else than initialize its members, hence it has an empty function body.

For members of fundamental types, it makes no difference which of the ways above the constructor is defined, because they
are not initialized by default, but for member objects (those whose type is a class), if they are not initialized after
the colon, they are default-constructed.

Default-constructing all members of a class may or may always not be convenient: in some cases, this is a waste (when the
member is then reinitialized otherwise in the constructor), but in some other cases, default-construction is not even
possible (when the class does not have a default constructor). In these cases, members shall be initialized in the
member initialization list. For example:*/

// member initialization
#include <iostream>
using namespace std;

class Circle {
    double radius;
  public:
    Circle(double r) : radius(r) { }
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}
    double volume() {return base.area() * height;}
};

int main () {
  Cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  return 0;
}
/* In this example, class Cylinder has a member object whose type is another class (base's type is Circle).
Because objects of class Circle can only be constructed with a parameter, Cylinder's constructor needs to
call base's constructor, and the only way to do this is in the member initializer list.

These initializations can also use uniform initializer syntax, using braces {} instead of parentheses ():

Cylinder::Cylinder (double r, double h) : base{r}, height{h} { }*/
