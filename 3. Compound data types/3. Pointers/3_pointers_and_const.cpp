/*Pointers and const
Pointers can be used to access a variable by its address, and this access may include modifying the value pointed.
But it is also possible to declare pointers that can access the pointed value to read it, but not to modify it.
For this, it is enough with qualifying the type pointed to by the pointer as const. For example:

int x;
int y = 10;
const int * p = &y;
x = *p;          // ok: reading p
*p = x;          // error: modifying p, which is const-qualified

Here p points to a variable, but points to it in a const-qualified manner, meaning that it can read the
value pointed, but it cannot modify it. Note also, that the expression &y is of type int*, but this is
assigned to a pointer of type const int*. This is allowed: a pointer to non-const can be implicitly converted
to a pointer to const. But not the other way around! As a safety feature, pointers to const are not implicitly
convertible to pointers to non-const.

One of the use cases of pointers to const elements is as function parameters: a function that takes a pointer
to non-const as parameter can modify the value passed as argument, while a function that takes a pointer to const as parameter cannot.*/

// pointers as arguments:
#include <iostream>
using namespace std;

void increment_all (int* start, int* stop)
{
  int * current = start;
  while (current != stop) {
    ++(*current);  // increment value pointed
    ++current;     // increment pointer
  }
}

void print_all (const int* start, const int* stop)
{
  const int * current = start;
  while (current != stop) {
    cout << *current << '\n';
    ++current;     // increment pointer
  }
}

int main ()
{
  int numbers[] = {10,20,30};
  increment_all (numbers,numbers+3);
  print_all (numbers,numbers+3);
  return 0;
}
/*Note that print_all uses pointers that point to constant elements. These pointers point to constant content they cannot modify,
but they are not constant themselves: i.e., the pointers can still be incremented or assigned different addresses, although they
cannot modify the content they point to.

And this is where a second dimension to constness is added to pointers: Pointers can also be themselves const. And this is specified
by appending const to the pointed type (after the asterisk):

int x;
      int *       p1 = &x;  // non-const pointer to non-const int
const int *       p2 = &x;  // non-const pointer to const int
      int * const p3 = &x;  // const pointer to non-const int
const int * const p4 = &x;  // const pointer to const int


The syntax with const and pointers is definitely tricky, and recognizing the cases that best suit each use tends to require some experience.
In any case, it is important to get constness with pointers (and references) right sooner rather than later, but you should not worry too
much about grasping everything if this is the first time you are exposed to the mix of const and pointers. More use cases will show up in
coming chapters.

To add a little bit more confusion to the syntax of const with pointers, the const qualifier can either precede or follow the pointed
type, with the exact same meaning:

const int * p2a = &x;  //      non-const pointer to const int
int const * p2b = &x;  // also non-const pointer to const int

As with the spaces surrounding the asterisk, the order of const in this case is simply a matter of style. This chapter uses a prefix const,
as for historical reasons this seems to be more extended, but both are exactly equivalent. The merits of each style are still intensely debated
on the internet.

Pointers and string literals
As pointed earlier, string literals are arrays containing null-terminated character sequences. In earlier sections, string literals have been
used to be directly inserted into cout, to initialize strings and to initialize arrays of characters.

But they can also be accessed directly. String literals are arrays of the proper array type to contain all its characters
plus the terminating null-character, with each of the elements being of type const char (as literals, they can never be modified). For example:

const char * foo = "hello";

This declares an array with the literal representation for "hello", and then a pointer to its first element is assigned to foo. If we imagine that
"hello" is stored at the memory locations that start at address 1702, we can represent the previous declaration as:

Note that here foo is a pointer and contains the value 1702, and not 'h', nor "hello", although 1702 indeed is the address of both of these.

The pointer foo points to a sequence of characters. And because pointers and arrays behave essentially in the same way in expressions, foo
can be used to access the characters in the same way arrays of null-terminated character sequences are. For example:

*(foo+4)
foo[4]

Both expressions have a value of 'o' (the fifth element of the array).

Pointers to pointers
C++ allows the use of pointers that point to pointers, that these, in its turn, point to data (or even to other pointers).
The syntax simply requires an asterisk (*) for each level of indirection in the declaration of the pointer:

char a;
char * b;
char ** c;
a = 'z';
b = &a;
c = &b;


This, assuming the randomly chosen memory locations for each variable of 7230, 8092, and 10502, could be represented as:


With the value of each variable represented inside its corresponding cell, and their respective addresses in memory represented
by the value under them.

The new thing in this example is variable c, which is a pointer to a pointer, and can be used in three different levels of
indirection, each one of them would correspond to a different value:

c is of type char** and a value of 8092
*c is of type char* and a value of 7230
**c is of type char and a value of 'z'*/
