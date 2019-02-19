/*Pointers to classes
Objects can also be pointed to by pointers: Once declared, a class becomes a valid type, so it can be used as the
type pointed to by a pointer. For example:

Rectangle * prect;

is a pointer to an object of class Rectangle.

Similarly as with plain data structures, the members of an object can be accessed directly from a pointer by
using the arrow operator (->). Here is an example with some possible combinations:*/

// pointer to classes example
#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public:
  Rectangle(int x, int y) : width(x), height(y) {}
  int area(void) { return width * height; }
};


int main() {
  Rectangle obj (3, 4);
  Rectangle * foo, * bar, * baz;
  foo = &obj;
  bar = new Rectangle (5, 6);
  baz = new Rectangle[2] { {2,5}, {3,6} };
  cout << "obj's area: " << obj.area() << '\n';
  cout << "*foo's area: " << foo->area() << '\n';
  cout << "*bar's area: " << bar->area() << '\n';
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';
  delete bar;
  delete[] baz;
  return 0;
}


/*  This example makes use of several operators to operate on objects and pointers (operators *, &, ., ->, []).
They can be interpreted as:

expression	can be read as
*x	pointed to by x
&x	address of x
x.y	member y of object x
x->y	member y of object pointed to by x
(*x).y	member y of object pointed to by x (equivalent to the previous one)
x[0]	first object pointed to by x
x[1]	second object pointed to by x
x[n]	(n+1)th object pointed to by x

Most of these expressions have been introduced in earlier chapters. Most notably, the chapter about arrays
introduced the offset operator ([]) and the chapter about plain data structures introduced the arrow operator (->).

Classes defined with struct and union
Classes can be defined not only with keyword class, but also with keywords struct and union.

The keyword struct, generally used to declare plain data structures, can also be used to declare classes that
have member functions, with the same syntax as with keyword class. The only difference between both is that members
of classes declared with the keyword struct have public access by default, while members of classes declared with
the keyword class have private access by default. For all other purposes both keywords are equivalent in this context.

Conversely, the concept of unions is different from that of classes declared with struct and class, since unions
only store one data member at a time, but nevertheless they are also classes and can thus also hold member functions.
The default access in union classes is public.*/
