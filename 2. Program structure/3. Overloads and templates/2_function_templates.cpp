/* Function templates
Overloaded functions may have the same definition. For example:

// overloaded functions
#include <iostream>
using namespace std;

int sum (int a, int b)
{
  return a+b;
}

double sum (double a, double b)
{
  return a+b;
}

int main ()
{
  cout << sum (10,20) << '\n';
  cout << sum (1.0,1.5) << '\n';
  return 0;
}

Here, sum is overloaded with different parameter types, but with the exact same body.

The function sum could be overloaded for a lot of types, and it could make sense for all of
them to have the same body. For cases such as this, C++ has the ability to define functions
with generic types, known as function templates. Defining a function template follows the
same syntax as a regular function, except that it is preceded by the template keyword and a
series of template parameters enclosed in angle-brackets <>:

template <template-parameters> function-declaration
The template parameters are a series of parameters separated by commas. These parameters can
be generic template types by specifying either the class or typename keyword followed by an
identifier. This identifier can then be used in the function declaration as if it was a regular
type. For example, a generic sum function could be defined as:

template <class SomeType>
SomeType sum (SomeType a, SomeType b)
{
  return a+b;
}

It makes no difference whether the generic type is specified with keyword class or keyword
typename in the template argument list (they are 100% synonyms in template declarations).

In the code above, declaring SomeType (a generic type within the template parameters enclosed
in angle-brackets) allows SomeType to be used anywhere in the function definition, just as any other
type; it can be used as the type for parameters, as return type, or to declare new variables of this
type. In all cases, it represents a generic type that will be determined on the moment the template
is instantiated.

Instantiating a template is applying the template to create a function using particular types or
values for its template parameters. This is done by calling the function template, with the same
syntax as calling a regular function, but specifying the template arguments enclosed in angle brackets:

name <template-arguments> (function-arguments)
For example, the sum function template defined above can be called with:

x = sum<int>(10,20);

The function sum<int> is just one of the possible instantiations of function template sum.
In this case, by using int as template argument in the call, the compiler automatically instantiates a
version of sum where each occurrence of SomeType is replaced by int, as if it was defined as:

int sum (int a, int b)
{
  return a+b;
}

Let's see an actual example: */

// function template
#include <iostream>
using namespace std;

template <class T>
T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}

int main () {
  int i=5, j=6, k;
  double f=2.0, g=0.5, h;
  k=sum<int>(i,j);
  h=sum<double>(f,g);
  cout << k << '\n';
  cout << h << '\n';
  return 0;
}


/*In this case, we have used T as the template parameter name, instead of SomeType. It makes no difference,
and T is actually a quite common template parameter name for generic types.

In the example above, we used the function template sum twice. The first time with arguments of type int,
and the second one with arguments of type double. The compiler has instantiated and then called each time
the appropriate version of the function.

Note also how T is also used to declare a local variable of that (generic) type within sum:

T result;

Therefore, result will be a variable of the same type as the parameters a and b, and as the type returned by the function.*/
