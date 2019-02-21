/*Special members
[NOTE: This chapter requires proper understanding of dynamically allocated memory]

Special member functions are member functions that are implicitly defined as member of classes under certain circumstances. There are six:

Member function	typical form for class C:
Default constructor	C::C();
Destructor	C::~C();
Copy constructor	C::C (const C&);
Copy assignment	C& operator= (const C&);
Move constructor	C::C (C&&);
Move assignment	C& operator= (C&&);

Let's examine each of these:

Default constructor
The default constructor is the constructor called when objects of a class are declared, but are not initialized with any arguments.

If a class definition has no constructors, the compiler assumes the class to have an implicitly defined default constructor.
Therefore, after declaring a class like this:

class Example {
  public:
    int total;
    void accumulate (int x) { total += x; }
};

The compiler assumes that Example has a default constructor. Therefore, objects of this class can be constructed by simply
declaring them without any arguments:

Example ex;

But as soon as a class has some constructor taking any number of parameters explicitly declared, the compiler no longer
provides an implicit default constructor, and no longer allows the declaration of new objects of that class without arguments.
For example, the following class:

class Example2 {
  public:
    int total;
    Example2 (int initial_value) : total(initial_value) { };
    void accumulate (int x) { total += x; };
};

Here, we have declared a constructor with a parameter of type int. Therefore the following object declaration would be correct:

Example2 ex (100);   // ok: calls constructor

But the following:

Example2 ex;         // not valid: no default constructor

Would not be valid, since the class has been declared with an explicit constructor taking one argument and that replaces the
implicit default constructor taking none.

Therefore, if objects of this class need to be constructed without arguments, the proper default constructor shall also be
declared in the class. For example: */

// classes and default constructors
#include <iostream>
#include <string>
using namespace std;

class Example3 {
    string data;
  public:
    Example3 (const string& str) : data(str) {}
    Example3() {}
    const string& content() const {return data;}
};

int main () {
  Example3 foo;
  Example3 bar ("Example");

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}

/*Here, Example3 has a default constructor (i.e., a constructor without parameters) defined as an empty block:

Example3() {}

This allows objects of class Example3 to be constructed without arguments (like foo was declared in this example).
Normally, a default constructor like this is implicitly defined for all classes that have no other constructors
and thus no explicit definition is required. But in this case, Example3 has another constructor:

Example3 (const string& str);

And when any constructor is explicitly declared in a class, no implicit default constructors is automatically provided.*/
