/* INPUT OUTPUT
The standard library defines a handful of stream objects that can be used to access
 what are considered the standard sources and destinations of characters by the environment where the program runs:

cin     standard input stream
cout	standard output stream
cerr	standard error (output) stream
clog	standard logging (output) stream

Standard output (cout)

Multiple insertion operations (<<) may be chained in a single statement:

cout << "This " << " is a " << "single C++ statement";

This last statement would print the text This is a single C++ statement.
Chaining insertions is especially useful to mix literals and variables in a single statement:

cout << "I am " << age << " years old and my zipcode is " << zipcode;

Assuming the age variable contains the value 24 and the zipcode variable contains 90064, the output of the previous statement would be:

I am 24 years old and my zipcode is 90064
What cout does not do automatically is add line breaks at the end, unless instructed to do so.
For example, take the following two statements inserting into cout:
cout << "This is a sentence.";
cout << "This is another sentence.";

The output would be in a single line, without any line breaks in between. Something like:

This is a sentence.This is another sentence.
To insert a line break, a new-line character shall be inserted at the exact position the line
 should be broken. In C++, a new-line character can be specified as \n (i.e., a backslash character followed by a lowercase n). For example:

cout << "First sentence.\n";
cout << "Second sentence.\nThird sentence.";

This produces the following output:

First sentence.
Second sentence.
Third sentence.

Alternatively, the endl manipulator can also be used to break lines. For example:

cout << "First sentence." << endl;
cout << "Second sentence." << endl;

This would print:

First sentence.
Second sentence.

Standard input (cin)
In most program environments, the standard input by default is the keyboard, and the C++ stream object defined to access it is cin.

For formatted input operations, cin is used together with the extraction operator,
which is written as >> (i.e., two "greater than" signs). This operator is then followed by the variable where
the extracted data is stored. For example:

int age;
cin >> age;

*/
// i/o example

#include <iostream>
using namespace std;

int main ()
{
  int i;
  cout << "Please enter an integer value: ";
  cin >> i;
  cout << "The value you entered is " << i;
  cout << " and its double is " << i*2 << ".\n";
  return 0;
}
