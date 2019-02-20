/*Class templates
Just like we can create function templates, we can also create class templates, allowing classes to have
members that use template parameters as types. For example:

template <class T>
class mypair {
    T values [2];
  public:
    mypair (T first, T second)
    {
      values[0]=first; values[1]=second;
    }
};

The class that we have just defined serves to store two elements of any valid type. For example, if we wanted
to declare an object of this class to store two integer values of type int with the values 115 and 36 we would write:

mypair<int> myobject (115, 36);

This same class could also be used to create an object to store any other type, such as:

mypair<double> myfloats (3.0, 2.18);

The constructor is the only member function in the previous class template and it has been defined inline within
the class definition itself. In case that a member function is defined outside the defintion of the class template,
it shall be preceded with the template <...> prefix:*/

// class templates
#include <iostream>
using namespace std;

template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

int main () {
  mypair <int> myobject (100, 75);
  cout << myobject.getmax();
  return 0;
}
/*
Notice the syntax of the definition of member function getmax:

template <class T>
T mypair<T>::getmax ()


Confused by so many T's? There are three T's in this declaration: The first one is the template parameter.
The second T refers to the type returned by the function. And the third T (the one between angle brackets)
is also a requirement: It specifies that this function's template parameter is also the class template parameter.*/
