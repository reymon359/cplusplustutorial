/*Multidimensional arrays
Multidimensional arrays can be described as "arrays of arrays". For example, a bidimensional array can be
imagined as a two-dimensional table made of elements, all of them of a same uniform data type.

jimmy represents a bidimensional array of 3 per 5 elements of type int. The C++ syntax for this is:

int jimmy [3][5];

and, for example, the way to reference the second element vertically and fourth horizontally in an expression would be:

jimmy[1][3]

(remember that array indices always begin with zero).

Multidimensional arrays are not limited to two indices (i.e., two dimensions). They can contain as many indices as needed.
Although be careful: the amount of memory needed for an array increases exponentially with each dimension. For example:

char century [100][365][24][60][60];

declares an array with an element of type char for each second in a century. This amounts to more than 3 billion char!
So this declaration would consume more than 3 gigabytes of memory!

At the end, multidimensional arrays are just an abstraction for programmers, since the same results can be achieved with a
simple array, by multiplying its indices:

int jimmy [3][5];   // is equivalent to
int jimmy [15];     // (3 * 5 = 15)


With the only difference that with multidimensional arrays, the compiler automatically remembers the depth of each imaginary
dimension. The following two pieces of code produce the exact same result, but one uses a bidimensional array while the other
uses a simple array:

multidimensional array	pseudo-multidimensional array
#define WIDTH 5
#define HEIGHT 3

int jimmy [HEIGHT][WIDTH];
int n,m;

int main ()
{
  for (n=0; n<HEIGHT; n++)
    for (m=0; m<WIDTH; m++)
    {
      jimmy[n][m]=(n+1)*(m+1);
    }
}
#define WIDTH 5
#define HEIGHT 3

int jimmy [HEIGHT * WIDTH];
int n,m;

int main ()
{
  for (n=0; n<HEIGHT; n++)
    for (m=0; m<WIDTH; m++)
    {
      jimmy[n*WIDTH+m]=(n+1)*(m+1);
    }
}

None of the two code snippets above produce any output on the screen, but both assign values to the memory block
called jimmy in the following way:

Note that the code uses defined constants for the width and height, instead of using directly their numerical
values. This gives the code a better readability, and allows changes in the code to be made easily in one place.

Arrays as parameters
At some point, we may need to pass an array to a function as a parameter. In C++, it is not possible to pass the
entire block of memory represented by an array to a function directly as an argument. But what can be passed instead
is its address. In practice, this has almost the same effect, and it is a much faster and more efficient operation.

To accept an array as parameter for a function, the parameters can be declared as the array type, but with empty
brackets, omitting the actual size of the array. For example:

void procedure (int arg[])

This function accepts a parameter of type "array of int" called arg. In order to pass to this function an array declared as:

int myarray [40];

it would be enough to write a call like this:

procedure (myarray);

Here you have a complete example: */

// arrays as parameters
#include <iostream>
using namespace std;

void printarray (int arg[], int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

int main ()
{
  int firstarray[] = {5, 10, 15};
  int secondarray[] = {2, 4, 6, 8, 10};
  printarray (firstarray,3);
  printarray (secondarray,5);
}

/*In the code above, the first parameter (int arg[]) accepts any array whose elements are of type int, whatever its length.
For that reason, we have included a second parameter that tells the function the length of each array that we pass to it as
its first parameter. This allows the for loop that prints out the array to know the range to iterate in the array passed,
without going out of range.

In a function declaration, it is also possible to include multidimensional arrays. The format for a tridimensional array parameter is:

base_type[][depth][depth]

For example, a function with a multidimensional array as argument could be:

void procedure (int myarray[][3][4])

Notice that the first brackets [] are left empty, while the following ones specify sizes for their respective dimensions.
This is necessary in order for the compiler to be able to determine the depth of each additional dimension.

In a way, passing an array as argument always loses a dimension. The reason behind is that, for historical reasons, arrays
cannot be directly copied, and thus what is really passed is a pointer. This is a common source of errors for novice programmers.
Although a clear understanding of pointers, explained in a coming chapter, helps a lot.

Library arrays
The arrays explained above are directly implemented as a language feature, inherited from the C language. They are a great
feature, but by restricting its copy and easily decay into pointers, they probably suffer from an excess of optimization.

To overcome some of these issues with language built-in arrays, C++ provides an alternative array type as a standard container.
It is a type template (a class template, in fact) defined in header <array>.

Containers are a library feature that falls out of the scope of this tutorial, and thus the class will not be explained in
detail here. Suffice it to say that they operate in a similar way to built-in arrays, except that they allow being copied
(an actually expensive operation that copies the entire block of memory, and thus to use with care) and decay into pointers
only when explicitly told to do so (by means of its member data).

Just as an example, these are two versions of the same example using the language built-in array described in this chapter,
and the container in the library:

language built-in array
#include <iostream>

using namespace std;

int main()
{
  int myarray[3] = {10,20,30};

  for (int i=0; i<3; ++i)
    ++myarray[i];

  for (int elem : myarray)
    cout << elem << '\n';
}

container library array
#include <iostream>
#include <array>
using namespace std;

int main()
{
  array<int,3> myarray {10,20,30};

  for (int i=0; i<myarray.size(); ++i)
    ++myarray[i];

  for (int elem : myarray)
    cout << elem << '\n';
}

As you can see, both kinds of arrays use the same syntax to access its elements: myarray[i].
Other than that, the main differences lay on the declaration of the array, and the inclusion
of an additional header for the library array. Notice also how it is easy to access the size of the library array.*/
