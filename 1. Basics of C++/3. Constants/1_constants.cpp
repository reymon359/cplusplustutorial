/* Constants are expressions with a fixed value.

LITERALS Literals are the most obvious kind of constants.
They are used to express particular values within the source code of a program.
Literal constants can be classified into: integer, floating-point, characters, strings, Boolean, pointers, and user-defined literals.


Here you have a list of the single character escape codes:

Escape code	Description
\n	newline
\r	carriage return
\t	tab
\v	vertical tab
\b	backspace
\f	form feed (page feed)
\a	alert (beep)
\'	single quote (')
\"	double quote (")
\?	question mark (?)
\\	backslash (\)



Some programmers also use a trick to include long string literals in multiple lines:
In C++, a backslash (\) at the end of line is considered a line-continuation character
that merges both that line and the next into a single line. Therefore the following code:

x = "string expressed in \
two lines"

is equivalent to:

x = "string expressed in two lines"

*/

/* Typed constant expressions
Sometimes, it is just convenient to give a name to a constant value.
We can then use these names instead of the literals they were defined to: */


#include <iostream>
using namespace std;

const double pi = 3.14159;
const char newline = '\n';

int main ()
{
  double r=5.0;               // radius
  double circle;

  circle = 2 * pi * r;
  cout << circle;
  cout << newline;
}

