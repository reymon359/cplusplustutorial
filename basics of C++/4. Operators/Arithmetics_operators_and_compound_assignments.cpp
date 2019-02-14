/* Arithmetic operators ( +, -, *, /, % )
The five arithmetical operations supported by C++ are:

+	addition
-	subtraction
*	multiplication
/	division
%	modulo

Operations of addition, subtraction, multiplication and division correspond literally to their respective
mathematical operators. The last one, modulo operator, represented by a percentage sign (%), gives the
remainder of a division of two values. For example:

x = 11 % 3;

results in variable x containing the value 2, since dividing 11 by 3 results in 3, with a remainder of 2.*/

/* Compound assignment (+=, -=, *=, /=, %=, >>=, <<=, &=, ^=, |=)
Compound assignment operators modify the current value of a variable by performing an operation on it.
They are equivalent to assigning the result of an operation to the first operand:

expression	equivalent to...
y += x;	y = y + x;
x -= 5;	x = x - 5;
x /= y;	x = x / y;
price *= units + 1;	price = price * (units+1);

and the same for all other compound assignment operators. For example:*/

// compound assignment operators
#include <iostream>
using namespace std;

int main ()
{
  int a, b=3;
  a = b;
  a+=2;             // equivalent to a=a+2
  cout << a;
}
