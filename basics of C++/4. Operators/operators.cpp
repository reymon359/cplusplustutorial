// assignment operator
#include <iostream>
using namespace std;

int main ()
{
  int a, b;         // a:?,  b:?
  a = 10;           // a:10, b:?
  b = 4;            // a:10, b:4
  a = b;            // a:4,  b:4
  b = 7;            // a:4,  b:7

  cout << "a:";
  cout << a;
  cout << " b:";
  cout << b;
}
/*
Assignment operations are expressions that can be evaluated. That means that the assignment itself has a value,
and -for fundamental types- this value is the one assigned in the operation. For example:

y = 2 + (x = 5);

In this expression, y is assigned the result of adding 2 and the value of another assignment expression
(which has itself a value of 5). It is roughly equivalent to:

x = 5;
y = 2 + x;

With the final result of assigning 7 to y.

The following expression is also valid in C++:

x = y = z = 5;

It assigns 5 to the all three variables: x, y and z; always from right-to-left. */

/* Arithmetic operators ( +, -, *, /, % )
The five arithmetical operations supported by C++ are:

operator	description
+	addition
-	subtraction
*	multiplication
/	division
%	modulo

Operations of addition, subtraction, multiplication and division correspond literally to their respective mathematical operators. The last one, modulo operator, represented by a percentage sign (%), gives the remainder of a division of two values. For example:

x = 11 % 3;

results in variable x containing the value 2, since dividing 11 by 3 results in 3, with a remainder of 2. */
