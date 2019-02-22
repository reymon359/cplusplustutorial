/*typeid
typeid allows to check the type of an expression:

typeid (expression)

This operator returns a reference to a constant object of type type_info that is defined in the standard header
<typeinfo>. A value returned by typeid can be compared with another value returned by typeid using operators ==
and != or can serve to obtain a null-terminated character sequence representing the data type or class name by using its name() member.

// typeid
#include <iostream>
#include <typeinfo>
using namespace std;

int main () {
  int * a,b;
  a=0; b=0;
  if (typeid(a) != typeid(b))
  {
    cout << "a and b are of different types:\n";
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
  }
  return 0;
}
// OUTPUT
a and b are of different types:
a is: int *
b is: int

When typeid is applied to classes, typeid uses the RTTI to keep track of the type of dynamic objects.
When typeid is applied to an expression whose type is a polymorphic class, the result is the type of
the most derived complete object:*/

// typeid, polymorphic class
#include <iostream>
#include <typeinfo>
#include <exception>
using namespace std;

class Base { virtual void f(){} };
class Derived : public Base {};

int main () {
  try {
    Base* a = new Base;
    Base* b = new Derived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
  } catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
  return 0;
}
/* Note: The string returned by member name of type_info depends on the specific implementation of your
compiler and library. It is not necessarily a simple string with its typical type name, like in the compiler
used to produce this output.

Notice how the type that typeid considers for pointers is the pointer type itself (both a and b are of type class Base *).
However, when typeid is applied to objects (like *a and *b) typeid yields their dynamic type (i.e. the type of their most
derived complete object).

If the type typeid evaluates is a pointer preceded by the dereference operator (*), and this pointer has a null value,
typeid throws a bad_typeid exception.*/
