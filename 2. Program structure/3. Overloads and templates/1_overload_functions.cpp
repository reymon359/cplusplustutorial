/* Overloaded functions
In C++, two different functions can have the same name if their parameters are different;
either because they have a different number of parameters, or because any of their parameters
are of a different type. For example: */

// overloading functions
#include <iostream>
using namespace std;

int operate (int a, int b)
{
  return (a*b);
}

double operate (double a, double b)
{
  return (a/b);
}

int main ()
{
  int x=5,y=2;
  double n=5.0,m=2.0;
  cout << operate (x,y) << '\n';
  cout << operate (n,m) << '\n';
  return 0;
}
/*
In this example, there are two functions called operate, but one of them has two parameters of type int,
while the other has them of type double. The compiler knows which one to call in each case by examining
    the types passed as arguments when the function is called. If it is called with two int arguments,
    it calls to the function that has two int parameters, and if it is called with two doubles, it calls the one with two doubles.

In this example, both functions have quite different behaviors, the int version multiplies its arguments,
while the double version divides them. This is generally not a good idea. Two functions with the same name
are generally expected to have -at least- a similar behavior, but this example demonstrates that is entirely
possible for them not to. Two overloaded functions (i.e., two functions with the same name) have entirely
different definitions; they are, for all purposes, different functions, that only happen to have the same name.

Note that a function cannot be overloaded only by its return type. At least one of its parameters must have a different type.*/
