/*Overloading constructors
Like any other function, a constructor can also be overloaded with different versions taking different
parameters: with a different number of parameters and/or parameters of different types. The compiler
will automatically call the one whose parameters match the arguments:*/

// overloading class constructors
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle ();
    Rectangle (int,int);
    int area (void) {return (width*height);}
};

Rectangle::Rectangle () {
  width = 5;
  height = 5;
}

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4);
  Rectangle rectb;
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}

/*In the above example, two objects of class Rectangle are constructed: rect and rectb. rect is constructed
with two arguments, like in the example before.

But this example also introduces a special kind constructor: the default constructor. The default constructor
is the constructor that takes no parameters, and it is special because it is called when an object is declared
but is not initialized with any arguments. In the example above, the default constructor is called for rectb.
Note how rectb is not even constructed with an empty set of parentheses - in fact, empty parentheses cannot be
used to call the default constructor:

Rectangle rectb;   // ok, default constructor called
Rectangle rectc(); // oops, default constructor NOT called

This is because the empty set of parentheses would make of rectc a function declaration instead of an object
declaration: It would be a function that takes no arguments and returns a value of type Rectangle.*/
