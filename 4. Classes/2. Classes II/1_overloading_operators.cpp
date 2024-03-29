/*Overloading operators
Classes, essentially, define new types to be used in C++ code. And types in C++ not only interact with code by means of
constructions and assignments. They also interact by means of operators. For example, take the following operation on fundamental types:

int a, b, c;
a = b + c;

Here, different variables of a fundamental type (int) are applied the addition operator, and then the assignment operator.
For a fundamental arithmetic type, the meaning of such operations is generally obvious and unambiguous, but it may not be
so for certain class types. For example:

struct myclass {
  string product;
  float price;
} a, b, c;
a = b + c;

Here, it is not obvious what the result of the addition operation on b and c does. In fact, this code alone would cause a
compilation error, since the type myclass has no defined behavior for additions. However, C++ allows most operators to be
overloaded so that their behavior can be defined for just about any type, including classes. Here is a list of all the
operators that can be overloaded:

Overloadable operators
+    -    *    /    =    <    >    +=   -=   *=   /=   <<   >>
<<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    |
~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new
delete    new[]     delete[]

Operators are overloaded by means of operator functions, which are regular functions with special names: their name begins
by the operator keyword followed by the operator sign that is overloaded. The syntax is:

type operator sign (parameters) { /*... body ... }
For example, cartesian vectors are sets of two coordinates: x and y. The addition operation of two cartesian vectors is defined
as the addition both x coordinates together, and both y coordinates together. For example, adding the cartesian vectors (3,1)
and (1,2) together would result in (3+1,1+2) = (4,3). This could be implemented in C++ with the following code:

// overloading operators example
#include <iostream>
using namespace std;

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

int main () {
  CVector foo (3,1);
  CVector bar (1,2);
  CVector result;
  result = foo + bar;
  cout << result.x << ',' << result.y << '\n';
  return 0;
}
OUTPUT 4,3
/*
If confused about so many appearances of CVector, consider that some of them refer to the class name (i.e., the type)
CVector and some others are functions with that name (i.e., constructors, which must have the same name as the class). For example:

CVector (int, int) : x(a), y(b) {}  // function name CVector (constructor)
CVector operator+ (const CVector&); // function that returns a CVector

The function operator+ of class CVector overloads the addition operator (+) for that type. Once declared,
this function can be called either implicitly using the operator, or explicitly using its functional name:

c = a + b;
c = a.operator+ (b);

Both expressions are equivalent.

The operator overloads are just regular functions which can have any behavior; there is actually no requirement
that the operation performed by that overload bears a relation to the mathematical or usual meaning of the operator,
although it is strongly recommended. For example, a class that overloads operator+ to actually subtract or that
overloads operator== to fill the object with zeros, is perfectly valid, although using such a class could be challenging.

The parameter expected for a member function overload for operations such as operator+ is naturally the operand
to the right hand side of the operator. This is common to all binary operators (those with an operand to its left
and one operand to its right). But operators can come in diverse forms. Here you have a table with a summary of
the parameters needed for each of the different operators than can be overloaded (please, replace @ by the operator in each case):

Expression	Operator	Member function	Non-member function
@a	+ - * & ! ~ ++ --	A::operator@()	operator@(A)
a@	++ --	A::operator@(int)	operator@(A,int)
a@b	+ - * / % ^ & | < > == != <= >= << >> && || ,	A::operator@(B)	operator@(A,B)
a@b	= += -= *= /= %= ^= &= |= <<= >>= []	A::operator@(B)	-
a(b,c...)	()	A::operator()(B,C...)	-
a->b	->	A::operator->()	-
(TYPE) a	TYPE	A::operator TYPE()	-
Where a is an object of class A, b is an object of class B and c is an object of class C. TYPE is just any type
(that operators overloads the conversion to type TYPE).

Notice that some operators may be overloaded in two forms: either as a member function or as a non-member function:
The first case has been used in the example above for operator+. But some operators can also be overloaded as
non-member functions; In this case, the operator function takes an object of the proper class as first argument.

For example:*/

// non-member operator overloads
#include <iostream>
using namespace std;

class CVector {
  public:
    int x,y;
    CVector () {}
    CVector (int a, int b) : x(a), y(b) {}
};


CVector operator+ (const CVector& lhs, const CVector& rhs) {
  CVector temp;
  temp.x = lhs.x + rhs.x;
  temp.y = lhs.y + rhs.y;
  return temp;
}

int main () {
  CVector foo (3,1);
  CVector bar (1,2);
  CVector result;
  result = foo + bar;
  cout << result.x << ',' << result.y << '\n';
  return 0;
}
