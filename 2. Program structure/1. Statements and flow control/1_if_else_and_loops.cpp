/* if (condition) statement

Here, condition is the expression that is being evaluated. If this condition is true, statement is executed. If it is false, statement is not executed (it is simply ignored), and the program continues right after the entire selection statement.
For example, the following code fragment prints the message (x is 100), only if the value stored in the x variable is indeed 100:

if (x == 100)
  cout << "x is 100";

If x is not exactly 100, this statement is ignored, and nothing is printed.

If you want to include more than a single statement to be executed when the condition is fulfilled, these statements shall be enclosed in braces ({}), forming a block:

if (x == 100)
{
   cout << "x is ";
   cout << x;
}

if (condition) statement1 else statement2

where statement1 is executed in case condition is true, and in case it is not, statement2 is executed.

For example:

if (x == 100)
  cout << "x is 100";
else
  cout << "x is not 100";

This prints x is 100, if indeed x has a value of 100, but if it does not, and only if it does not, it prints x is not 100 instead.
Several if + else structures can be concatenated with the intention of checking a range of values. For example:

if (x > 0)
  cout << "x is positive";
else if (x < 0)
  cout << "x is negative";
else
  cout << "x is 0";

The while loop
The simplest kind of loop is the while-loop. Its syntax is:

while (expression) statement

The while-loop simply repeats statement while expression is true. If, after any execution of statement, expression is no longer true, the loop ends, and the program continues right after the loop. For example, let's have a look at a countdown using a while-loop:
*/
// custom countdown using while
#include <iostream>
using namespace std;

int main ()
{
  int n = 10;

  while (n>0) {
    cout << n << ", ";
    --n;
  }

  cout << "liftoff!\n";
}
