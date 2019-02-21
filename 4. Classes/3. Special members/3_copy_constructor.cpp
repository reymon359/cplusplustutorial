/* Copy constructor
When an object is passed a named object of its own type as argument, its copy constructor is invoked
in order to construct a copy.

A copy constructor is a constructor whose first parameter is of type reference to the class itself (possibly
const qualified) and which can be invoked with a single argument of this type. For example, for a class MyClass,
the copy constructor may have the following signature:

MyClass::MyClass (const MyClass&);

If a class has no custom copy nor move constructors (or assignments) defined, an implicit copy constructor is
provided. This copy constructor simply performs a copy of its own members. For example, for a class such as:

class MyClass {
  public:
    int a, b; string c;
};

An implicit copy constructor is automatically defined. The definition assumed for this function performs a shallow
copy, roughly equivalent to:

MyClass::MyClass(const MyClass& x) : a(x.a), b(x.b), c(x.c) {}

This default copy constructor may suit the needs of many classes. But shallow copies only copy the members of the class
themselves, and this is probably not what we expect for classes like class Example4 we defined above, because it contains
pointers of which it handles its storage. For that class, performing a shallow copy means that the pointer value is copied,
but not the content itself; This means that both objects (the copy and the original) would be sharing a single string object
(they would both be pointing to the same object), and at some point (on destruction) both objects would try to delete the
same block of memory, probably causing the program to crash on runtime. This can be solved by defining the following custom
copy constructor that performs a deep copy:*/

// copy constructor: deep copy
#include <iostream>
#include <string>
using namespace std;

class Example5 {
    string* ptr;
  public:
    Example5 (const string& str) : ptr(new string(str)) {}
    ~Example5 () {delete ptr;}
    // copy constructor:
    Example5 (const Example5& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const {return *ptr;}
};

int main () {
  Example5 foo ("Example");
  Example5 bar = foo;

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}

/*The deep copy performed by this copy constructor allocates storage for a new string, which is initialized to
contain a copy of the original object. In this way, both objects (copy and original) have distinct copies of the
content stored in different locations.*/
