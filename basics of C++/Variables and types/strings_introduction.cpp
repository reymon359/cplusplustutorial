/*An example of compound type is the string class. Variables of this
type are able to store sequences of characters, such as words or sentences. A very useful feature!

A first difference with fundamental data types is that in order to
 declare and use objects (variables) of this type, the program needs
 to include the header where the type is defined within the standard library (header <string>): */


// my first string
// Note: inserting the endl manipulator ends the line (printing a newline character and flushing the stream).
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string mystring;
  mystring = "This is the initial string content";
  cout << mystring << endl;
  mystring = "This is a different string content";
  cout << mystring << endl;
  return 0;
}
