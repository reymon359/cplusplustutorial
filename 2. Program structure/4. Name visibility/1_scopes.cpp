/* Scopes
Named entities, such as variables, functions, and compound types need to be declared before being used in C++.
The point in the program where this declaration happens influences its visibility:

An entity declared outside any block has global scope, meaning that its name is valid
anywhere in the code. While an entity declared within a block, such as a function or a
selective statement, has block scope, and is only visible within the specific block in which it
is declared, but not outside it.

Variables with block scope are known as local variables.

For example, a variable declared in the body of a function is a local variable that extends until
the end of the the function (i.e., until the brace } that closes the function definition), but not outside it:

int foo;        // global variable

int some_function ()
{
  int bar;      // local variable
  bar = 0;
}

int other_function ()
{
  foo = 1;  // ok: foo is a global variable
  bar = 2;  // wrong: bar is not visible from this function
}

In each scope, a name can only represent one entity. For example, there cannot be two
variables with the same name in the same scope:

int some_function ()
{
  int x;
  x = 0;
  double x;   // wrong: name already used in this scope
  x = 0.0;
}


The visibility of an entity with block scope extends until the end of the block, including
inner blocks. Nevertheless, an inner block, because it is a different block, can re-utilize a name
existing in an outer scope to refer to a different entity; in this case, the name will refer to a
different entity only within the inner block, hiding the entity it names outside.
While outside it, it will still refer to the original entity. For example: */

// inner block scopes
#include <iostream>
using namespace std;

int main () {
  int x = 10;
  int y = 20;
  {
    int x;   // ok, inner scope.
    x = 50;  // sets value to inner x
    y = 50;  // sets value to (outer) y
    cout << "inner block:\n";
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';
  }
  cout << "outer block:\n";
  cout << "x: " << x << '\n';
  cout << "y: " << y << '\n';
  return 0;
}


/*Note that y is not hidden in the inner block, and thus accessing y still accesses the outer variable.

Variables declared in declarations that introduce a block, such as function parameters and variables
declared in loops and conditions (such as those declared on a for or an if) are local to the block they introduce.*/
