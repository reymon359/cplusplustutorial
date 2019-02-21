/*In principle, a publicly derived class inherits access to every member of a base class except:

its constructors and its destructor
its assignment operator members (operator=)
its friends
its private members

Even though access to the constructors and destructor of the base class is not inherited as such,
they are automatically called by the constructors and destructor of the derived class.

Unless otherwise specified, the constructors of a derived class calls the default constructor of its base
classes (i.e., the constructor taking no arguments). Calling a different constructor of a base class is
possible, using the same syntax used to initialize member variables in the initialization list:

derived_constructor_name (parameters) : base_constructor_name (parameters) {...}

For example: */

// constructors and derived classes
#include <iostream>
using namespace std;

class Mother {
  public:
    Mother ()
      { cout << "Mother: no parameters\n"; }
    Mother (int a)
      { cout << "Mother: int parameter\n"; }
};

class Daughter : public Mother {
  public:
    Daughter (int a)
      { cout << "Daughter: int parameter\n\n"; }
};

class Son : public Mother {
  public:
    Son (int a) : Mother (a)
      { cout << "Son: int parameter\n\n"; }
};

int main () {
  Daughter kelly(0);
  Son bud(0);

  return 0;
}
/*
Notice the difference between which Mother's constructor is called when a new Daughter object is created and which
when it is a Son object. The difference is due to the different constructor declarations of Daughter and Son:

Daughter (int a)          // nothing specified: call default constructor
Son (int a) : Mother (a)  // constructor specified: call this specific constructor */
