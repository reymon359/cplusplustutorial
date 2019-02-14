/* The for loop is designed to iterate a number of times. Its syntax is:

for (initialization; condition; increase) statement;

Like the while-loop, this loop repeats statement while condition is true. But, in addition, the for loop provides specific locations to contain an initialization and an increase expression, executed before the loop begins the first time, and after each iteration, respectively. Therefore, it is especially useful to use counter variables as condition.

It works in the following way:

initialization is executed. Generally, this declares a counter variable, and sets it to some initial value. This is executed a single time, at the beginning of the loop.
condition is checked. If it is true, the loop continues; otherwise, the loop ends, and statement is skipped, going directly to step 5.
statement is executed. As usual, it can be either a single statement or a block enclosed in curly braces { }.
increase is executed, and the loop gets back to step 2.
the loop ends: execution continues by the next statement after it.

Here is the countdown example using a for loop:*/

// countdown using a for loop
#include <iostream>
using namespace std;

int main ()
{
  for (int n=10; n>0; n--) {
    cout << n << ", ";
  }
  cout << "liftoff!\n";
}

/*
Range-based for loop
The for-loop has another syntax, which is used exclusively with ranges:

for ( declaration : range ) statement;

This kind of for loop iterates over all the elements in range, where declaration
declares some variable able to take the value of an element in this range. Ranges
are sequences of elements, including arrays, containers, and any other type supporting
the functions begin and end; Most of these types have not yet been introduced in this
tutorial, but we are already acquainted with at least one kind of range: strings, which are sequences of characters.

An example of range-based for loop using strings:

// range-based for loop
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string str {"Hello!"};
  for (char c : str)
  {
    cout << "[" << c << "]";
  }
  cout << '\n';
}
*/
/*
The syntax of the switch statement is a bit peculiar. Its purpose is to check for a value among a number of possible constant
expressions. It is something similar to concatenating if-else statements, but limited to constant expressions. Its most typical syntax is:

switch (expression)
{
  case constant1:
     group-of-statements-1;
     break;
  case constant2:
     group-of-statements-2;
     break;
  .
  .
  .
  default:
     default-group-of-statements
}

It works in the following way: switch evaluates expression and checks if it is equivalent to constant1; if it is,
it executes group-of-statements-1 until it finds the break statement. When it finds this break statement, the program
jumps to the end of the entire switch statement (the closing brace). */
