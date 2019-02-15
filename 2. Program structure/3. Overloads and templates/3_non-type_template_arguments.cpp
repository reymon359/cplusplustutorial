/* Non-type template arguments
The template parameters can not only include types introduced by class or typename,
but can also include expressions of a particular type: */

// template arguments
#include <iostream>
using namespace std;

template <class T, int N>
T fixed_multiply (T val)
{
  return val * N;
}

int main() {
  std::cout << fixed_multiply<int,2>(10) << '\n';
  std::cout << fixed_multiply<int,3>(10) << '\n';
}
/*The second argument of the fixed_multiply function template is of type int. It just looks like a
regular function parameter, and can actually be used just like one.

But there exists a major difference: the value of template parameters is determined on compile-time
to generate a different instantiation of the function fixed_multiply, and thus the value of that
argument is never passed during runtime: The two calls to fixed_multiply in main essentially call
two versions of the function: one that always multiplies by two, and one that always multiplies by
three. For that same reason, the second template argument needs to be a constant expression (it cannot be passed a variable).*/
