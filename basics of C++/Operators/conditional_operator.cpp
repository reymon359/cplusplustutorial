/* Conditional ternary operator ( ? )
The conditional operator evaluates an expression, returning one value if that expression evaluates to true, and a different one if the expression evaluates as false. Its syntax is:

condition ? result1 : result2

If condition is true, the entire expression evaluates to result1, and otherwise to result2.

7==5 ? 4 : 3     // evaluates to 3, since 7 is not equal to 5.
7==5+2 ? 4 : 3   // evaluates to 4, since 7 is equal to 5+2.
5>3 ? a : b      // evaluates to the value of a, since 5 is greater than 3.
a>b ? a : b      // evaluates to whichever is greater, a or b.

For example: */

// conditional operator
#include <iostream>
using namespace std;

int main ()
{
  int a,b,c;

  a=2;
  b=7;
  c = (a>b) ? a : b;

  cout << c << '\n';
}

/*In this example, a was 2, and b was 7, so the expression being evaluated (a>b) was not true, thus the
first value specified after the question mark was discarded in favor of the second value (the one after
the colon) which was b (with a value of 7). */
