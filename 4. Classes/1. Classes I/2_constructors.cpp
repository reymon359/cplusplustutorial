/*Constructors
What would happen in the previous example if we called the member function area before having called
set_values? An undetermined result, since the members width and height had never been assigned a value.

In order to avoid that, a class can include a special function called its constructor, which is automatically
called whenever a new object of this class is created, allowing the class to initialize member variables or allocate storage.

This constructor function is declared just like a regular member function, but with a name that matches the
class name and without any return type; not even void.

The Rectangle class above can easily be improved by implementing a constructor:*/

// example: class constructor
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle (int,int);
    int area () {return (width*height);}
};

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4);
  Rectangle rectb (5,6);
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}

/*The results of this example are identical to those of the previous example. But now, class Rectangle has no member
function set_values, and has instead a constructor that performs a similar action: it initializes the values of width
and height with the arguments passed to it.

Notice how these arguments are passed to the constructor at the moment at which the objects of this class are created:

Rectangle rect (3,4);
Rectangle rectb (5,6);

Constructors cannot be called explicitly as if they were regular member functions. They are only executed once, when
a new object of that class is created.

Notice how neither the constructor prototype declaration (within the class) nor the latter constructor definition,
have return values; not even void: Constructors never return values, they simply initialize the object.*/
