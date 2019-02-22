/*Abstract base classes
Abstract base classes are something very similar to the Polygon class in the previous example.
They are classes that can only be used as base classes, and thus are allowed to have virtual member
functions without definition (known as pure virtual functions). The syntax is to replace their definition
by =0 (an equal sign and a zero):

An abstract base Polygon class could look like this:

// abstract class CPolygon
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area () =0;
};

Notice that area has no definition; this has been replaced by =0, which makes it a pure virtual function.
Classes that contain at least one pure virtual function are known as abstract base classes.

Abstract base classes cannot be used to instantiate objects. Therefore, this last abstract base class version
of Polygon could not be used to declare objects like:

Polygon mypolygon;   // not working if Polygon is abstract base class

But an abstract base class is not totally useless. It can be used to create pointers to it, and take advantage
of all its polymorphic abilities. For example, the following pointer declarations would be valid:

Polygon * ppoly1;
Polygon * ppoly2;

And can actually be dereferenced when pointing to objects of derived (non-abstract) classes.
Here is the entire example:

// abstract base class
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area (void) =0;
};

class Rectangle: public Polygon {
  public:
    int area (void)
      { return (width * height); }
};

class Triangle: public Polygon {
  public:
    int area (void)
      { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  cout << ppoly1->area() << '\n';
  cout << ppoly2->area() << '\n';
  return 0;
}
// OUTPUT
20
10

In this example, objects of different but related types are referred to using a unique type of pointer (Polygon*)
and the proper member function is called every time, just because they are virtual. This can be really useful in
 some circumstances. For example, it is even possible for a member of the abstract base class Polygon to use the
 special pointer this to access the proper virtual members, even though Polygon itself has no implementation for this function:

// pure virtual members can be called
// from the abstract base class
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area() =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

class Rectangle: public Polygon {
  public:
    int area (void)
      { return (width * height); }
};

class Triangle: public Polygon {
  public:
    int area (void)
      { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly1->printarea();
  ppoly2->printarea();
  return 0;
}
// OUTPUT
20
10

Virtual members and abstract classes grant C++ polymorphic characteristics, most useful for object-oriented projects.
Of course, the examples above are very simple use cases, but these features can be applied to arrays of objects or
dynamically allocated objects.

Here is an example that combines some of the features in the latest chapters, such as dynamic memory,
constructor initializers and polymorphism:*/

// dynamic allocation and polymorphism
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    Polygon (int a, int b) : width(a), height(b) {}
    virtual int area (void) =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

class Rectangle: public Polygon {
  public:
    Rectangle(int a,int b) : Polygon(a,b) {}
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    Triangle(int a,int b) : Polygon(a,b) {}
    int area()
      { return width*height/2; }
};

int main () {
  Polygon * ppoly1 = new Rectangle (4,5);
  Polygon * ppoly2 = new Triangle (4,5);
  ppoly1->printarea();
  ppoly2->printarea();
  delete ppoly1;
  delete ppoly2;
  return 0;
}

/* Notice that the ppoly pointers:

Polygon * ppoly1 = new Rectangle (4,5);
Polygon * ppoly2 = new Triangle (4,5);

are declared being of type "pointer to Polygon", but the objects allocated have been declared having the derived
class type directly (Rectangle and Triangle).*/
