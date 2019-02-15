/*Arrays
An array is a series of elements of the same type placed in contiguous memory locations that can be
individually referenced by adding an index to a unique identifier.

That means that, for example, five values of type int can be declared as an array without having to
declare 5 different variables (each with its own identifier). Instead, using an array, the five int
values are stored in contiguous memory locations, and all five can be accessed using the same identifier, with the proper index.

For example, an array containing 5 integer values of type int called foo could be represented as:

where each blank panel represents an element of the array. In this case, these are values of type int.
These elements are numbered from 0 to 4, being 0 the first and 4 the last; In C++, the first element in
an array is always numbered with a zero (not a one), no matter its length.

Like a regular variable, an array must be declared before it is used. A typical declaration for an array in C++ is:

type name [elements];

where type is a valid type (such as int, float...), name is a valid identifier and the elements field
(which is always enclosed in square brackets []), specifies the length of the array in terms of the number of elements.

Therefore, the foo array, with five elements of type int, can be declared as:

int foo [5];

NOTE: The elements field within square brackets [], representing the number of elements in the array, must be
a constant expression, since arrays are blocks of static memory whose size must be determined at compile time, before the program runs.

Initializing arrays
By default, regular arrays of local scope (for example, those declared within a function) are left uninitialized.
This means that none of its elements are set to any particular value; their contents are undetermined at the point the array is declared.

But the elements in an array can be explicitly initialized to specific values when it is declared, by
enclosing those initial values in braces {}. For example:

int foo [5] = { 16, 2, 77, 40, 12071 };

This statement declares an array that can be represented like this:

The number of values between braces {} shall not be greater than the number of elements in the array.
For example, in the example above, foo was declared having 5 elements (as specified by the number enclosed
in square brackets, []), and the braces {} contained exactly 5 values, one for each element. If declared with less,
the remaining elements are set to their default values (which for fundamental types, means they are filled with zeroes). For example:

int bar [5] = { 10, 20, 30 };

Will create an array like this:

The initializer can even have no values, just the braces:

int baz [5] = { };

This creates an array of five int values, each initialized with a value of zero:

When an initialization of values is provided for an array, C++ allows the possibility of leaving the square brackets empty
[]. In this case, the compiler will assume automatically a size for the array that matches the number of values included between the braces {}:

int foo [] = { 16, 2, 77, 40, 12071 };

After this declaration, array foo would be 5 int long, since we have provided 5 initialization values.

Finally, the evolution of C++ has led to the adoption of universal initialization also for arrays. Therefore,
there is no longer need for the equal sign between the declaration and the initializer. Both these statements are equivalent:

int foo[] = { 10, 20, 30 };
int foo[] { 10, 20, 30 };

Static arrays, and those declared directly in a namespace (outside any function), are always initialized.
If no explicit initializer is specified, all the elements are default-initialized (with zeroes, for fundamental types).

Accessing the values of an array
The values of any of the elements in an array can be accessed just like the value of a regular variable of the same type. The syntax is:

name[index]
Following the previous examples in which foo had 5 elements and each of those elements was of type int,
the name which can be used to refer to each element is the following:

For example, the following statement stores the value 75 in the third element of foo:

foo [2] = 75;

and, for example, the following copies the value of the third element of foo to a variable called x:

x = foo[2];

Therefore, the expression foo[2] is itself a variable of type int.

Notice that the third element of foo is specified foo[2], since the first one is foo[0], the second one is foo[1], and
therefore, the third one is foo[2]. By this same reason, its last element is foo[4]. Therefore, if we write foo[5], we
would be accessing the sixth element of foo, and therefore actually exceeding the size of the array.

In C++, it is syntactically correct to exceed the valid range of indices for an array. This can create problems, since
accessing out-of-range elements do not cause errors on compilation, but can cause errors on runtime. The reason for this
being allowed will be seen in a later chapter when pointers are introduced.

At this point, it is important to be able to clearly distinguish between the two uses that brackets [] have related to
arrays. They perform two different tasks: one is to specify the size of arrays when they are declared; and the second one
is to specify indices for concrete array elements when they are accessed. Do not confuse these two possible uses of brackets [] with arrays.

int foo[5];         // declaration of a new array
foo[2] = 75;        // access to an element of the array.

The main difference is that the declaration is preceded by the type of the elements, while the access is not.

Some other valid operations with arrays:

foo[0] = a;
foo[a] = 75;
b = foo [a+2];
foo[foo[a]] = foo[2] + 5;


For example:*/

// arrays example
#include <iostream>
using namespace std;

int foo [] = {16, 2, 77, 40, 12071};
int n, result=0;

int main ()
{
  for ( n=0 ; n<5 ; ++n )
  {
    result += foo[n];
  }
  cout << result;
  return 0;
}

