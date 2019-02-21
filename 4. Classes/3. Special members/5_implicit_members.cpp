/*Implicit members
The six special members functions described above are members implicitly declared on classes under certain circumstances:

Member function	            implicitly defined:	                                                    default definition:
Default constructor	        if no other constructors	                                            does nothing
Destructor	                if no destructor	                                                    does nothing
Copy constructor	        if no move constructor and no move assignment	                        copies all members
Copy assignment	            if no move constructor and no move assignment	                        copies all members
Move constructor	        if no destructor, no copy constructor and no copy nor move assignment	moves all members
Move assignment	            if no destructor, no copy constructor and no copy nor move assignment	moves all members

Notice how not all special member functions are implicitly defined in the same cases. This is mostly due to backwards
compatibility with C structures and earlier C++ versions, and in fact some include deprecated cases. Fortunately, each
class can select explicitly which of these members exist with their default definition or which are deleted by using the
keywords default and delete, respectively. The syntax is either one of:

function_declaration = default;
function_declaration = delete;

For example:*/
// default and delete implicit members
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle (int x, int y) : width(x), height(y) {}
    Rectangle() = default;
    Rectangle (const Rectangle& other) = delete;
    int area() {return width*height;}
};

int main () {
  Rectangle foo;
  Rectangle bar (10,20);

  cout << "bar's area: " << bar.area() << '\n';
  return 0;
}
/*
Here, Rectangle can be constructed either with two int arguments or be default-constructed
(with no arguments). It cannot however be copy-constructed from another Rectangle object, because
this function has been deleted. Therefore, assuming the objects of the last example, the following statement would not be valid:

Rectangle baz (foo);

It could, however, be made explicitly valid by defining its copy constructor as:

Rectangle::Rectangle (const Rectangle& other) = default;

Which would be essentially equivalent to:

Rectangle::Rectangle (const Rectangle& other) : width(other.width), height(other.height) {}

Note that, the keyword default does not define a member function equal to the default constructor (i.e.,
where default constructor means constructor with no parameters), but equal to the constructor that would be
implicitly defined if not deleted.

In general, and for future compatibility, classes that explicitly define one copy/move constructor or one
copy/move assignment but not both, are encouraged to specify either delete or default on the other special
member functions they don't explicitly define.*/
