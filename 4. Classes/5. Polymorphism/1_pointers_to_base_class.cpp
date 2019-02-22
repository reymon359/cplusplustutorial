/* Pointers to base class
One of the key features of class inheritance is that a pointer to a derived class is type-compatible with a pointer to its base
class. Polymorphism is the art of taking advantage of this simple but powerful and versatile feature.

The example about the rectangle and triangle classes can be rewritten using pointers taking this feature into account: */

// pointers to base class
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
};

class Rectangle: public Polygon {
  public:
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    int area()
      { return width*height/2; }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  return 0;
}
/*
Function main declares two pointers to Polygon (named ppoly1 and ppoly2). These are assigned the addresses of rect and trgl,
respectively, which are objects of type Rectangle and Triangle. Such assignments are valid, since both Rectangle and Triangle
are classes derived from Polygon.

Dereferencing ppoly1 and ppoly2 (with *ppoly1 and *ppoly2) is valid and allows us to access the members of their pointed objects.
For example, the following two statements would be equivalent in the previous example:

ppoly1->set_values (4,5);
rect.set_values (4,5);

But because the type of ppoly1 and ppoly2 is pointer to Polygon (and not pointer to Rectangle nor pointer to Triangle),
only the members inherited from Polygon can be accessed, and not those of the derived classes Rectangle and Triangle.
That is why the program above accesses the area members of both objects using rect and trgl directly, instead of the
pointers; the pointers to the base class cannot access the area members.

Member area could have been accessed with the pointers to Polygon if area were a member of Polygon instead of a member of
its derived classes, but the problem is that Rectangle and Triangle implement different versions of area, therefore there
is not a single common version that could be implemented in the base class. */
