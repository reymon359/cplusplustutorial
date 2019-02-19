/*Classes (I)
Classes are an expanded concept of data structures: like data structures, they can contain data members,
but they can also contain functions as members.

An object is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable.

Classes are defined using either keyword class or keyword struct, with the following syntax:

class class_name {
  access_specifier_1:
    member1;
  access_specifier_2:
    member2;
  ...
} object_names;

Where class_name is a valid identifier for the class, object_names is an optional list of names for objects
of this class. The body of the declaration can contain members, which can either be data or function declarations,
and optionally access specifiers.

Classes have the same format as plain data structures, except that they can also include functions and have
these new things called access specifiers. An access specifier is one of the following three keywords: private,
public or protected. These specifiers modify the access rights for the members that follow them:

private members of a class are accessible only from within other members of the same class (or from their "friends").
protected members are accessible from other members of the same class (or from their "friends"), but also
from members of their derived classes.
Finally, public members are accessible from anywhere where the object is visible.

By default, all members of a class declared with the class keyword have private access for all its members.
Therefore, any member that is declared before any other access specifier has private access automatically. For example:

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area (void);
} rect;

Declares a class (i.e., a type) called Rectangle and an object (i.e., a variable) of this class, called rect.
This class contains four members: two data members of type int (member width and member height) with private
access (because private is the default access level) and two member functions with public access: the functions
set_values and area, of which for now we have only included their declaration, but not their definition.

Notice the difference between the class name and the object name: In the previous example, Rectangle was the
class name (i.e., the type), whereas rect was an object of type Rectangle. It is the same relationship int and
a have in the following declaration:

int a;

where int is the type name (the class) and a is the variable name (the object).

After the declarations of Rectangle and rect, any of the public members of object rect can be accessed as if
they were normal functions or normal variables, by simply inserting a dot (.) between object name and member name.
This follows the same syntax as accessing the members of plain data structures. For example:

rect.set_values (3,4);
myarea = rect.area();

The only members of rect that cannot be accessed from outside the class are width and height, since they
have private access and they can only be referred to from within other members of that same class.

Here is the complete example of class Rectangle:

// classes example
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area() {return width*height;}
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Rectangle rect;
  rect.set_values (3,4);
  cout << "area: " << rect.area();
  return 0;
}
OUTPUT
area: 12

This example reintroduces the scope operator (::, two colons), seen in earlier chapters in relation to namespaces. Here
it is used in the definition of function set_values to define a member of a class outside the class itself.

Notice that the definition of the member function area has been included directly within the definition of class Rectangle
given its extreme simplicity. Conversely, set_values it is merely declared with its prototype within the class, but its
definition is outside it. In this outside definition, the operator of scope (::) is used to specify that the function being
defined is a member of the class Rectangle and not a regular non-member function.

The scope operator (::) specifies the class to which the member being defined belongs, granting exactly the same scope
properties as if this function definition was directly included within the class definition. For example, the function
set_values in the previous example has access to the variables width and height, which are private members of class Rectangle,
and thus only accessible from other members of the class, such as this.

The only difference between defining a member function completely within the class definition or to just include its declaration
in the function and define it later outside the class, is that in the first case the function is automatically considered an
inline member function by the compiler, while in the second it is a normal (not-inline) class member function. This causes
no differences in behavior, but only on possible compiler optimizations.

Members width and height have private access (remember that if nothing else is specified, all members of a class defined
with keyword class have private access). By declaring them private, access from outside the class is not allowed. This makes
sense, since we have already defined a member function to set values for those members within the object: the member function
set_values. Therefore, the rest of the program does not need to have direct access to them. Perhaps in a so simple example as
this, it is difficult to see how restricting access to these variables may be useful, but in greater projects it may be very
important that values cannot be modified in an unexpected way (unexpected from the point of view of the object).

The most important property of a class is that it is a type, and as such, we can declare multiple objects of it.
For example, following with the previous example of class Rectangle, we could have declared the object rectb in addition to object rect:*/

// example: one class, two objects
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area () {return width*height;}
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Rectangle rect, rectb;
  rect.set_values (3,4);
  rectb.set_values (5,6);
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}
/*In this particular case, the class (type of the objects) is Rectangle, of which there are two instances (i.e., objects): rect and rectb.
Each one of them has its own member variables and member functions.

Notice that the call to rect.area() does not give the same result as the call to rectb.area().
This is because each object of class Rectangle has its own variables width and height, as they -in some way-
have also their own function members set_value and area that operate on the object's own member variables.

Classes allow programming using object-oriented paradigms: Data and functions are both members of the object,
reducing the need to pass and carry handlers or other state variables as arguments to functions, because they
are part of the object whose member is called. Notice that no arguments were passed on the calls to rect.area
or rectb.area. Those member functions directly used the data members of their respective objects rect and rectb.*/
