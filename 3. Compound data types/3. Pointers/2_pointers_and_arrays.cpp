/*Pointers and arrays
The concept of arrays is related to that of pointers. In fact, arrays work very much like pointers to their first elements,
and, actually, an array can always be implicitly converted to the pointer of the proper type. For example, consider these two declarations:

int myarray [20];
int * mypointer;

The following assignment operation would be valid:

mypointer = myarray;

After that, mypointer and myarray would be equivalent and would have very similar properties. The main difference being
that mypointer can be assigned a different address, whereas myarray can never be assigned anything, and will always
represent the same block of 20 elements of type int. Therefore, the following assignment would not be valid:

myarray = mypointer;

Let's see an example that mixes arrays and pointers:*/

// more pointers
#include <iostream>
using namespace std;

int main ()
{
  int numbers[5];
  int * p;
  p = numbers;  *p = 10;
  p++;  *p = 20;
  p = &numbers[2];  *p = 30;
  p = numbers + 3;  *p = 40;
  p = numbers;  *(p+4) = 50;
  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";
  return 0;
}

/*Pointers and arrays support the same set of operations, with the same meaning for both. The main difference
being that pointers can be assigned new addresses, while arrays cannot.

In the chapter about arrays, brackets ([]) were explained as specifying the index of an element of the array.
Well, in fact these brackets are a dereferencing operator known as offset operator. They dereference the variable
they follow just as * does, but they also add the number between brackets to the address being dereferenced. For example:

a[5] = 0;       // a [offset of 5] = 0
*(a+5) = 0;     // pointed to by (a+5) = 0

These two expressions are equivalent and valid, not only if a is a pointer, but also if a is an array.
Remember that if an array, its name can be used just like a pointer to its first element.

Pointer initialization
Pointers can be initialized to point to specific locations at the very moment they are defined:

int myvar;
int * myptr = &myvar;

The resulting state of variables after this code is the same as after:

int myvar;
int * myptr;
myptr = &myvar;

When pointers are initialized, what is initialized is the address they point to (i.e., myptr),
never the value being pointed (i.e., *myptr). Therefore, the code above shall not be confused with:

int myvar;
int * myptr;
*myptr = &myvar;

Which anyway would not make much sense (and is not valid code).

The asterisk (*) in the pointer declaration (line 2) only indicates that it is a pointer, it is not the
dereference operator (as in line 3). Both things just happen to use the same sign: *. As always, spaces
are not relevant, and never change the meaning of an expression.

Pointers can be initialized either to the address of a variable (such as in the case above), or to the value of another pointer (or array):

int myvar;
int *foo = &myvar;
int *bar = foo;

Pointer arithmetics
To conduct arithmetical operations on pointers is a little different than to conduct them on regular integer
types. To begin with, only addition and subtraction operations are allowed; the others make no sense in the
world of pointers. But both addition and subtraction have a slightly different behavior with pointers, according
to the size of the data type to which they point.

When fundamental data types were introduced, we saw that types have different sizes. For example: char always has
a size of 1 byte, short is generally larger than that, and int and long are even larger; the exact size of these
being dependent on the system. For example, let's imagine that in a given system, char takes 1 byte, short takes 2 bytes, and long takes 4.

Suppose now that we define three pointers in this compiler:

char *mychar;
short *myshort;
long *mylong;

and that we know that they point to the memory locations 1000, 2000, and 3000, respectively.

Therefore, if we write:

++mychar;
++myshort;
++mylong;

mychar, as one would expect, would contain the value 1001. But not so obviously, myshort would contain
the value 2002, and mylong would contain 3004, even though they have each been incremented only once.
The reason is that, when adding one to a pointer, the pointer is made to point to the following element
of the same type, and, therefore, the size in bytes of the type it points to is added to the pointer.

This is applicable both when adding and subtracting any number to a pointer. It would happen exactly the same if we wrote:

mychar = mychar + 1;
myshort = myshort + 1;
mylong = mylong + 1;

Regarding the increment (++) and decrement (--) operators, they both can be used as either prefix or suffix of an
expression, with a slight difference in behavior: as a prefix, the increment happens before the expression is evaluated,
and as a suffix, the increment happens after the expression is evaluated. This also applies to expressions incrementing
and decrementing pointers, which can become part of more complicated expressions that also include dereference
operators (*). Remembering operator precedence rules, we can recall that postfix operators, such as increment
and decrement, have higher precedence than prefix operators, such as the dereference operator (*). Therefore, the following expression:

*p++

is equivalent to *(p++). And what it does is to increase the value of p (so it now points to the next element),
but because ++ is used as postfix, the whole expression is evaluated as the value pointed originally by the pointer
(the address it pointed to before being incremented).

Essentially, these are the four possible combinations of the dereference operator with both the prefix and suffix versions
of the increment operator (the same being applicable also to the decrement operator):

*p++   // same as *(p++): increment pointer, and dereference unincremented address
*++p   // same as *(++p): increment pointer, and dereference incremented address
++*p   // same as ++(*p): dereference pointer, and increment the value it points to
(*p)++ // dereference pointer, and post-increment the value it points to

A typical -but not so simple- statement involving these operators is:

*p++ = *q++;

Because ++ has a higher precedence than *, both p and q are incremented, but because both increment operators (++)
are used as postfix and not prefix, the value assigned to *p is *q before both p and q are incremented. And then both
are incremented. It would be roughly equivalent to:

*p = *q;
++p;
++q;

Like always, parentheses reduce confusion by adding legibility to expressions.*/
