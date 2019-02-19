/*Uniform initialization
The way of calling constructors by enclosing their arguments in parentheses, as shown above,
is known as functional form. But constructors can also be called with other syntaxes:

First, constructors with a single parameter can be called using the variable initialization
syntax (an equal sign followed by the argument):

class_name object_name = initialization_value;

More recently, C++ introduced the possibility of constructors to be called using uniform initialization,
which essentially is the same as the functional form, but using braces ({}) instead of parentheses (()):

class_name object_name { value, value, value, ... }

Optionally, this last syntax can include an equal sign before the braces.

Here is an example with four ways to construct objects of a class whose constructor takes a single parameter:*/

// classes and uniform initialization
#include <iostream>
using namespace std;

class Circle {
    double radius;
  public:
    Circle(double r) { radius = r; }
    double circum() {return 2*radius*3.14159265;}
};

int main () {
  Circle foo (10.0);   // functional form
  Circle bar = 20.0;   // assignment init.
  Circle baz {30.0};   // uniform init.
  Circle qux = {40.0}; // POD-like

  cout << "foo's circumference: " << foo.circum() << '\n';
  return 0;
}
/*
An advantage of uniform initialization over functional form is that, unlike parentheses, braces cannot be
confused with function declarations, and thus can be used to explicitly call default constructors:

Rectangle rectb;   // default constructor called
Rectangle rectc(); // function declaration (default constructor NOT called)
Rectangle rectd{}; // default constructor called

The choice of syntax to call constructors is largely a matter of style. Most existing code currently uses
functional form, and some newer style guides suggest to choose uniform initialization over the others, even
though it also has its potential pitfalls for its preference of initializer_list as its type.*/
