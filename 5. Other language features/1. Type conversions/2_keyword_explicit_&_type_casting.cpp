/*Keyword explicit
On a function call, C++ allows one implicit conversion to happen for each argument. This may be somewhat
problematic for classes, because it is not always what is intended. For example, if we add the following
function to the last example:

void fn (B arg) {}

This function takes an argument of type B, but it could as well be called with an object of type A as argument:

fn (foo);

This may or may not be what was intended. But, in any case, it can be prevented by marking the affected constructor
with the explicit keyword:

// explicit:
#include <iostream>
using namespace std;

class A {};

class B {
public:
  explicit B (const A& x) {}
  B& operator= (const A& x) {return *this;}
  operator A() {return A();}
};

void fn (B x) {}

int main ()
{
  A foo;
  B bar (foo);
  bar = foo;
  foo = bar;

//  fn (foo);  // not allowed for explicit ctor.
  fn (bar);

  return 0;
}

Additionally, constructors marked with explicit cannot be called with the assignment-like syntax; In the above example,
bar could not have been constructed with:

B bar = foo;

Type-cast member functions (those described in the previous section) can also be specified as explicit.
This prevents implicit conversions in the same way as explicit-specified constructors do for the destination type.

Type casting
C++ is a strong-typed language. Many conversions, specially those that imply a different interpretation of the value,
require an explicit conversion, known in C++ as type-casting. There exist two main syntaxes for generic type-casting: functional and c-like:

double x = 10.3;
int y;
y = int (x);    // functional notation
y = (int) x;    // c-like cast notation

The functionality of these generic forms of type-casting is enough for most needs with fundamental data types. However,
these operators can be applied indiscriminately on classes and pointers to classes, which can lead to code that -while
 being syntactically correct- can cause runtime errors. For example, the following code compiles without errors: */

// class type-casting
#include <iostream>
using namespace std;

class Dummy {
    double i,j;
};

class Addition {
    int x,y;
  public:
    Addition (int a, int b) { x=a; y=b; }
    int result() { return x+y;}
};

int main () {
  Dummy d;
  Addition * padd;
  padd = (Addition*) &d;
  cout << padd->result();
  return 0;
}
/*
The program declares a pointer to Addition, but then it assigns to it a reference to an object of another unrelated type
using explicit type-casting:

padd = (Addition*) &d;

Unrestricted explicit type-casting allows to convert any pointer into any other pointer type, independently of the types
they point to. The subsequent call to member result will produce either a run-time error or some other unexpected results.

In order to control these types of conversions between classes, we have four specific casting operators: dynamic_cast,
reinterpret_cast, static_cast and const_cast. Their format is to follow the new type enclosed between angle-brackets (<>)
and immediately after, the expression to be converted between parentheses.

dynamic_cast <new_type> (expression)
reinterpret_cast <new_type> (expression)
static_cast <new_type> (expression)
const_cast <new_type> (expression)

The traditional type-casting equivalents to these expressions would be:

(new_type) expression
new_type (expression)

but each one with its own special characteristics: */
