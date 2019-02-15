/* Declaring functions
In C++, identifiers can only be used in expressions once they have been declared. For example,
some variable x cannot be used before being declared with a statement, such as:

int x;

The same applies to functions. Functions cannot be called before they are declared.
That is why, in all the previous examples of functions, the functions were always defined
before the main function, which is the function from where the other functions were called.
If main were defined before the other functions, this would break the rule that functions
shall be declared before being used, and thus would not compile.

The prototype of a function can be declared without actually defining the function completely,
giving just enough details to allow the types involved in a function call to be known. Naturally,
the function shall be defined somewhere else, like later in the code. But at least, once declared
like this, it can already be called.

The declaration shall include all types involved (the return type and the type of its arguments),
using the same syntax as used in the definition of the function, but replacing the body of the
function (the block of statements) with an ending semicolon.

The parameter list does not need to include the parameter names, but only their types. Parameter
names can nevertheless be specified, but they are optional, and do not need to necessarily match
those in the function definition. For example, a function called protofunction with two int
parameters can be declared with either of these statements:

int protofunction (int first, int second);
int protofunction (int, int);

Anyway, including a name for each parameter always improves legibility of the declaration.

// declaring functions prototypes
#include <iostream>
using namespace std;

void odd (int x);
void even (int x);

int main()
{
  int i;
  do {
    cout << "Please, enter number (0 to exit): ";
    cin >> i;
    odd (i);
  } while (i!=0);
  return 0;
}

void odd (int x)
{
  if ((x%2)!=0) cout << "It is odd.\n";
  else even (x);
}

void even (int x)
{
  if ((x%2)==0) cout << "It is even.\n";
  else odd (x);
}



This example is indeed not an example of efficiency. You can probably write yourself a
version of this program with half the lines of code. Anyway, this example illustrates
how functions can be declared before its definition:

The following lines:

void odd (int a);
void even (int a);


Declare the prototype of the functions. They already contain all what
is necessary to call them, their name, the types of their argument, and
their return type (void in this case). With these prototype declarations
in place, they can be called before they are entirely defined, allowing for
example, to place the function from where they are called (main) before the actual
definition of these functions.

But declaring functions before being defined is not only useful to reorganize the
order of functions within the code. In some cases, such as in this particular case,
at least one of the declarations is required, because odd and even are mutually called;
there is a call to even in odd and a call to odd in even. And, therefore, there is no
way to structure the code so that odd is defined before even, and even before odd.

Recursivity
Recursivity is the property that functions have to be called by themselves. It is
useful for some tasks, such as sorting elements, or calculating the factorial of
numbers. For example, in order to obtain the factorial of a number (n!) the mathematical
formula would be:

n! = n * (n-1) * (n-2) * (n-3) ... * 1
More concretely, 5! (factorial of 5) would be:

5! = 5 * 4 * 3 * 2 * 1 = 120
And a recursive function to calculate this in C++ could be:*/

// factorial calculator
#include <iostream>
using namespace std;

long factorial (long a)
{
  if (a > 1)
   return (a * factorial (a-1));
  else
   return 1;
}

int main ()
{
  long number = 8;
  cout << number << "! = " << factorial (number);
  return 0;
}
/*Notice how in function factorial we included a call to itself, but only if the argument
passed was greater than 1, since, otherwise, the function would perform an infinite recursive
loop, in which once it arrived to 0, it would continue multiplying by all the negative numbers
(probably provoking a stack overflow at some point during runtime).*/
