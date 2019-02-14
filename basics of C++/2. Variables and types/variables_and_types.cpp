/* There are some identifiers that cant be used :
alignas, alignof, and, and_eq, asm, auto, bitand, bitor,
 bool, break, case, catch, char, char16_t, char32_t, class,
 compl, const, constexpr, const_cast, continue, decltype,
 default, delete, do, double, dynamic_cast, else, enum,
explicit, export, extern, false, float, for, friend, goto,
if, inline, int, long, mutable, namespace, new, noexcept,
not, not_eq, nullptr, operator, or, or_eq, private,
protected, public, register, reinterpret_cast, return,
short, signed, sizeof, static, static_assert, static_cast,
struct, switch, template, this, thread_local, throw, true,
try, typedef, typeid, typename, union, unsigned, using,
virtual, void, volatile, wchar_t, while, xor, xor_eq */

/* FUNDAMENTAL DATA TYPES
- Character types: They can represent a single character, such as 'A' or '$'.
    he most basic type is char, which is a one-byte character. Other types are also provided for wider characters.
- Numerical integer types: They can store a whole number value, such as 7 or 1024.
    They exist in a variety of sizes, and can either be signed or unsigned, depending on whether they support negative values or not.
- Floating-point types: They can represent real values, such as 3.14 or 0.01,
    with different levels of precision, depending on which of the three floating-point types is used.
- Boolean type: The boolean type, known in C++ as bool, can only represent one of two states, true or false.


Group	Type names*	Notes on size / precision
Character types
    char	Exactly one byte in size. At least 8 bits.
    char16_t	Not smaller than char. At least 16 bits.
    char32_t	Not smaller than char16_t. At least 32 bits.
    wchar_t	Can represent the largest supported character set.
Integer types (signed)
    signed char	Same size as char. At least 8 bits.
    signed short int	Not smaller than char. At least 16 bits.
    signed int	Not smaller than short. At least 16 bits.
    signed long int	Not smaller than int. At least 32 bits.
    signed long long int	Not smaller than long. At least 64 bits.
Integer types (unsigned)
    unsigned char	(same size as their signed counterparts)
    unsigned short int
    unsigned int
    unsigned long int
    unsigned long long int
Floating-point types
    float
    double	Precision not less than float
    long double	Precision not less than double
Boolean type
    bool
Void type
    void	no storage
Null pointer
    decltype(nullptr)

If the size or precision of the type is not a concern, then char, int,
and double are typically selected to represent characters, integers, and
floating-point values, respectively. The other types in their respective
groups are only used in very particular cases.

*/

// operating with variables

#include <iostream>
using namespace std;

int main ()
{
  // declaring variables:
  int a, b;
  int result;

  // process:
  a = 5;
  b = 2;
  a = a + 1;
  result = a - b;

  // print out the result:
  cout << result;

  // terminate the program:
  return 0;
}
