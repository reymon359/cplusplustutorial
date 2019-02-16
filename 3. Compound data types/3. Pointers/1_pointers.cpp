/*Pointers
In earlier chapters, variables have been explained as locations in the computer's memory which can be accessed by
their identifier (their name). This way, the program does not need to care about the physical address of the data
in memory; it simply uses the identifier whenever it needs to refer to the variable.

For a C++ program, the memory of a computer is like a succession of memory cells, each one byte in size, and each
with a unique address. These single-byte memory cells are ordered in a way that allows data representations larger
than one byte to occupy memory cells that have consecutive addresses.

This way, each cell can be easily located in the memory by means of its unique address. For example, the memory
cell with the address 1776 always follows immediately after the cell with address 1775 and precedes the one with
1777, and is exactly one thousand cells after 776 and exactly one thousand cells before 2776.

When a variable is declared, the memory needed to store its value is assigned a specific location in memory (its
memory address). Generally, C++ programs do not actively decide the exact memory addresses where its variables
are stored. Fortunately, that task is left to the environment where the program is run - generally, an operating
system that decides the particular memory locations on runtime. However, it may be useful for a program to be able
to obtain the address of a variable during runtime in order to access data cells that are at a certain position relative to it.

Address-of operator (&)
The address of a variable can be obtained by preceding the name of a variable with an ampersand sign (&), known
as address-of operator. For example:

foo = &myvar;

This would assign the address of variable myvar to foo; by preceding the name of the variable myvar
with the address-of operator (&), we are no longer assigning the content of the variable itself to foo, but its address.

The actual address of a variable in memory cannot be known before runtime, but let's assume, in order to
help clarify some concepts, that myvar is placed during runtime in the memory address 1776.

In this case, consider the following code fragment:

myvar = 25;
foo = &myvar;
bar = myvar;

The values contained in each variable after the execution of this are shown in the following diagram:

First, we have assigned the value 25 to myvar (a variable whose address in memory we assumed to be 1776).

The second statement assigns foo the address of myvar, which we have assumed to be 1776.

Finally, the third statement, assigns the value contained in myvar to bar. This is a standard assignment
operation, as already done many times in earlier chapters.

The main difference between the second and third statements is the appearance of the address-of operator (&).

The variable that stores the address of another variable (like foo in the previous example) is what in C++
is called a pointer. Pointers are a very powerful feature of the language that has many uses in lower level
programming. A bit later, we will see how to declare and use pointers.

Dereference operator (*)
As just seen, a variable which stores the address of another variable is called a pointer. Pointers are said
to "point to" the variable whose address they store.

An interesting property of pointers is that they can be used to access the variable they point to directly.
This is done by preceding the pointer name with the dereference operator (*). The operator itself can be read as "value pointed to by".

Therefore, following with the values of the previous example, the following statement:

baz = *foo;

This could be read as: "baz equal to value pointed to by foo", and the statement would actually assign the value
25 to baz, since foo is 1776, and the value pointed to by 1776 (following the example above) would be 25.

It is important to clearly differentiate that foo refers to the value 1776, while *foo (with an asterisk *
preceding the identifier) refers to the value stored at address 1776, which in this case is 25. Notice the
difference of including or not including the dereference operator (I have added an explanatory comment of
how each of these two expressions could be read):

baz = foo;   // baz equal to foo (1776)
baz = *foo;  // baz equal to value pointed to by foo (25)

The reference and dereference operators are thus complementary:
& is the address-of operator, and can be read simply as "address of"
* is the dereference operator, and can be read as "value pointed to by"

Thus, they have sort of opposite meanings: An address obtained with & can be dereferenced with *.

Earlier, we performed the following two assignment operations:

myvar = 25;
foo = &myvar;

Right after these two statements, all of the following expressions would give true as result:

myvar == 25
&myvar == 1776
foo == 1776
*foo == 25


The first expression is quite clear, considering that the assignment operation performed on myvar
was myvar=25. The second one uses the address-of operator (&), which returns the address of myvar,
which we assumed it to have a value of 1776. The third one is somewhat obvious, since the second
expression was true and the assignment operation performed on foo was foo=&myvar. The fourth expression
uses the dereference operator (*) that can be read as "value pointed to by", and the value pointed to by foo is indeed 25.

So, after all that, you may also infer that for as long as the address pointed to by foo remains
unchanged, the following expression will also be true:

*foo == myvar

Declaring pointers
Due to the ability of a pointer to directly refer to the value that it points to, a pointer
has different properties when it points to a char than when it points to an int or a float.
Once dereferenced, the type needs to be known. And for that, the declaration of a pointer needs
to include the data type the pointer is going to point to.

The declaration of pointers follows this syntax:

type * name;

where type is the data type pointed to by the pointer. This type is not the type of the pointer itself,
but the type of the data the pointer points to. For example:

int * number;
char * character;
double * decimals;

These are three declarations of pointers. Each one is intended to point to a different data type,
but, in fact, all of them are pointers and all of them are likely going to occupy the same amount
of space in memory (the size in memory of a pointer depends on the platform where the program runs).
Nevertheless, the data to which they point to do not occupy the same amount of space nor are of the
same type: the first one points to an int, the second one to a char, and the last one to a double.
Therefore, although these three example variables are all of them pointers, they actually have different
types: int*, char*, and double* respectively, depending on the type they point to.

Note that the asterisk (*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier), and should not be confused with the dereference operator seen a bit earlier, but which is also written with an asterisk (*). They are simply two different things represented with the same sign.

Let's see an example on pointers:

// my first pointer
#include <iostream>
using namespace std;

int main ()
{
  int firstvalue, secondvalue;
  int * mypointer;

  mypointer = &firstvalue;
  *mypointer = 10;
  mypointer = &secondvalue;
  *mypointer = 20;
  cout << "firstvalue is " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';
  return 0;
}
RESULT:
firstvalue is 10
secondvalue is 20

Notice that even though neither firstvalue nor secondvalue are directly set any value in the program,
 both end up with a value set indirectly through the use of mypointer. This is how it happens:

First, mypointer is assigned the address of firstvalue using the address-of operator (&). Then, the value
pointed to by mypointer is assigned a value of 10. Because, at this moment, mypointer is pointing to the
memory location of firstvalue, this in fact modifies the value of firstvalue.

In order to demonstrate that a pointer may point to different variables during its lifetime in a program,
the example repeats the process with secondvalue and that same pointer, mypointer.

Here is an example a little bit more elaborated:*/

// more pointers
#include <iostream>
using namespace std;

int main ()
{
  int firstvalue = 5, secondvalue = 15;
  int * p1, * p2;

  p1 = &firstvalue;  // p1 = address of firstvalue
  p2 = &secondvalue; // p2 = address of secondvalue
  *p1 = 10;          // value pointed to by p1 = 10
  *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
  p1 = p2;           // p1 = p2 (value of pointer is copied)
  *p1 = 20;          // value pointed to by p1 = 20

  cout << "firstvalue is " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';
  return 0;
}

/*Each assignment operation includes a comment on how each line could be read: i.e.,
replacing ampersands (&) by "address of", and asterisks (*) by "value pointed to by".

Notice that there are expressions with pointers p1 and p2, both with and without the
dereference operator (*). The meaning of an expression using the dereference operator
(*) is very different from one that does not. When this operator precedes the pointer
name, the expression refers to the value being pointed, while when a pointer name appears
without this operator, it refers to the value of the pointer itself (i.e., the address of what the pointer is pointing to).

Another thing that may call your attention is the line:

int * p1, * p2;

This declares the two pointers used in the previous example. But notice that there is an asterisk (*)
for each pointer, in order for both to have type int* (pointer to int). This is required due to the
    precedence rules. Note that if, instead, the code was:

int * p1, p2;

p1 would indeed be of type int*, but p2 would be of type int. Spaces do not matter at all for this purpose.
But anyway, simply remembering to put one asterisk per pointer is enough for most pointer users interested
in declaring multiple pointers per statement. Or even better: use a different statement for each variable.*/
