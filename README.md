# cplusplustutorial

I was learning C++ form the [cplusplus](http://www.cplusplus.com) tutorial and practising and compiling in my pc the examples and then I thought i could pass it to markdown to read it more easily and to practise markdown too. So here is my attempt. Of course none of the text here is written by me. It all belongs to cplusplus.

Table of contents
=================

<!--ts-->
   * [Introduction](#introduction)
      * [Compilers](#compilers)
   * [Basics](#basics)
      * [Structure of a program](#structure-of-a-program)
   
<!--te-->

## Introduction

### Compilers

The essential tools needed to follow these tutorials are a computer and a compiler toolchain able to compile C++ code and build the programs to run on it.

C++ is a language that has evolved much over the years, and these tutorials explain many features added recently to the language. Therefore, in order to properly follow the tutorials, a recent compiler is needed. It shall support (even if only partially) the features introduced by the 2011 standard.

Many compiler vendors support the new features at different degrees. See the bottom of this page for some compilers that are known to support the features needed. Some of them are free!

If for some reason, you need to use some older compiler, you can access an older version of these tutorials here (no longer updated).

#### What is a compiler?

Computers understand only one language and that language consists of sets of instructions made of ones and zeros. This computer language is appropriately called machine language.

A single instruction to a computer could look like this:

00000|10011110
-----|--------

A particular computer's machine language program that allows a user to input two numbers, adds the two numbers together, and displays the total could include these machine code instructions:

00000 |	10011110
---|---
00001	 |	11110100
00010	 |	10011110
00011	 |	11010100
00100	 |	10111111
00101 |		00000000

As you can imagine, programming a computer directly in machine language using only ones and zeros is very tedious and error prone. To make programming easier, high level languages have been developed. High level programs also make it easier for programmers to inspect and understand each other's programs easier.

This is a portion of code written in C++ that accomplishes the exact same purpose:
```c++
int a, b, sum;
     
cin >> a;
cin >> b;
             
sum = a + b;
cout << sum << endl;
```
Even if you cannot really understand the code above, you should be able to appreciate how much easier it will be to program in the C++ language as opposed to machine language.

Because a computer can only understand machine language and humans wish to write in high level languages high level languages have to be re-written (translated) into machine language at some point. This is done by special programs called compilers, interpreters, or assemblers that are built into the various programming applications.

C++ is designed to be a compiled language, meaning that it is generally translated into machine language that can be understood directly by the system, making the generated program highly efficient. For that, a set of tools are needed, known as the development toolchain, whose core are a compiler and its linker.

#### Console programs

Console programs are programs that use text to communicate with the user and the environment, such as printing text to the screen or reading input from a keyboard.

Console programs are easy to interact with, and generally have a predictable behavior that is identical across all platforms. They are also simple to implement and thus are very useful to learn the basics of a programming language: The examples in these tutorials are all console programs.

The way to compile console programs depends on the particular tool you are using.

The easiest way for beginners to compile C++ programs is by using an Integrated Development Environment (IDE). An IDE generally integrates several development tools, including a text editor and tools to compile programs directly from it.

Here you have instructions on how to compile and run console programs using different free Integrated Development Interfaces (IDEs):


IDE|Platform|Console programs
-----|--------|-----
Code::blocks	|Windows/Linux/MacOS|	[Compile console programs using Code::blocks](http://www.cplusplus.com/doc/tutorial/introduction/codeblocks/)
Visual Studio Express	|Windows	|[Compile console programs using VS Express 2013](http://www.cplusplus.com/doc/tutorial/introduction/visualstudio/)
Dev-C++	|Windows	|[Compile console programs using Dev-C++](http://www.cplusplus.com/doc/tutorial/introduction/devcpp/)

If you happen to have a Linux or Mac environment with development features, you should be able to compile any of the examples directly from a terminal just by including C++11 flags in the command for the compiler:

Compiler|	Platform	|Command
-----|--------|-----
GCC|	Linux, among others...	|g++ -std=c++0x example.cpp -o example_program
Clang|	OS X, among others...	|clang++ -std=c++11 -stdlib=libc++ example.cpp -o example_program


## Basics

### Structure of a program

The best way to learn a programming language is by writing programs. Typically, the first program beginners write is a program called "Hello World", which simply prints "Hello World" to your computer screen. Although it is very simple, it contains all the fundamental components C++ programs have:

```c++
// my first program in C++
#include <iostream>

int main()
{
  std::cout << "Hello World!";
}
// Hello World!
```

## Compound data types

### Arrays

### Character sequences
The string class has been briefly introduced in an earlier chapter. It is a very powerful class to handle and manipulate strings of characters. However, because strings are, in fact, sequences of characters, we can represent them also as plain arrays of elements of a character type.

For example, the following array:

 
`char foo [20];`


is an array that can store up to 20 elements of type char. It can be represented as:

 ![cstrings1](http://www.cplusplus.com/doc/tutorial/ntcs/c_strings1.png)
 
Therefore, this array has a capacity to store sequences of up to 20 characters. But this capacity does not need to be fully exhausted: the array can also accommodate shorter sequences. For example, at some point in a program, either the sequence "Hello" or the sequence "Merry Christmas" can be stored in foo, since both would fit in a sequence with a capacity for 20 characters.

By convention, the end of strings represented in character sequences is signaled by a special character: the null character, whose literal value can be written as '\0' (backslash, zero).

In this case, the array of 20 elements of type char called foo can be represented storing the character sequences "Hello" and "Merry Christmas" as:

 
Notice how after the content of the string itself, a null character ('\0') has been added in order to indicate the end of the sequence. The panels in gray color represent char elements with undetermined values.


