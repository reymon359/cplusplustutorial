/*using
The keyword using introduces a name into the current declarative region (such as a block),
thus avoiding the need to qualify the name. For example:

// using
#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int main () {
  using first::x;
  using second::y;
  cout << x << '\n';
  cout << y << '\n';
  cout << first::y << '\n';
  cout << second::x << '\n';
  return 0;
}

RESULT:
5
2.7183
10
3.1416

Notice how in main, the variable x (without any name qualifier) refers to first::x, whereas y
refers to second::y, just as specified by the using declarations. The variables first::y and
second::x can still be accessed, but require fully qualified names.

The keyword using can also be used as a directive to introduce an entire namespace:

// using
#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int main () {
  using namespace first;
  cout << x << '\n';
  cout << y << '\n';
  cout << second::x << '\n';
  cout << second::y << '\n';
  return 0;
}
RESULT:
5
10
3.1416
2.7183

In this case, by declaring that we were using namespace first, all direct uses of x and y without name
qualifiers were also looked up in namespace first.

using and using namespace have validity only in the same block in which they are stated or in the
entire source code file if they are used directly in the global scope. For example, it would be
possible to first use the objects of one namespace and then those of another one by splitting the code in different blocks:*/

// using namespace example
#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
}

namespace second
{
  double x = 3.1416;
}

int main () {
  {
    using namespace first;
    cout << x << '\n';
  }
  {
    using namespace second;
    cout << x << '\n';
  }
  return 0;
}


/*Namespace aliasing
Existing namespaces can be aliased with new names, with the following syntax:

namespace new_name = current_name;*/



/*
The std namespace
All the entities (variables, types, constants, and functions) of the standard C++ library are
declared within the std namespace. Most examples in these tutorials, in fact, include the following line:

using namespace std;

This introduces direct visibility of all the names of the std namespace into the code.
This is done in these tutorials to facilitate comprehension and shorten the length of the examples,
but many programmers prefer to qualify each of the elements of the standard library used in their
programs. For example, instead of:

cout << "Hello world!";

It is common to instead see:

std::cout << "Hello world!";

Whether the elements in the std namespace are introduced with using declarations or are fully qualified on
every use does not change the behavior or efficiency of the resulting program in any way. It is mostly a
matter of style preference, although for projects mixing libraries, explicit qualification tends to be preferred.*/
