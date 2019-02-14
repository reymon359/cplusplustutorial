/*Explicit type casting operator
Type casting operators allow to convert a value of a given type to another type. There are several ways to do this in C++.
 The simplest one, which has been inherited from the C language, is to precede the expression to be converted by the new
 type enclosed between parentheses (()):

int i;
float f = 3.14;
i = (int) f;

The previous code converts the floating-point number 3.14 to an integer value (3); the remainder is lost. Here, the
typecasting operator was (int). Another way to do the same thing in C++ is to use the functional notation preceding
the expression to be converted by the type and enclosing the expression between parentheses:

i = int (f);

Both ways of casting types are valid in C++.

sizeof
This operator accepts one parameter, which can be either a type or a variable, and returns the size in bytes of that type or object:

x = sizeof (char);

Here, x is assigned the value 1, because char is a type with a size of one byte.

The value returned by sizeof is a compile-time constant, so it is always determined before program execution.

Other operators
Later in these tutorials, we will see a few more operators, like the ones referring to pointers or the specifics for object-oriented programming.

Precedence of operators
A single expression may have multiple operators. For example:

x = 5 + 7 % 2;

In C++, the above expression always assigns 6 to variable x, because the % operator has a higher precedence than the +
operator, and is always evaluated before. Parts of the expressions can be enclosed in parenthesis to override this
precedence order, or to make explicitly clear the intended effect. Notice the difference:

x = 5 + (7 % 2);    // x = 6 (same as without parenthesis)
x = (5 + 7) % 2;    // x = 0

From greatest to smallest priority, C++ operators are evaluated in the following order:
Level	Precedence group	Operator	Description	                    Grouping
1	    Scope	    ::	    scope       qualifier	                    Left-to-right
2	    Postfix (unary)	    ++ --	    postfix increment / decrement	Left-to-right
                            ()	        functional forms                Left-to-right
                            []	        subscript                       Left-to-right
                            . ->	    member access                   Left-to-right
3	    Prefix (unary)	    ++ --	    prefix increment / decrement	Right-to-left
                            ~ !	        bitwise NOT / logical NOT       Right-to-left
                            + -	        unary prefix                    Right-to-left
                            & *	        reference / dereference         Right-to-left
                            new delete	allocation / deallocation       Right-to-left
                            sizeof	    parameter pack                  Right-to-left
                            (type)	    C-style type-casting            Right-to-left
4	    Pointer-to-member	.* ->*	    access pointer	                Left-to-right
5	    Arithmetic: scaling	* / %	    multiply, divide, modulo        Left-to-right
6	    Arithmetic: addition	+ -	    addition, subtraction	        Left-to-right
7	    Bitwise shift	<< >>	        shift left, shift right	        Left-to-right
8	    Relational	< > <= >=	        comparison operators	        Left-to-right
9	    Equality	== !=	            equality / inequality	        Left-to-right
10	    And	&	                        bitwise AND	                    Left-to-right
11	    Exclusive or	    ^	        bitwise XOR	                    Left-to-right
12	    Inclusive or	    |	        bitwise OR	                    Left-to-right
13	    Conjunction	        &&	        logical AND                 	Left-to-right
14	    Disjunction     	||	        logical OR	                    Left-to-right
15	    Assignment-level expressions	= *= /= %= += -=
>>= <<= &= ^= |=	assignment / compound assignment	                    Right-to-left
?:	conditional operator
16	Sequencing	,	comma separator	Left-to-right

When an expression has two operators with the same precedence level, grouping determines which one is evaluated first: either left-to-right or right-to-left.

Enclosing all sub-statements in parentheses (even those unnecessary because of their precedence) improves code readability.*/
