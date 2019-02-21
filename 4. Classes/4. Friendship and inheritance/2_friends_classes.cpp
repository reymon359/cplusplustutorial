/*Friend classes
Similar to friend functions, a friend class is a class whose members have access to the private or
protected members of another class:*/

// friend class
#include <iostream>
using namespace std;

class Square;

class Rectangle {
    int width, height;
  public:
    int area ()
      {return (width * height);}
    void convert (Square a);
};

class Square {
  friend class Rectangle;
  private:
    int side;
  public:
    Square (int a) : side(a) {}
};

void Rectangle::convert (Square a) {
  width = a.side;
  height = a.side;
}

int main () {
  Rectangle rect;
  Square sqr (4);
  rect.convert(sqr);
  cout << rect.area();
  return 0;
}
/*
In this example, class Rectangle is a friend of class Square allowing Rectangle's member functions to access
private and protected members of Square. More concretely, Rectangle accesses the member variable Square::side,
which describes the side of the square.

There is something else new in this example: at the beginning of the program, there is an empty declaration of
class Square. This is necessary because class Rectangle uses Square (as a parameter in member convert), and Square
uses Rectangle (declaring it a friend).

Friendships are never corresponded unless specified: In our example, Rectangle is considered a friend class by Square,
but Square is not considered a friend by Rectangle. Therefore, the member functions of Rectangle can access the protected
and private members of Square but not the other way around. Of course, Square could also be declared friend of Rectangle,
if needed, granting such an access.

Another property of friendships is that they are not transitive: The friend of a friend is not considered a friend unless explicitly specified.*/
