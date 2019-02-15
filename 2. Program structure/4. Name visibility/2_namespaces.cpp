/*Namespaces
Only one entity can exist with a particular name in a particular scope. This is seldom a problem
for local names, since blocks tend to be relatively short, and names have particular purposes
    within them, such as naming a counter variable, an argument, etc...

But non-local names bring more possibilities for name collision, especially considering that
libraries may declare many functions, types, and variables, neither of them local in nature,
and some of them very generic.

Namespaces allow us to group named entities that otherwise would have global scope into narrower
scopes, giving them namespace scope. This allows organizing the elements of programs into
different logical scopes referred to by names.

The syntax to declare a namespaces is:

namespace identifier
{
  named_entities
}

Where identifier is any valid identifier and named_entities is the set of variables, types and functions
that are included within the namespace. For example:

namespace myNamespace
{
  int a, b;
}

In this case, the variables a and b are normal variables declared within a namespace called myNamespace.

These variables can be accessed from within their namespace normally, with their identifier
(either a or b), but if accessed from outside the myNamespace namespace they have to be properly
qualified with the scope operator ::. For example, to access the previous variables from outside
myNamespace they should be qualified like:

myNamespace::a
myNamespace::b


Namespaces are particularly useful to avoid name collisions. For example:*/

// namespaces
#include <iostream>
using namespace std;

namespace foo
{
  int value() { return 5; }
}

namespace bar
{
  const double pi = 3.1416;
  double value() { return 2*pi; }
}

int main () {
  cout << foo::value() << '\n';
  cout << bar::value() << '\n';
  cout << bar::pi << '\n';
  return 0;
}
/*In this case, there are two functions with the same name: value. One is defined within the namespace foo,
and the other one in bar. No redefinition errors happen thanks to namespaces. Notice also how pi is
accessed in an unqualified manner from within namespace bar (just as pi), while it is again accessed
in main, but here it needs to be qualified as bar::pi.

Namespaces can be split: Two segments of a code can be declared in the same namespace:

namespace foo { int a; }
namespace bar { int b; }
namespace foo { int c; }


This declares three variables: a and c are in namespace foo, while b is in namespace bar.
Namespaces can even extend across different translation units (i.e., across different files of source code).*/
