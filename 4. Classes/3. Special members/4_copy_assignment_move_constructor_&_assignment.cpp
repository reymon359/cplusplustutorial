/* Copy assignment
Objects are not only copied on construction, when they are initialized: They can also be copied on
any assignment operation. See the difference:

MyClass foo;
MyClass bar (foo);       // object initialization: copy constructor called
MyClass baz = foo;       // object initialization: copy constructor called
foo = bar;               // object already initialized: copy assignment called

Note that baz is initialized on construction using an equal sign, but this is not an assignment operation!
(although it may look like one): The declaration of an object is not an assignment operation, it is just another
of the syntaxes to call single-argument constructors.

The assignment on foo is an assignment operation. No object is being declared here, but an operation is being
performed on an existing object; foo.

The copy assignment operator is an overload of operator= which takes a value or reference of the class itself as
parameter. The return value is generally a reference to *this (although this is not required). For example, for
a class MyClass, the copy assignment may have the following signature:

MyClass& operator= (const MyClass&);

The copy assignment operator is also a special function and is also defined implicitly if a class has no custom
copy nor move assignments (nor move constructor) defined.

But again, the implicit version performs a shallow copy which is suitable for many classes, but not for classes
with pointers to objects they handle its storage, as is the case in Example5. In this case, not only the class
incurs the risk of deleting the pointed object twice, but the assignment creates memory leaks by not deleting
the object pointed by the object before the assignment. These issues could be solved with a copy assignment that
deletes the previous object and performs a deep copy:

Example5& operator= (const Example5& x) {
  delete ptr;                      // delete currently pointed string
  ptr = new string (x.content());  // allocate space for new string, and copy
  return *this;
}

Or even better, since its string member is not constant, it could re-utilize the same string object:

Example5& operator= (const Example5& x) {
  *ptr = x.content();
  return *this;
}

Move constructor and assignment
Similar to copying, moving also uses the value of an object to set the value to another object. But, unlike copying,
the content is actually transferred from one object (the source) to the other (the destination): the source loses that
content, which is taken over by the destination. This moving only happens when the source of the value is an unnamed object.

Unnamed objects are objects that are temporary in nature, and thus haven't even been given a name. Typical examples of
unnamed objects are return values of functions or type-casts.

Using the value of a temporary object such as these to initialize another object or to assign its value, does not really
require a copy: the object is never going to be used for anything else, and thus, its value can be moved into the destination
object. These cases trigger the move constructor and move assignments:

The move constructor is called when an object is initialized on construction using an unnamed temporary. Likewise,
the move assignment is called when an object is assigned the value of an unnamed temporary:

MyClass fn();            // function returning a MyClass object
MyClass foo;             // default constructor
MyClass bar = foo;       // copy constructor
MyClass baz = fn();      // move constructor
foo = bar;               // copy assignment
baz = MyClass();         // move assignment


Both the value returned by fn and the value constructed with MyClass are unnamed temporaries. In these cases,
there is no need to make a copy, because the unnamed object is very short-lived and can be acquired by the other object
when this is a more efficient operation.

The move constructor and move assignment are members that take a parameter of type rvalue reference to the class itself:

1
2
MyClass (MyClass&&);             // move-constructor
MyClass& operator= (MyClass&&);  // move-assignment


An rvalue reference is specified by following the type with two ampersands (&&). As a parameter, an rvalue reference
matches arguments of temporaries of this type.

The concept of moving is most useful for objects that manage the storage they use, such as objects that allocate storage
with new and delete. In such objects, copying and moving are really different operations:
- Copying from A to B means that new memory is allocated to B and then the entire content of A is copied to this new memory allocated for B.
- Moving from A to B means that the memory already allocated to A is transferred to B without allocating any new storage.
It involves simply copying the pointer.

For example:*/
// move constructor/assignment
#include <iostream>
#include <string>
using namespace std;

class Example6 {
    string* ptr;
  public:
    Example6 (const string& str) : ptr(new string(str)) {}
    ~Example6 () {delete ptr;}
    // move constructor
    Example6 (Example6&& x) : ptr(x.ptr) {x.ptr=nullptr;}
    // move assignment
    Example6& operator= (Example6&& x) {
      delete ptr;
      ptr = x.ptr;
      x.ptr=nullptr;
      return *this;
    }
    // access content:
    const string& content() const {return *ptr;}
    // addition:
    Example6 operator+(const Example6& rhs) {
      return Example6(content()+rhs.content());
    }
};


int main () {
  Example6 foo ("Exam");
  Example6 bar = Example6("ple");   // move-construction

  foo = foo + bar;                  // move-assignment

  cout << "foo's content: " << foo.content() << '\n';
  return 0;
}

/*Compilers already optimize many cases that formally require a move-construction call in what is known as Return Value
Optimization. Most notably, when the value returned by a function is used to initialize an object. In these cases, the move
constructor may actually never get called.

Note that even though rvalue references can be used for the type of any function parameter, it is seldom useful for uses
other than the move constructor. Rvalue references are tricky, and unnecessary uses may be the source of errors quite difficult to track.*/
