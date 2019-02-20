/*Static members
A class can contain static members, either data or functions.

A static data member of a class is also known as a "class variable", because there is only one
common variable for all the objects of that same class, sharing the same value: i.e., its value
is not different from one object of this class to another.

For example, it may be used for a variable within a class that can contain a counter with the number
of objects of that class that are currently allocated, as in the following example:*/

// static members in classes
#include <iostream>
using namespace std;

class Dummy {
  public:
    static int n;
    Dummy () { n++; };
};

int Dummy::n=0;

int main () {
  Dummy a;
  Dummy b[5];
  cout << a.n << '\n';
  Dummy * c = new Dummy;
  cout << Dummy::n << '\n';
  delete c;
  return 0;
}
/*In fact, static members have the same properties as non-member variables but they enjoy class scope. For that reason,
and to avoid them to be declared several times, they cannot be initialized directly in the class, but need to be initialized
somewhere outside it. As in the previous example:

int Dummy::n=0;

Because it is a common variable value for all the objects of the same class, it can be referred to as a member
of any object of that class or even directly by the class name (of course this is only valid for static members):

cout << a.n;
cout << Dummy::n;

These two calls above are referring to the same variable: the static variable n within class Dummy shared by all
objects of this class.

Again, it is just like a non-member variable, but with a name that requires to be accessed like a member of a class (or an object).

Classes can also have static member functions. These represent the same: members of a class that are common to all object of that class,
acting exactly as non-member functions but being accessed like members of the class. Because they are like non-member
functions, they cannot access non-static members of the class (neither member variables nor member functions). They neither
can use the keyword this.*/
