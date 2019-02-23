/*Exception specification
Older code may contain dynamic exception specifications. They are now deprecated in C++,
but still supported. A dynamic exception specification follows the declaration of a function,
appending a throw specifier to it. For example:

double myfunction (char param) throw (int);

This declares a function called myfunction, which takes one argument of type char and returns a value of type double.
If this function throws an exception of some type other than int, the function calls std::unexpected instead of looking
for a handler or calling std::terminate.

If this throw specifier is left empty with no type, this means that std::unexpected is called for any exception. Functions
with no throw specifier (regular functions) never call std::unexpected, but follow the normal path of looking for their exception handler.

int myfunction (int param) throw(); // all exceptions call unexpected
int myfunction (int param);         // normal exception handling

Standard exceptions
The C++ Standard library provides a base class specifically designed to declare objects to be thrown as exceptions. It is
called std::exception and is defined in the <exception> header. This class has a virtual member function called what that returns
a null-terminated character sequence (of type char *) and that can be overwritten in derived classes to contain some sort of
description of the exception.*/

// using standard exceptions
#include <iostream>
#include <exception>
using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

int main () {
  try
  {
    throw myex;
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }
  return 0;
}


/* We have placed a handler that catches exception objects by reference (notice the ampersand & after the type),
therefore this catches also classes derived from exception, like our myex object of type myexception.

All exceptions thrown by components of the C++ Standard library throw exceptions derived from this exception class. These are:

exception	description
bad_alloc	thrown by new on allocation failure
bad_cast	thrown by dynamic_cast when it fails in a dynamic cast
bad_exception	thrown by certain dynamic exception specifiers
bad_typeid	thrown by typeid
bad_function_call	thrown by empty function objects
bad_weak_ptr	thrown by shared_ptr when passed a bad weak_ptr

Also deriving from exception, header <exception> defines two generic exception types that can be inherited by custom
exceptions to report errors:

exception	description
logic_error	error related to the internal logic of the program
runtime_error	error detected during runtime

A typical example where standard exceptions need to be checked for is on memory allocation:

// bad_alloc standard exception
#include <iostream>
#include <exception>
using namespace std;

int main () {
  try
  {
    int* myarray= new int[1000];
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl;
  }
  return 0;
}

The exception that may be caught by the exception handler in this example is a bad_alloc. Because bad_alloc is derived
from the standard base class exception, it can be caught (capturing by reference, captures all related classes).*/
