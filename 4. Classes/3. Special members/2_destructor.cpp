/*Destructor
Destructors fulfill the opposite functionality of constructors: They are responsible for the necessary cleanup
needed by a class when its lifetime ends. The classes we have defined in previous chapters did not allocate any
resource and thus did not really require any clean up.

But now, let's imagine that the class in the last example allocates dynamic memory to store the string it had as
data member; in this case, it would be very useful to have a function called automatically at the end of the object's
life in charge of releasing this memory. To do this, we use a destructor. A destructor is a member function very similar
to a default constructor: it takes no arguments and returns nothing, not even void. It also uses the class name as its
own name, but preceded with a tilde sign (~):*/

// destructors
#include <iostream>
#include <string>
using namespace std;

class Example4 {
    string* ptr;
  public:
    // constructors:
    Example4() : ptr(new string) {}
    Example4 (const string& str) : ptr(new string(str)) {}
    // destructor:
    ~Example4 () {delete ptr;}
    // access content:
    const string& content() const {return *ptr;}
};

int main () {
  Example4 foo;
  Example4 bar ("Example");

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}

/*
On construction, Example4 allocates storage for a string. Storage that is later released by the destructor.

The destructor for an object is called at the end of its lifetime; in the case of foo and bar this happens
at the end of function main.*/
