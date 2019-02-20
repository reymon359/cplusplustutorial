/*The keyword this
The keyword this represents a pointer to the object whose member function is being executed.
It is used within a class's member function to refer to the object itself.

One of its uses can be to check if a parameter passed to a member function is the object itself. For example:*/

// example on this
#include <iostream>
using namespace std;

class Dummy {
  public:
    bool isitme (Dummy& param);
};

bool Dummy::isitme (Dummy& param)
{
  if (&param == this) return true;
  else return false;
}

int main () {
  Dummy a;
  Dummy* b = &a;
  if ( b->isitme(a) )
    cout << "yes, &a is b\n";
  return 0;
}
/*
It is also frequently used in operator= member functions that return objects by reference. Following with the examples on
cartesian vector seen before, its operator= function could have been defined as:

CVector& CVector::operator= (const CVector& param)
{
  x=param.x;
  y=param.y;
  return *this;
}

In fact, this function is very similar to the code that the compiler generates implicitly for this class for operator=.*/
