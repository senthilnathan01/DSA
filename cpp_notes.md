

|  [Basics of C++	3](#basics-of-c++) [sstream	3](#sstream) [printf	3](#printf) [scanf	3](#scanf) [Compilers	4](#compilers) [Identifiers	4](#identifiers) [Fundamental Data Types	4](#fundamental-data-types) [Initialization of variables	4](#initialization-of-variables) [Type deduction: auto and decltype	5](#type-deduction:-auto-and-decltype) [Constants	5](#constants) [Literals	5](#literals) [Preprocessor Definitions (Another way)	6](#preprocessor-definitions-\(another-way\)) [Operators	6](#operators) [Program Structure	7](#program-structure) [Statements and Flow control	7](#statements-and-flow-control) [Templates	9](#templates) [Function templates	9](#function-templates) [Name Visibility	11](#name-visibility) [Scopes	11](#scopes) [Namespaces	12](#namespaces) [using	14](#using) [Compound Data Types	15](#compound-data-types) [Arrays	15](#arrays) [Initializing:	16](#initializing:) [Character sequences	16](#character-sequences) [Initializing:	16](#initializing:-1) [Pointers	17](#pointers) [Pointers and arrays	17](#pointers-and-arrays) [Void pointers	17](#void-pointers) [Invalid pointers	18](#invalid-pointers) [null pointers	19](#null-pointers) [Pointers to function	19](#pointers-to-function) [Dynamic Memory	20](#dynamic-memory) [Operators new and new\[\]	20](#operators-new-and-new[]) [Operator delete and delete\[\]	21](#operator-delete-and-delete[]) [Data Structures	22](#data-structures) [Pointers to structures	24](#pointers-to-structures) [Other Data Types	24](#other-data-types) [Type aliases (typedef / using)	24](#type-aliases-\(typedef-/-using\)) [Unions	25](#unions) [Enumerated Types (Enum)	26](#enumerated-types-\(enum\)) [Enumerated types with enum class	26](#enumerated-types-with-enum-class) [Classes	27](#classes) [Constructors	28](#constructors) [Overloading Constructors	28](#overloading-constructors) [Uniform Initialization	29](#uniform-initialization) [Member Initialisation Methods	30](#member-initialisation-methods) [Pointers to Class	31](#pointers-to-class) [Class vs Struct	31](#class-vs-struct) [Overloading Operators	32](#overloading-operators) [The keyword this	33](#the-keyword-this) [Static Members	34](#static-members) [Const member functions	36](#const-member-functions) [Class Templates	38](#class-templates) [Template Specialisation	40](#template-specialisation) [Special Members	42](#special-members) [Default Constructor	42](#default-constructor) [Destructor	44](#destructor) [Copy constructor	46](#copy-constructor) [Copy assignment	47](#copy-assignment) [Move Constructor and assignment	49](#move-constructor-and-assignment) [Friendship and Inheritance	51](#friendship-and-inheritance) [Friend functions	51](#friend-functions) [Friend classes	52](#friend-classes) [Inheritance between classes	53](#inheritance-between-classes) [Multiple Inheritance	54](#multiple-inheritance) [Polymorphism	56](#polymorphism) [Pointers to base class	56](#pointers-to-base-class) [Virtual Members	57](#virtual-members) [Abstract Base Classes	59](#abstract-base-classes) [Other Features	63](#other-features) [Type Conversions	63](#type-conversions) [Implicit conversion	63](#implicit-conversion) [Implicit conversions with classes	64](#implicit-conversions-with-classes) [Keyword explicit	64](#keyword-explicit) [Type casting	64](#type-casting) [Typeid	65](#typeid) [Exceptions	66](#exceptions) [Exception specification	67](#exception-specification) [Standard exceptions	68](#standard-exceptions) [Preprocessor directives	69](#preprocessor-directives) [Macro definitions (\#define, \#undef)	69](#macro-definitions-\(#define,-#undef\)) [Conditional inclusions (\#ifdef, \#endif, \#ifndef, \#if, \#else and \#elif)	71](#conditional-inclusions-\(#ifdef,-#endif,-#ifndef,-#if,-#else-and-#elif\)) [Line control (\#line)	73](#line-control-\(#line\)) [Error directive (\#error)	73](#error-directive-\(#error\)) [Source file inclusion (\#include)	73](#source-file-inclusion-\(#include\)) [Input/Output with files	73](#input/output-with-files) [Open a file	74](#open-a-file) [Closing a file	75](#closing-a-file) [Text files	75](#text-files)  |
| :---- |

# Basics of C++ {#basics-of-c++}

### sstream {#sstream}

The standard header [\<sstream\>](https://cplusplus.com/%3Csstream%3E) defines a type called [stringstream](https://cplusplus.com/stringstream) that allows a string to be treated as a stream, and thus allowing extraction or insertion operations from/to strings in the same way as they are performed on cin and cout. This feature is most useful to convert strings to numerical values and vice versa. For example, in order to extract an integer from a string we can write:

| 1 2 3 | string mystr ("1204"); int myint; stringstream(mystr) \>\> myint; |
| ----: | :---- |

This declares a string with initialized to a value of "1204", and a variable of type int. Then, the third line uses this variable to extract from a stringstream constructed from the string. This piece of code stores the numerical value 1204 in the variable called myint.

### printf {#printf}

    \#include \<cstdio\>

    int main() {  
        int num \= 10;  
        printf("The number is: %d\\n", num);  
        return 0;  
    }

### scanf {#scanf}

    \#include \<cstdio\>  
    int main() {  
        int num;  
        printf("Enter a number: ");  
        scanf("%d", \&num);  
        printf("You entered: %d\\n", num);  
        return 0;  
    }

### Compilers {#compilers}

Because a computer can only understand machine language and humans wish to write in high level languages. High level languages have to be re-written (translated) into machine language at some point. This is done by special programs called compilers, interpreters, or assemblers that are built into the various programming applications.

### Identifiers {#identifiers}

C++ uses a number of keywords to identify operations and data descriptions; therefore, identifiers created by a programmer cannot match these keywords.

### Fundamental Data Types {#fundamental-data-types}

![][image1]

### Initialization of variables {#initialization-of-variables}

c-like initialization  
type identifier \= initial\_value;

constructor initialization  
type identifier (initial\_value);

uniform initialization  
type identifier {initial\_value};

### Type deduction: auto and decltype {#type-deduction:-auto-and-decltype}

| 1 2 | int foo \= 0; auto bar \= foo;  // the same as: int bar \= foo; |
| ----: | :---- |

| 1 2 | int foo \= 0; decltype(foo) bar;  // the same as: int bar; |
| ----: | :---- |

### Constants {#constants}

#### Literals {#literals}

Three keyword literals exist in C++: true, false and nullptr:

* true and false are the two possible values for variables of type bool.  
* nullptr is the *null pointer* value.

| 1 2 3 | bool foo \= true; bool bar \= false; int\* p \= nullptr; |
| ----: | :---- |

**Typed constant expressions**

| 1 2 | const double pi \= 3.1415926; const char tab \= '\\t'; |
| ----: | :---- |

Another example:  
\#include \<iostream\>  
using namespace std;

const double pi \= 3.14159;  
const char newline \= '\\n';

int main ()  
{  
  double r=5.0;               // radius  
  double circle;

  circle \= 2 \* pi \* r;  
  cout \<\< circle;  
  cout \<\< newline;  
}

#### Preprocessor Definitions (Another way) {#preprocessor-definitions-(another-way)}

Another mechanism to name constant values is the use of preprocessor definitions. They have the following form:

\#define identifier replacement

For example:

\#define PI 3.14159  
\#define NEWLINE '\\n'

### Operators {#operators}

* Assignment operator  
* Arithmetic operator  
* Compound assignment  
* Increment and decrement  
* Relational and comparison operator  
* Logical operator  
* Conditional ternary operator  
* Comma operator

The comma operator (,) is used to separate two or more expressions that are included where only one expression is expected. When the set of expressions has to be evaluated for a value, only the right-most expression is considered.

For example, the following code:

| 1 | a \= (b=3, b+2); |
| ----: | :---- |

would first assign the value 3 to b, and then assign b+2 to variable a. So, at the end, variable a would contain the value 5 while variable b would contain value 3\.

* Bitwise operator


| operator | asm equivalent | description |
| :---- | :---- | :---- |
| & | AND | Bitwise AND |
| | | OR | Bitwise inclusive OR |
| ^ | XOR | Bitwise exclusive OR |
| \~ | NOT | Unary complement (bit inversion) |
| \<\< | SHL | Shift bits left |
| \>\> | SHR | Shift bits right |

* Explicit type casting operator

Type casting operators allow to convert a value of a given type to another type. There are several ways to do this in C++. The simplest one, which has been inherited from the C language, is to precede the expression to be converted by the new type enclosed between parentheses (()):

| 1 2 3 | int i; float f \= 3.14; i \= (int) f; |
| ----: | :---- |

The previous code converts the floating-point number 3.14 to an integer value (3); the remainder is lost. Here, the typecasting operator was (int). Another way to do the same thing in C++ is to use the functional notation preceding the expression to be converted by the type and enclosing the expression between parentheses:

| 1 | i \= int (f); |
| ----: | :---- |

Both ways of casting types are valid in C++.

* Sizeof

This operator accepts one parameter, which can be either a type or a variable, and returns the size in bytes of that type or object:

| 1 | x \= sizeof (char); |
| ----: | :---- |

## Program Structure {#program-structure}

### Statements and Flow control {#statements-and-flow-control}

* Selection statement  
  * If else  
  * Switch (limited to constant expressions)

switch (expression)

{

  case constant1:

     group-of-statements-1;

     break;

  case constant2:

     group-of-statements-2;

     break;

  .  
  .  
  .

  default:

     default-group-of-statements

}

* Iteration statements  
  * While  
  * Do while  
  * For loop

for (initialization; condition; increase) statement;  
![][image2]

* Range based loop

for ( declaration : range ) statement;

* Jump statements  
  * Break  
  * Continue  
  * Goto

|  | // goto loop example \#include \<iostream\> using namespace std; int main () {   int n=10; mylabel:   cout \<\< n \<\< ", ";   n--;   if (n\>0) goto mylabel;   cout \<\< "liftoff\!\\n"; } | 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, liftoff\!  |
| ----: | :---- | :---- |

goto is generally deemed a low-level feature, with no particular use cases in modern higher-level programming paradigms generally used with C++. 

The destination point is identified by a *label*, which is then used as an argument for the goto statement. A *label* is made of a valid identifier followed by a colon (:).

### Templates {#templates}

#### Function templates {#function-templates}

| 1 2 3 4 5 | template \<class SomeType\> SomeType sum (SomeType a, SomeType b) {   return a+b; } |
| ----: | :---- |

name \<template-arguments\> (function-arguments)  
For example, the sum function template defined above can be called with:

| 1 | x \= sum\<int\>(10,20); |
| ----: | :---- |

The function sum\<int\> is just one of the possible instantiations of function template sum. In this case, by using int as template argument in the call, the compiler automatically instantiates a version of sum where each occurrence of SomeType is replaced by int, as if it was defined as:

| 1 2 3 4 | int sum (int a, int b) {   return a+b; }  |
| ----: | :---- |

| // function template \#include \<iostream\> using namespace std; template \<class T\> T sum (T a, T b) {   T result;   result \= a \+ b;   return result; } int main () {   int i=5, j=6, k;   double f=2.0, g=0.5, h;   k=sum\<int\>(i,j);   h=sum\<double\>(f,g);   cout \<\< k \<\< '\\n';   cout \<\< h \<\< '\\n';   return 0; } | 11 2.5  |
| :---- | :---- |

|  | // function templates \#include \<iostream\> using namespace std; template \<class T, class U\> bool are\_equal (T a, U b) {   return (a==b); } int main () {   if (are\_equal(10,10.0))     cout \<\< "x and y are equal\\n";   else     cout \<\< "x and y are not equal\\n";   return 0; } |
| ----: | :---- |

Note that this example uses automatic template parameter deduction in the call to are\_equal:

| 1 | are\_equal(10,10.0) |
| ----: | :---- |

Is equivalent to:

| 1 | are\_equal\<int,double\>(10,10.0) |
| ----: | :---- |

### Name Visibility {#name-visibility}

#### Scopes {#scopes}

| 1 2 3 4 5 6 7 | int some\_function () {   int x;   x \= 0;   double x;   // wrong: name already used in this scope   x \= 0.0; } |
| ----: | :---- |

| // inner block scopes \#include \<iostream\> using namespace std; int main () {   int x \= 10;   int y \= 20;   {     int x;   // ok, inner scope.     x \= 50;  // sets value to inner x     y \= 50;  // sets value to (outer) y     cout \<\< "inner block:\\n";     cout \<\< "x: " \<\< x \<\< '\\n';     cout \<\< "y: " \<\< y \<\< '\\n';   }   cout \<\< "outer block:\\n";   cout \<\< "x: " \<\< x \<\< '\\n';   cout \<\< "y: " \<\< y \<\< '\\n';   return 0; } | inner block: x: 50 y: 50 outer block: x: 10 y: 50  |
| :---- | :---- |

#### Namespaces {#namespaces}

Only one entity can exist with a particular name in a particular scope. This is seldom a problem for local names, since blocks tend to be relatively short, and names have particular purposes within them, such as naming a counter variable, an argument, etc…

Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope. This allows organizing the elements of programs into different logical scopes referred to by names.

The syntax to declare a namespaces is:

|  namespace identifier {   named\_entities }  |
| :---- |

Where identifier is any valid identifier and named\_entities is the set of variables, types and functions that are included within the namespace. For example:

| 1 2 3 4 | namespace myNamespace {   int a, b; } |
| ----: | :---- |

In this case, the variables a and b are normal variables declared within a namespace called myNamespace.

These variables can be accessed from within their namespace normally, with their identifier (either a or b), but if accessed from outside the myNamespace namespace they have to be properly qualified with the scope operator ::. For example, to access the previous variables from outside myNamespace they should be qualified like:

| 1 2 | myNamespace::a myNamespace::b |
| ----: | :---- |

Namespaces are particularly useful to avoid name collisions. For example:

|  | // namespaces \#include \<iostream\> using namespace std; namespace foo {   int value() { return 5; } } namespace bar {   const double pi \= 3.1416;   double value() { return 2\*pi; } } int main () {   cout \<\< foo::value() \<\< '\\n';   cout \<\< bar::value() \<\< '\\n';   cout \<\< bar::pi \<\< '\\n';   return 0; } | 5 6.2832 3.1416 |
| ----: | :---- | :---- |

#### using {#using}

The keyword using introduces a name into the current declarative region (such as a block), thus avoiding the need to qualify the name. For example:

|  | // using \#include \<iostream\> using namespace std; namespace first {   int x \= 5;   int y \= 10; } namespace second {   double x \= 3.1416;   double y \= 2.7183; } int main () {   using first::x;   using second::y;   cout \<\< x \<\< '\\n';   cout \<\< y \<\< '\\n';   cout \<\< first::y \<\< '\\n';   cout \<\< second::x \<\< '\\n';   return 0; } | 5 2.7183 10 3.1416  |
| ----: | :---- | :---- |

The keyword using can also be used as a directive to introduce an entire namespace:

|  | // using \#include \<iostream\> using namespace std; namespace first {   int x \= 5;   int y \= 10; } namespace second {   double x \= 3.1416;   double y \= 2.7183; } int main () {   using namespace first;   cout \<\< x \<\< '\\n';   cout \<\< y \<\< '\\n';   cout \<\< second::x \<\< '\\n';   cout \<\< second::y \<\< '\\n';   return 0; } | 5 10 3.1416 2.7183 |
| ----: | :---- | :---- |

## Compound Data Types {#compound-data-types}

### Arrays {#arrays}

An array is a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.

A typical declaration for an array in C++ is:

type name \[elements\];

| 1 | int foo \[5\];  |
| ----: | :---- |

The elements field within square brackets \[\], representing the number of elements in the array, must be a *constant expression*, since **arrays are blocks of static memory** whose size must be determined at compile time, before the program runs.

#### Initializing: {#initializing:}

| 1 | int foo \[5\] \= { 16, 2, 77, 40, 12071 };  |
| ----: | :---- |

| 1 | int bar \[5\] \= { 10, 20, 30 };  |
| ----: | :---- |

| 1 | int baz \[5\] \= { }; |
| ----: | :---- |

| 1 | int foo \[\] \= { 16, 2, 77, 40, 12071 }; |
| ----: | :---- |

| 1 2 | int foo\[\] \= { 10, 20, 30 }; int foo\[\] { 10, 20, 30 }; |
| ----: | :---- |

### Character sequences {#character-sequences}

#### Initializing: {#initializing:-1}

| 1 2 | char myword\[\] \= { 'H', 'e', 'l', 'l', 'o', '\\0' }; char myword\[\] \= "Hello";  |
| ----: | :---- |

In any case, null-terminated character sequences and strings are easily transformed from one another:

Null-terminated character sequences can be transformed into strings implicitly, and strings can be transformed into null-terminated character sequences by using either of string's member functions c\_str or data:

| 1 2 3 4 | char myntcs\[\] \= "some text"; string mystring \= myntcs;  // convert c-string to string cout \<\< mystring;          // printed as a library string cout \<\< mystring.c\_str();  // printed as a c-string |
| ----: | :---- |

(note: both c\_str and data members of string are equivalent)

### Pointers {#pointers}

The reference and dereference operators are thus complementary:

* & is the ***address-of operator***, and can be read simply as "address of"  
* \* is the ***dereference operator***, and can be read as "value pointed to by"

#### Pointers and arrays {#pointers-and-arrays}

The concept of arrays is related to that of pointers. In fact, arrays work very much like pointers to their first elements, and, actually, an array can always be implicitly converted to the pointer of the proper type. For example, consider these two declarations:

| 1 2 | int myarray \[20\]; int \* mypointer; |
| ----: | :---- |

The following assignment operation would be valid:

| 1 | mypointer \= myarray; |
| ----: | :---- |

After that, mypointer and myarray would be equivalent and would have very similar properties. The main difference being that mypointer can be assigned a different address, whereas myarray can never be assigned anything, and will always represent the same block of 20 elements of type int. 

| 1 2 | a\[5\] \= 0;       // a \[offset of 5\] \= 0 \*(a+5) \= 0;     // pointed to by (a+5) \= 0  |
| ----: | :---- |

These two expressions are equivalent and valid, not only if a is a pointer, but also if a is an array. Remember that if an array, its name can be used just like a pointer to its first element.

#### Void pointers {#void-pointers}

The void type of pointer is a special type of pointer. In C++, void represents the absence of type. Therefore, void pointers are pointers that point to a value that has no type (and thus also an undetermined length and undetermined dereferencing properties).

This gives void pointers a great flexibility, by being able to point to any data type, from an integer value or a float to a string of characters. In exchange, they have a great limitation: the data pointed to by them cannot be directly dereferenced (which is logical, since we have no type to dereference to), and for that reason, any address in a void pointer needs to be transformed into some other pointer type that points to a concrete data type before being dereferenced.

One of its possible uses may be to pass generic parameters to a function. For example:

| // increaser \#include \<iostream\> using namespace std; void increase (void\* data, int psize) {   if ( psize \== sizeof(char) )   { char\* pchar; pchar=(char\*)data; \++(\*pchar); }   else if (psize \== sizeof(int) )   { int\* pint; pint=(int\*)data; \++(\*pint); } } int main () {   char a \= 'x';   int b \= 1602;   increase (\&a,sizeof(a));   increase (\&b,sizeof(b));   cout \<\< a \<\< ", " \<\< b \<\< '\\n';   return 0; } | y, 1603 |
| :---- | :---- |

#### Invalid pointers {#invalid-pointers}

In principle, pointers are meant to point to valid addresses, such as the address of a variable or the address of an element in an array. But pointers can actually point to any address, including addresses that do not refer to any valid element. Typical examples of this are *uninitialized pointers* and pointers to nonexistent elements of an array:

| 1 2 3 4 | int \* p;               // uninitialized pointer (local variable) int myarray\[10\]; int \* q \= myarray+20;  // element out of bounds |
| ----: | :---- |

Neither p nor q point to addresses known to contain a value, but none of the above statements causes an error. In C++, pointers are allowed to take any address value, no matter whether there actually is something at that address or not. What can cause an error is to dereference such a pointer (i.e., actually accessing the value they point to). Accessing such a pointer causes undefined behavior, ranging from an error during runtime to accessing some random value.

#### null pointers {#null-pointers}

But, sometimes, a pointer really needs to explicitly point to nowhere, and not just an invalid address. For such cases, there exists a special value that any pointer type can take: the *null pointer value*. This value can be expressed in C++ in two ways: either with an integer value of zero, or with the nullptr keyword:

| 1 2 | int \* p \= 0; int \* q \= nullptr;  |
| ----: | :---- |

This also works (was used in older code)

| 1 | int \* r \= NULL; |
| ----: | :---- |

NULL is defined in several headers of the standard library, and is defined as an alias of some *null pointer* constant value (such as 0 or nullptr).

#### Pointers to function {#pointers-to-function}

| // pointer to functions \#include \<iostream\> using namespace std; int addition (int a, int b) { return (a+b); } int subtraction (int a, int b) { return (a-b); } int operation (int x, int y, int (\*functocall)(int,int)) {   int g;   g \= (\*functocall)(x,y);   return (g); } int main () {   int m,n;   int (\*minus)(int,int) \= subtraction;   m \= operation (7, 5, addition);   n \= operation (20, m, minus);   cout \<\<n;   return 0; } | 8 |
| :---- | :---- |

### Dynamic Memory {#dynamic-memory}

programs need to dynamically allocate memory, for which the C++ language integrates the operators new and delete.

#### Operators new and new\[\] {#operators-new-and-new[]}

Dynamic memory is allocated using operator new. new is followed by a data type specifier and, if a sequence of more than one element is required, the number of these within brackets \[\]. It returns a pointer to the beginning of the new block of memory allocated. Its syntax is:

pointer \= new type  
pointer \= new type \[number\_of\_elements\]

The first expression is used to allocate memory to contain one single element of type type. The second one is used to allocate a block (an array) of elements of type type, where number\_of\_elements is an integer value representing the amount of these. For example:

| 1 2 | int \* foo; foo \= new int \[5\]; |
| ----: | :---- |

In this case, the system dynamically allocates space for five elements of type int and returns a pointer to the first element of the sequence, which is assigned to foo (a pointer). Therefore, foo now points to a valid block of memory with space for five elements of type int.

![][image3]

Here, foo is a pointer, and thus, the first element pointed to by foo can be accessed either with the expression foo\[0\] or the expression \*foo (both are equivalent). The second element can be accessed either with foo\[1\] or \*(foo+1), and so on...

There is a substantial difference between declaring a normal array and allocating dynamic memory for a block of memory using new. The most important difference is that the size of a regular array needs to be a *constant expression*, and thus its size has to be determined at the moment of designing the program, before it is run, whereas the dynamic memory allocation performed by new allows to assign memory during runtime using any variable value as size.

**Handling unsuccessful allocation:**

The other method is known as nothrow, and what happens when it is used is that when a memory allocation fails, instead of throwing a bad\_alloc exception or terminating the program, the pointer returned by new is a *null pointer*, and the program continues its execution normally.

This method can be specified by using a special object called nothrow, declared in header [\<new\>](https://cplusplus.com/%3Cnew%3E), as argument for new:

| 1 | foo \= new (nothrow) int \[5\]; |
| ----: | :---- |

In this case, if the allocation of this block of memory fails, the failure can be detected by checking if foo is a null pointer:

| 1 2 3 4 5 | int \* foo; foo \= new (nothrow) int \[5\]; if (foo \== nullptr) {   // error assigning memory. Take measures. }  |
| ----: | :---- |

#### Operator delete and delete\[\] {#operator-delete-and-delete[]}

In most cases, memory allocated dynamically is only needed during specific periods of time within a program; once it is no longer needed, it can be freed so that the memory becomes available again for other requests of dynamic memory. This is the purpose of operator delete, whose syntax is:

| 1 2 | delete pointer; delete\[\] pointer; |
| ----: | :---- |

| // rememb-o-matic \#include \<iostream\> \#include \<new\> using namespace std; int main () {   int i,n;   int \* p;   cout \<\< "How many numbers would you like to type? ";   cin \>\> i;   p= new (nothrow) int\[i\];   if (p \== nullptr)     cout \<\< "Error: memory could not be allocated";   else   {     for (n=0; n\<i; n++)     {       cout \<\< "Enter number: ";       cin \>\> p\[n\];     }     cout \<\< "You have entered: ";     for (n=0; n\<i; n++)       cout \<\< p\[n\] \<\< ", ";     delete\[\] p;   }   return 0; } | How many numbers would you like to type? 5 Enter number : 75 Enter number : 436 Enter number : 1067 Enter number : 8 Enter number : 32 You have entered: 75, 436, 1067, 8, 32,  |
| :---- | :---- |

### Data Structures {#data-structures}

A data structure is a group of data elements grouped together under one name. These data elements, known as *members*, can have different types and different lengths. Data structures can be declared in C++ using the following syntax:

struct type\_name {  
member\_type1 member\_name1;  
member\_type2 member\_name2;  
member\_type3 member\_name3;  
.  
.  
} object\_names;

| 1 2 3 4 5 6 7 | struct product {   int weight;   double price; } ; product apple; product banana, melon; |
| ----: | :---- |

| 1 2 3 4 | struct product {   int weight;   double price; } apple, banana, melon; |
| ----: | :---- |

#### 

| // pointers to structures \#include \<iostream\> \#include \<string\> \#include \<sstream\> using namespace std; struct movies\_t {   string title;   int year; }; int main () {   string mystr;   movies\_t amovie;   movies\_t \* pmovie;   pmovie \= \&amovie;   cout \<\< "Enter title: ";   getline (cin, pmovie-\>title);   cout \<\< "Enter year: ";   getline (cin, mystr);   (stringstream) mystr \>\> pmovie-\>year;   cout \<\< "\\nYou have entered:\\n";   cout \<\< pmovie-\>title;   cout \<\< " (" \<\< pmovie-\>year \<\< ")\\n";   return 0; } | Enter title: Invasion of the body snatchers Enter year: 1978   You have entered:Invasion of the body snatchers (1978) |
| :---- | :---- |

#### Pointers to structures {#pointers-to-structures}

Like any other type, structures can be pointed to by its own type of pointers:

| 1 2 3 4 5 6 7 | struct movies\_t {   string title;   int year; }; movies\_t amovie; movies\_t \* pmovie; |
| ----: | :---- |

Here amovie is an object of structure type movies\_t, and pmovie is a pointer to point to objects of structure type movies\_t. Therefore, the following code would also be valid:

| 1 | pmovie \= \&amovie; |
| ----: | :---- |

The arrow operator (\-\>) is a dereference operator that is used exclusively with pointers to objects that have members. This operator serves to access the member of an object directly from its address. For example, in the example above:

| 1 | pmovie-\> |
| ----: | :---- |

is, for all purposes, equivalent to:

| 1 | (\*pmovie). |
| ----: | :---- |

| Expression | What is evaluated | Equivalent |
| :---- | :---- | :---- |
| a.b | Member b of object a |  |
| a-\>b | Member b of object pointed to by a | (\*a).b |
| \*a.b | Value pointed to by member b of object a | \*(a.b) |

### Other Data Types {#other-data-types}

#### Type aliases (typedef / using) {#type-aliases-(typedef-/-using)}

A type alias is a different name by which a type can be identified. In C++, any valid type can be aliased so that it can be referred to with a different identifier.

In C++, there are two syntaxes for creating such type aliases: The first, inherited from the C language, uses the typedef keyword:

typedef existing\_type new\_type\_name ;

where existing\_type is any type, either fundamental or compound, and new\_type\_name is an identifier with the new name given to the type.

For example:

| 1 2 3 4 | typedef char C; typedef unsigned int WORD; typedef char \* pChar; typedef char field \[50\]; |
| ----: | :---- |

This defines four type aliases: C, WORD, pChar, and field as char, unsigned int, char\* and char\[50\], respectively. Once these aliases are defined, they can be used in any declaration just like any other valid type:

| 1 2 3 4 | C mychar, anotherchar, \*ptc1; WORD myword; pChar ptc2; field name; |
| ----: | :---- |

More recently, a second syntax to define type aliases was introduced in the C++ language:

| 1 | using new\_type\_name \= existing\_type ; |
| ----: | :---- |

For example, the same type aliases as above could be defined as:

| 1 2 3 4 | using C \= char; using WORD \= unsigned int; using pChar \= char \*; using field \= char \[50\]; |
| ----: | :---- |

#### Unions {#unions}

Unions allow one portion of memory to be accessed as different data types. Its declaration and use is similar to the one of structures, but its functionality is totally different:

| union type\_name {   member\_type1 member\_name1;   member\_type2 member\_name2;   member\_type3 member\_name3;   .   . } object\_names; |
| :---- |

#### 

I don’t think I will need this thing?

#### Enumerated Types (Enum) {#enumerated-types-(enum)}

|  enum type\_name {   value1,   value2,   value3,   .   . } object\_names;  |
| :---- |

#### Enumerated types with enum class {#enumerated-types-with-enum-class}

But, in C++, it is possible to create real enum types that are neither implicitly convertible to int and that neither have enumerator values of type int, but of the enum type itself, thus preserving type safety. They are declared with enum class (or enum struct) instead of just enum:

| 1 | enum class Colors {black, blue, green, cyan, red, purple, yellow, white}; |
| ----: | :---- |

Each of the enumerator values of an enum class type needs to be scoped into its type (this is actually also possible with enum types, but it is only optional). For example:

| 1 2 3 4 | Colors mycolor;   mycolor \= Colors::blue; if (mycolor \== Colors::green) mycolor \= Colors::red; |
| ----: | :---- |

Enumerated types declared with enum class also have more control over their underlying type; it may be any integral data type, such as char, short or unsigned int, which essentially serves to determine the size of the type. This is specified by a colon and the underlying type following the enumerated type. For example:

| 1 | enum class EyeColor : char {blue, green, brown}; |
| ----: | :---- |

Here, Eyecolor is a distinct type with the same size of a char (1 byte).

## Classes {#classes}

Classes are defined using either keyword class or keyword struct, with the following syntax:

| class class\_name {   access\_specifier\_1:     member1;   access\_specifier\_2:     member2;   ... } object\_names; |
| :---- |

Where class\_name is a valid identifier for the class, object\_names is an optional list of names for objects of this class. The body of the declaration can contain *members*, which can either be data or function declarations, and optionally *access specifiers*.

Classes have the same format as plain *data structures*, **except that they can also include functions and have these new things called *access specifiers***. An *access specifier* is one of the following three keywords: private, public or protected. 

An *access specifier* is one of the following three keywords: private, public or protected. These specifiers modify the access rights for the members that follow them:

* private members of a class are accessible only from **within other members** of the same class (or from their *"friends"*).  
* protected members are accessible from other members of the same class (or from their *"friends"*), but **also from members of their derived classes**.  
* Finally, public members are accessible from **anywhere** where the object is visible.

| // classes example \#include \<iostream\> using namespace std; class Rectangle {     int width, height;   public:     void set\_values (int,int);     int area() {return width\*height;} }; void Rectangle::set\_values (int x, int y) {   width \= x;   height \= y; } int main () {   Rectangle rect;   rect.set\_values (3,4);   cout \<\< "area: " \<\< rect.area();   return 0; } | area: 12 |
| :---- | :---- |

#### Constructors {#constructors}

What would happen in the previous example if we called the member function area before having called set\_values? An undetermined result, since the members width and height had never been assigned a value.

In order to avoid that, a class can include **a special function called its *constructor*, which is automatically called whenever a new object of this class is created, allowing the class to initialize member variables or allocate storage**.

This constructor function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even void.

#### Overloading Constructors {#overloading-constructors}

| // overloading class constructors \#include \<iostream\> using namespace std; class Rectangle {     int width, height;   public:     Rectangle ();     Rectangle (int,int);     int area (void) {return (width\*height);} }; Rectangle::Rectangle () {   width \= 5;   height \= 5; } Rectangle::Rectangle (int a, int b) {   width \= a;   height \= b; } int main () {   Rectangle rect (3,4);   Rectangle rectb;   cout \<\< "rect area: " \<\< rect.area() \<\< endl;   cout \<\< "rectb area: " \<\< rectb.area() \<\< endl;   return 0; } | rect area: 12 rectb area: 25  |
| :---- | :---- |

The ***default constructor*** is the constructor that takes no parameters, and it is special because it is called when an object is declared but is not initialized with any arguments.

#### Uniform Initialization {#uniform-initialization}

The way of calling constructors by enclosing their arguments in parentheses, as shown above, is known as *functional form*. But constructors can also be called with other syntaxes:

First, constructors with a single parameter can be called using the variable initialization syntax (an equal sign followed by the argument):

class\_name object\_name \= initialization\_value;

---

More recently, C++ introduced the possibility of constructors to be called using *uniform initialization*, which essentially is the same as the functional form, but using braces ({}) instead of parentheses (()):

class\_name object\_name { value, value, value, ... }

Ex:

| // classes and uniform initialization \#include \<iostream\> using namespace std; class Circle {     double radius;   public:     Circle(double r) { radius \= r; }     double circum() {return 2\*radius\*3.14159265;} }; int main () {   Circle foo (10.0);   // functional form   Circle bar \= 20.0;   // assignment init.   Circle baz {30.0};   // uniform init.   Circle qux \= {40.0}; // POD-like   cout \<\< "foo's circumference: " \<\< foo.circum() \<\< '\\n';   return 0; } | foo's circumference: 62.8319 |
| :---- | :---- |

#### Member Initialisation Methods {#member-initialisation-methods}

class Rectangle {  
    int width,height;  
  public:  
    Rectangle(int,int);  
    int area() {return width\*height;}  
};

1. Usual method

| Rectangle::Rectangle (int x, int y) { width=x; height=y; } |
| :---- |

2. Two other methods

| 1 | Rectangle::Rectangle (int x, int y) : width(x) { height=y; } |
| ----: | :---- |

| 1 | Rectangle::Rectangle (int x, int y) : width(x), height(y) { } |
| ----: | :---- |

#### Pointers to Class {#pointers-to-class}

| 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 | // pointer to classes example \#include \<iostream\> using namespace std; class Rectangle {   int width, height; public:   Rectangle(int x, int y) : width(x), height(y) {}   int area(void) { return width \* height; } }; int main() {   Rectangle obj (3, 4);   Rectangle \* foo, \* bar, \* baz;   foo \= \&obj;   bar \= new Rectangle (5, 6);   baz \= new Rectangle\[2\] { {2,5}, {3,6} };   cout \<\< "obj's area: " \<\< obj.area() \<\< '\\n';   cout \<\< "\*foo's area: " \<\< foo-\>area() \<\< '\\n';   cout \<\< "\*bar's area: " \<\< bar-\>area() \<\< '\\n';   cout \<\< "baz\[0\]'s area:" \<\< baz\[0\].area() \<\< '\\n';   cout \<\< "baz\[1\]'s area:" \<\< baz\[1\].area() \<\< '\\n';          delete bar;   delete\[\] baz;   return 0; }	 |
| ----: | :---- |

#### Class vs Struct {#class-vs-struct}

Classes can be defined not only with keyword class, but also with keywords struct and union.

The keyword struct, generally used to declare plain data structures, can also be used to declare classes that have member functions, with the same syntax as with keyword class. The only difference between both is that members of classes declared with the keyword struct have public access by default, while members of classes declared with the keyword class have private access by default. For all other purposes both keywords are equivalent in this context.

~~Conversely, the concept of *unions* is different from that of classes declared with struct and class, since unions only store one data member at a time, but nevertheless they are also classes and can thus also hold member functions. The default access in union classes is public.~~

---

#### Overloading Operators {#overloading-operators}

type operator sign (parameters) { /\*... body ...\*/ }

| // overloading operators example \#include \<iostream\> using namespace std; class CVector {   public:     int x,y;     CVector () {};     CVector (int a,int b) : x(a), y(b) {}     CVector operator \+ (const CVector&); }; CVector CVector::operator\+ (const CVector& param) {   CVector temp;   temp.x \= x \+ param.x;   temp.y \= y \+ param.y;   return temp; } int main () {   CVector foo (3,1);   CVector bar (1,2);   CVector result;   result \= foo \+ bar;   cout \<\< result.x \<\< ',' \<\< result.y \<\< '\\n';   return 0; } | 4,3 |
| :---- | :---- |

####  {#the-keyword-this}

| // non-member operator overloads \#include \<iostream\> using namespace std; class CVector {   public:     int x,y;     CVector () {}     CVector (int a, int b) : x(a), y(b) {} }; CVector operator\+ (const CVector& lhs, const CVector& rhs) {   CVector temp;   temp.x \= lhs.x \+ rhs.x;   temp.y \= lhs.y \+ rhs.y;   return temp; } int main () {   CVector foo (3,1);   CVector bar (1,2);   CVector result;   result \= foo \+ bar;   cout \<\< result.x \<\< ',' \<\< result.y \<\< '\\n';   return 0; } | 4,3 |
| :---- | :---- |

#### The keyword this {#the-keyword-this}

The keyword this represents a pointer to the object whose member function is being executed. It is used within a class's member function to refer to the object itself.

One of its uses can be to check if a parameter passed to a member function is the object itself. For example:

#### 

| // example on this \#include \<iostream\> using namespace std; class Dummy {   public:     bool isitme (Dummy& param); }; bool Dummy::isitme (Dummy& param) {   if (\&param \== this) return true;   else return false; } int main () {   Dummy a;   Dummy\* b \= \&a;   if ( b-\>isitme(a) )     cout \<\< "yes, \&a is b\\n";   return 0; } | yes, \&a is b |
| :---- | :---- |

#### Static Members {#static-members}

A class can contain static members, either data or functions.

A static data member of a class is also known as a "class variable", because there is only one common variable for all the objects of that same class, sharing the same value: i.e., its value is not different from one object of this class to another.

For example, it may be used for a variable within a class that can contain a counter with the number of objects of that class that are currently allocated, as in the following example:

|  | // static members in classes \#include \<iostream\> using namespace std; class Dummy {   public:     static int n;     Dummy () { n++; }; }; int Dummy::n=0; int main () {   Dummy a;   Dummy b\[5\];   cout \<\< a.n \<\< '\\n';   Dummy \* c \= new Dummy;   cout \<\< Dummy::n \<\< '\\n';   delete c;   return 0; } | 6 7 |
| ----: | :---- | :---- |

In fact, static members have the same properties as non-member variables but they enjoy class scope. For that reason, and to avoid them to be declared several times, they cannot be initialized directly in the class, but need to be initialized somewhere outside it. As in the previous example:

| 1 | int Dummy::n=0; |
| ----: | :---- |

Because it is a common variable value for all the objects of the same class, it can be referred to as a member of any object of that class or even directly by the class name (of course this is only valid for static members):

| 1 2 | cout \<\< a.n; cout \<\< Dummy::n; |
| ----: | :---- |

These two calls above are referring to the same variable: the static variable n within class Dummy shared by all objects of this class.

Again, it is just like a non-member variable, but with a name that requires to be accessed like a member of a class (or an object).

Classes can also have static member functions. These represent the same: members of a class that are common to all object of that class, acting exactly as non-member functions but being accessed like members of the class. Because they are like non-member functions, they cannot access non-static members of the class (neither member variables nor member functions). They neither can use the keyword this.

#### Const member functions {#const-member-functions}

When an object of a class is qualified as a const object:

| 1 | const MyClass myobject; |
| ----: | :---- |

The access to its data members from outside the class is restricted to **read-only**, as if all its **data members were const for those accessing them from outside the class**. Note though, that the constructor is still called and is allowed to initialize and modify these data members:

| // constructor on const object \#include \<iostream\> using namespace std; class MyClass {   public:     int x;     MyClass(int val) : x(val) {}     int get() {return x;} }; int main() {   const MyClass foo(10); // foo.x \= 20;            // not valid: x cannot be modified   cout \<\< foo.x \<\< '\\n';  // ok: data member x can be read   return 0; } | 10 |
| :---- | :---- |

The member functions of a const object can only be called if they are themselves specified as const members; in the example above, member get (which is not specified as const) cannot be called from foo. To specify that a member is a const member, the const keyword shall follow the function prototype, after the closing parenthesis for its parameters:

| 1 | int get() const {return x;}  |
| ----: | :---- |

Note that const can be used to qualify the type returned by a member function. This const is not the same as the one which specifies a member as const. Both are independent and are located at different places in the function prototype:

|   | int get() const {return x;}        // const member function const int& get() {return x;}       // member function returning a const& const int& get() const {return x;} // const member function returning a const&  |
| ----: | :---- |

Member functions specified to be const cannot modify non-static data members nor call other non-const member functions. In essence, const members shall not modify the state of an object.

const objects are limited to access only member functions marked as const, but non-const objects are not restricted and thus can access both const and non-const member functions alike.

You may think that anyway you are seldom going to declare const objects, and thus marking all members that don't modify the object as const is not worth the effort, but const objects are actually very common. Most functions taking classes as parameters actually take them by const reference, and thus, these functions can only access their const members:

| // const objects \#include \<iostream\> using namespace std; class MyClass {     int x;   public:     MyClass(int val) : x(val) {}     const int& get() const {return x;} }; void print (const MyClass& arg) {   cout \<\< arg.get() \<\< '\\n'; } int main() {   MyClass foo (10);   print(foo);   return 0; } | 10 |
| :---- | :---- |

If in this example, get was not specified as a const member, the call to arg.get() in the print function would not be possible, because const objects only have access to const member functions.

Member functions can be overloaded on their constness: i.e., a class may have two member functions with identical signatures except that one is const and the other is not: in this case, the const version is called only when the object is itself const, and the non-const version is called when the object is itself non-const.

| // overloading members on constness \#include \<iostream\> using namespace std; class MyClass {     int x;   public:     MyClass(int val) : x(val) {}     const int& get() const {return x;}     int& get() {return x;} }; int main() {   MyClass foo (10);   const MyClass bar (20);   foo.get() \= 15;         // ok: get() returns int& // bar.get() \= 25;        // not valid: get() returns const int&   cout \<\< foo.get() \<\< '\\n';   cout \<\< bar.get() \<\< '\\n';   return 0; } | 15 20 |
| :---- | :---- |

#### Class Templates {#class-templates}

Just like we can create function templates, we can also create class templates, allowing classes to have members that use template parameters as types. For example:

| template \<class T\> class mypair {     T values \[2\];   public:     mypair (T first, T second)     {       values\[0\]=first; values\[1\]=second;     } };  |
| :---- |

The class that we have just defined serves to store two elements of any valid type. For example, if we wanted to declare an object of this class to store two integer values of type int with the values 115 and 36 we would write:

| 1 | mypair\<int\> myobject (115, 36); |
| ----: | :---- |

This same class could also be used to create an object to store any other type, such as:

| 1 | mypair\<double\> myfloats (3.0, 2.18); |
| ----: | :---- |

The constructor is the only member function in the previous class template and it has been defined inline within the class definition itself. In case that a member function is defined outside the definition of the class template, it shall be preceded with the template \<...\> prefix:

| // class templates \#include \<iostream\> using namespace std; template \<class T\> class mypair {     T a, b;   public:     mypair (T first, T second)       {a=first; b=second;}     T getmax (); }; template \<class T\> T mypair\<T\>::getmax () {   T retval;   retval \= a\>b? a : b;   return retval; } int main () {   mypair \<int\> myobject (100, 75);   cout \<\< myobject.getmax();   return 0; } | 100 |
| :---- | :---- |

Notice the syntax of the definition of member function getmax:

| 1 2 | template \<class T\> T mypair\<T\>::getmax () |
| ----: | :---- |

Confused by so many T's? There are three T's in this declaration: The first one is the template parameter. The second T refers to the type returned by the function. And the third T (the one between angle brackets) is also a requirement: It specifies that this function's template parameter is also the class template parameter.

#### Template Specialisation {#template-specialisation}

It is possible to define a different implementation for a template when a specific type is passed as template argument. This is called a ***template specialization***.

For example, let's suppose that we have a very simple class called mycontainer that can store one element of any type and that has just one member function called increase, which increases its value. But we find that when it stores an element of type char it would be more convenient to have a completely different implementation with a function member uppercase, so we decide to declare a class template specialization for that type:

| // template specialization \#include \<iostream\> using namespace std; // class template: template \<class T\> class mycontainer {     T element;   public:     mycontainer (T arg) {element=arg;}     T increase () {return \++element;} }; // class template specialization: template \<\> class mycontainer \<char\> {     char element;   public:     mycontainer (char arg) {element=arg;}     char uppercase ()     {       if ((element\>='a')&&(element\<='z'))       element+='A'\-'a';       return element;     } }; int main () {   mycontainer\<int\> myint (7);   mycontainer\<char\> mychar ('j');   cout \<\< myint.increase() \<\< endl;   cout \<\< mychar.uppercase() \<\< endl;   return 0; } | 8 J |
| :---- | :---- |

This is the syntax used for the class template specialization:

| 1 | template \<\> class mycontainer \<char\> { ... }; |
| ----: | :---- |

But more important than this prefix, is the \<char\> specialization parameter after the class template name. This specialization parameter itself identifies the type for which the template class is being specialized (char). Notice the differences between the generic class template and the specialization:

| 1 2 | template \<class T\> class mycontainer { ... }; template \<\> class mycontainer \<char\> { ... }; |
| ----: | :---- |

The first line is the generic template, and the second one is the specialization.

When we declare specializations for a template class, we must also define all its members, even those identical to the generic template class, because **there is no "inheritance" of members from the generic template to the specialization.**

### Special Members {#special-members}

**Special member functions are member functions that are implicitly defined as member of classes under certain circumstances.** There are six:

| Member function | typical form for class C: |
| :---- | :---- |
| [Default constructor](https://cplusplus.com/doc/tutorial/classes2/#default_constructor) | C::C(); |
| [Destructor](https://cplusplus.com/doc/tutorial/classes2/#destructor) | C::\~C(); |
| [Copy constructor](https://cplusplus.com/doc/tutorial/classes2/#copy_constructor) | C::C (const C&); |
| [Copy assignment](https://cplusplus.com/doc/tutorial/classes2/#copy_assignment) | C& operator= (const C&); |
| [Move constructor](https://cplusplus.com/doc/tutorial/classes2/#move) | C::C (C&&); |
| [Move assignment](https://cplusplus.com/doc/tutorial/classes2/#move) | C& operator= (C&&);  |

#### Default Constructor {#default-constructor}

**The default constructor is the constructor called when objects of a class are declared, but are not initialized with any arguments.**

—--  
If a class definition has no constructors, the compiler assumes the class to have an implicitly defined *default constructor*. Therefore, after declaring a class like this:

| 1 2 3 4 5 | class Example {   public:     int total;     void accumulate (int x) { total \+= x; } }; |
| ----: | :---- |

The compiler assumes that Example has a *default constructor*. Therefore, objects of this class can be constructed by simply declaring them without any arguments:

| 1 | Example ex;  |
| ----: | :---- |

—--  
But as soon as a class has some constructor taking any number of parameters explicitly declared, the compiler no longer provides an implicit default constructor, and no longer allows the declaration of new objects of that class without arguments. For example, the following class:

| 1 2 3 4 5 6 | class Example2 {   public:     int total;     Example2 (int initial\_value) : total(initial\_value) { };     void accumulate (int x) { total \+= x; }; }; |
| ----: | :---- |

Here, we have declared a constructor with a parameter of type int. Therefore the following object declaration would be correct:

| 1 | Example2 ex (100);   // ok: calls constructor |
| ----: | :---- |

But the following:

| 1 | Example2 ex;         // not valid: no default constructor |
| ----: | :---- |

Would not be valid, since the class has been declared with an explicit constructor taking one argument and that replaces the implicit *default constructor* taking none.  
—-  
Therefore, if objects of this class need to be constructed without arguments, the proper *default constructor* shall also be declared in the class. For example:

|  | // classes and default constructors \#include \<iostream\> \#include \<string\> using namespace std; class Example3 {     string data;   public:     Example3 (const string& str) : data(str) {}     Example3() {}     const string& content() const {return data;} }; int main () {   Example3 foo;   Example3 bar ("Example");   cout \<\< "bar's content: " \<\< bar.content() \<\< '\\n';   return 0; } | bar's content: Example |
| ----: | :---- | :---- |

Here, Example3 has a *default constructor* (i.e., a constructor without parameters) defined as an empty block:

| 1 | Example3() {} |
| ----: | :---- |

This allows objects of class Example3 to be constructed without arguments (like foo was declared in this example). Normally, a default constructor like this is implicitly defined for all classes that have no other constructors and thus no explicit definition is required. But in this case, Example3 has another constructor:

| 1 | Example3 (const string& str); |
| ----: | :---- |

And when any constructor is explicitly declared in a class, no implicit *default constructors* are automatically provided.  
—--

#### Destructor {#destructor}

**Destructors fulfill the opposite functionality of *constructors*: They are responsible for the necessary cleanup needed by a class when its lifetime ends. The classes we have defined in previous chapters did not allocate any resources and thus did not really require any clean up.**

But now, let's imagine that the class in the last example allocates dynamic memory to store the string it had as data member; in this case, it would be very useful to have a function called automatically at the end of the object's life in charge of releasing this memory. To do this, we use a *destructor*. A destructor is a member function very similar to a *default constructor*: it takes no arguments and returns nothing, not even void. It also uses the class name as its own name, but preceded with a tilde sign (\~):

| // destructors \#include \<iostream\> \#include \<string\> using namespace std; class Example4 {     string\* ptr;   public:     // constructors:     Example4() : ptr(new string) {}     Example4 (const string& str) : ptr(new string(str)) {}     // destructor:     \~Example4 () {delete ptr;}     // access content:     const string& content() const {return \*ptr;} }; int main () {   Example4 foo;   Example4 bar ("Example");   cout \<\< "bar's content: " \<\< bar.content() \<\< '\\n';   return 0; } | bar's content: Example |
| :---- | :---- |

On construction, Example4 allocates storage for a string. Storage that is later released by the destructor.

**The destructor for an object is called at the end of its lifetime; in the case of foo and bar this happens at the end of function main.**

#### Copy constructor {#copy-constructor}

**When an object is passed a named object of its own type as argument, its *copy constructor* is invoked in order to construct a copy.**

A *copy constructor* is a constructor whose first parameter is of type *reference to the class* itself (possibly const qualified) and which can be invoked with a single argument of this type. For example, for a class MyClass, the *copy constructor* may have the following signature:

| 1 | MyClass::MyClass (const MyClass&); |
| ----: | :---- |

If a class has no custom *copy* nor *move* constructors (or assignments) defined, an implicit *copy constructor* is provided. This copy constructor simply performs a copy of its own members. For example, for a class such as:

| 1 2 3 4 | class MyClass {   public:     int a, b; string c; }; |
| ----: | :---- |

An implicit *copy constructor* is automatically defined. The definition assumed for this function performs a *shallow copy*, roughly equivalent to:

| MyClass::MyClass(const MyClass& x) : a(x.a), b(x.b), c(x.c) {}  |
| :---- |

This default *copy constructor* may suit the needs of many classes. But *shallow copies* only copy the members of the class themselves, and this is probably not what we expect for classes like class Example4 we defined above, because it contains pointers of which it handles its storage. For that class, performing a *shallow copy* means that the pointer value is copied, but not the content itself; **This means that both objects (the copy and the original) would be sharing a single string object (they would both be pointing to the same object), and at some point (on destruction) both objects would try to delete the same block of memory, probably causing the program to crash on runtime.** **This can be solved by defining the following custom *copy constructor* that performs a *deep copy*:**

| // copy constructor: deep copy \#include \<iostream\> \#include \<string\> using namespace std; class Example5 {     string\* ptr;   public:     Example5 (const string& str) : ptr(new string(str)) {}     \~Example5 () {delete ptr;}     // copy constructor:     Example5 (const Example5& x) : ptr(new string(x.content())) {}     // access content:     const string& content() const {return \*ptr;} }; int main () {   Example5 foo ("Example");   Example5 bar \= foo;   cout \<\< "bar's content: " \<\< bar.content() \<\< '\\n';   return 0; } | bar's content: Example |
| :---- | :---- |

The *deep copy* performed by this *copy constructor* allocates storage for a new string, which is initialized to contain a copy of the original object. In this way, both objects (copy and original) have distinct copies of the content stored in different locations.

#### Copy assignment {#copy-assignment}

Objects are not only copied on construction, when they are initialized: They can also be copied on any assignment operation. See the difference:

|   | MyClass foo; MyClass bar (foo);       // object initialization: copy constructor called MyClass baz \= foo;       // object initialization: copy constructor called foo \= bar;               // object already initialized: copy assignment called |
| ----- | :---- |

Note that baz is initialized on construction using an *equal sign*, but this is not an assignment operation\! (although it may look like one): The declaration of an object is not an assignment operation, it is just another of the syntaxes to call single-argument constructors.

The assignment on foo is an assignment operation. No object is being declared here, but an operation is being performed on an existing object.

**The *copy assignment operator* is an overload of operator= which takes a *value* or *reference* of the class itself as a parameter.** The return value is generally a reference to \*this (although this is not required). For example, for a class MyClass, the *copy assignment* may have the following signature:

| 1 | MyClass& operator\= (const MyClass&);  |
| ----: | :---- |

The *copy assignment operator* is also a *special function* and is also defined implicitly if a class has no custom *copy* nor *move* assignments (nor move constructor) defined.

But again, the *implicit* version performs a *shallow copy* which is suitable for many classes, but not for classes with pointers to objects they handle its storage, as is the case in Example5. In this case, not only the class incurs the risk of deleting the pointed object twice, but the assignment creates memory leaks by not deleting the object pointed by the object before the assignment. These issues could be solved with a *copy assignment* that deletes the previous object and performs a *deep copy*:

|  | Example5& operator\= (const Example5& x) {   delete ptr;                      // delete currently pointed string   ptr \= new string (x.content());  // allocate space for new string, and copy   return \*this; } |
| ----: | :---- |

Or even better, since its string member is not constant, it could re-utilize the same string object:

|  | Example5& operator\= (const Example5& x) {   \*ptr \= x.content();   return \*this; } |
| ----: | :---- |

#### Move Constructor and assignment {#move-constructor-and-assignment}

Similar to copying, moving also uses the value of an object to set the value to another object. But, unlike copying, the content is actually transferred from one object (the source) to the other (the destination): the source loses that content, which is taken over by the destination. This moving only happens when the source of the value is an *unnamed object*.

***Unnamed objects*** **are objects that are temporary in nature, and thus haven't even been given a name. Typical examples of *unnamed objects* are return values of functions or type-casts.**

Using the value of a temporary object such as these to initialize another object or to assign its value, does not really require a copy: the object is never going to be used for anything else, and thus, its value can be *moved into* the destination object. These cases trigger the ***move constructor*** **and *move assignments*:**

**The *move constructor* is called when an object is initialized on construction using an unnamed temporary. Likewise, the *move assignment* is called when an object is assigned the value of an unnamed temporary:**

|  | MyClass fn();            // function returning a MyClass object MyClass foo;             // default constructor MyClass bar \= foo;       // copy constructor MyClass baz \= fn();      // move constructor foo \= bar;               // copy assignment baz \= MyClass();         // move assignment |
| ----: | :---- |

Both the value returned by fn and the value constructed with MyClass are unnamed temporaries. In these cases, there is no need to make a copy, because the unnamed object is very short-lived and can be acquired by the other object when this is a more efficient operation.

**The move constructor and move assignment are members that take a parameter of type *rvalue reference to the class* itself:**

|  | MyClass (MyClass&&);             // move-constructor MyClass& operator\= (MyClass&&);  // move-assignment |
| ----: | :---- |

**An *rvalue reference* is specified by following the type with two ampersands (&&). As a parameter, an *rvalue reference* matches arguments of temporaries of this type.**

The concept of moving is most useful for objects that manage the storage they use, such as objects that allocate storage with new and delete. In such objects, copying and moving are really different operations:  
\- Copying from A to B means that new memory is allocated to B and then the entire content of A is copied to this new memory allocated for B.  
\- Moving from A to B means that the memory already allocated to A is transferred to B without allocating any new storage. It involves simply copying the pointer.

| // move constructor/assignment \#include \<iostream\> \#include \<string\> using namespace std; class Example6 {     string\* ptr;   public:     Example6 (const string& str) : ptr(new string(str)) {}     \~Example6 () {delete ptr;}     // move constructor     Example6 (Example6&& x) : ptr(x.ptr) {x.ptr=nullptr;}     // move assignment     Example6& operator\= (Example6&& x) {       delete ptr;        ptr \= x.ptr;       x.ptr=nullptr;       return \*this;     }     // access content:     const string& content() const {return \*ptr;}     // addition:     Example6 operator\+(const Example6& rhs) {       return Example6(content()+rhs.content());     } }; int main () {   Example6 foo ("Exam");   Example6 bar \= Example6("ple");   // move-construction      foo \= foo \+ bar;                  // move-assignment   cout \<\< "foo's content: " \<\< foo.content() \<\< '\\n';   return 0; } | foo's content: Example |
| :---- | :---- |

### Friendship and Inheritance {#friendship-and-inheritance}

#### Friend functions {#friend-functions}

In principle, private and protected members of a class cannot be accessed from outside the same class in which they are declared. However, this rule does not apply to *"friends"*.

Friends are functions or classes declared with the friend keyword.

**A non-member function can access the private and protected members of a class if it is declared a *friend* of that class.** That is done by including a declaration of this external function within the class, and preceding it with the keyword friend:

| // friend functions \#include \<iostream\> using namespace std; class Rectangle {     int width, height;   public:     Rectangle() {}     Rectangle (int x, int y) : width(x), height(y) {}     int area() {return width \* height;}     friend Rectangle duplicate (const Rectangle&); }; Rectangle duplicate (const Rectangle& param) {   Rectangle res;   res.width \= param.width\*2;   res.height \= param.height\*2;   return res; } int main () {   Rectangle foo;   Rectangle bar (2,3);   foo \= duplicate (bar);   cout \<\< foo.area() \<\< '\\n';   return 0; } | 24 |
| :---- | :---- |

Notice that neither in the declaration of duplicate nor in its later use in main, function duplicate is considered a member of class Rectangle. It isn't\! It simply has access to its private and protected members without being a member.

### Friend classes {#friend-classes}

Similar to friend functions, a friend class is a class whose members have access to the private or protected members of another class:

| // friend class \#include \<iostream\> using namespace std; class Square; class Rectangle {     int width, height;   public:     int area ()       {return (width \* height);}     void convert (Square a); }; class Square {   friend class Rectangle;   private:     int side;   public:     Square (int a) : side(a) {} }; void Rectangle::convert (Square a) {   width \= a.side;   height \= a.side; }    int main () {   Rectangle rect;   Square sqr (4);   rect.convert(sqr);   cout \<\< rect.area();   return 0; } | 16 |
| :---- | :---- |

#### Inheritance between classes {#inheritance-between-classes}

**Classes in C++ can be extended, creating new classes which retain characteristics of the base class. This process, known as inheritance, involves a *base class* and a *derived class*: The *derived class* inherits the members of the *base class*, on top of which it can add its own members.**

**class derived\_class\_name: public base\_class\_name**  
**{ /\*...\*/ };**

( The public access specifier may be replaced by any one of the other access specifiers (protected or private). This access specifier limits the most accessible level for the members inherited from the base class: The members with a more accessible level are inherited with this level instead, while the members with an equal or more restrictive access level keep their restrictive level in the derived class.)

1\. Public inheritance

* Public members of the base class remain public in the derived class.  
* Protected members of the base class remain protected in the derived class.  
* Private members of the base class remain inaccessible in the derived class (private members are never inherited directly).

2\. Protected inheritance

* Public members of the base class become protected in the derived class.  
* Protected members of the base class remain protected in the derived class.  
* Private members of the base class remain inaccessible in the derived class.

3\. Private inheritance

* Public members of the base class become private in the derived class.  
* Protected members of the base class become private in the derived class.  
* Private members of the base class remain inaccessible in the derived class.

| // derived classes \#include \<iostream\> using namespace std; class Polygon {   protected:     int width, height;   public:     void set\_values (int a, int b)       { width=a; height=b;}  }; class Rectangle: public Polygon {   public:     int area ()       { return width \* height; }  }; class Triangle: public Polygon {   public:     int area ()       { return width \* height / 2; }   };    int main () {   Rectangle rect;   Triangle trgl;   rect.set\_values (4,5);   trgl.set\_values (4,5);   cout \<\< rect.area() \<\< '\\n';   cout \<\< trgl.area() \<\< '\\n';   return 0; } | 20 10 |
| :---- | :---- |

If no access level is specified for the inheritance, the compiler assumes private for classes declared with keyword class and public for those declared with struct.

#### Multiple Inheritance {#multiple-inheritance}

A class may inherit from more than one class by simply specifying more base classes, separated by commas, in the list of a class's base classes (i.e., after the colon). For example, if the program had a specific class to print on screen called Output, and we wanted our classes Rectangle and Triangle to also inherit its members in addition to those of Polygon we could write:

| class Rectangle: public Polygon, public Output; class Triangle: public Polygon, public Output; |
| :---- |

| // multiple inheritance \#include \<iostream\> using namespace std; class Polygon {   protected:     int width, height;   public:     Polygon (int a, int b) : width(a), height(b) {} }; class Output {   public:     static void print (int i); }; void Output::print (int i) {   cout \<\< i \<\< '\\n'; } class Rectangle: public Polygon, public Output {   public:     Rectangle (int a, int b) : Polygon(a,b) {}     int area ()       { return width\*height; } }; class Triangle: public Polygon, public Output {   public:     Triangle (int a, int b) : Polygon(a,b) {}     int area ()       { return width\*height/2; } };    int main () {   Rectangle rect (4,5);   Triangle trgl (4,5);   rect.print (rect.area());   Triangle::print (trgl.area());   return 0; } | 20 10  |
| :---- | :---- |

### Polymorphism {#polymorphism}

#### Pointers to base class {#pointers-to-base-class}

**One of the key features of class inheritance is that a pointer to a derived class is type-compatible with a pointer to its base class. *Polymorphism* is the art of taking advantage of this simple but powerful and versatile feature.**

| // pointers to base class \#include \<iostream\> using namespace std; class Polygon {   protected:     int width, height;   public:     void set\_values (int a, int b)       { width=a; height=b; } }; class Rectangle: public Polygon {   public:     int area()       { return width\*height; } }; class Triangle: public Polygon {   public:     int area()       { return width\*height/2; } }; int main () {   Rectangle rect;   Triangle trgl;   Polygon \* ppoly1 \= \&rect;   Polygon \* ppoly2 \= \&trgl;   ppoly1-\>set\_values (4,5);   ppoly2-\>set\_values (4,5);   cout \<\< rect.area() \<\< '\\n';   cout \<\< trgl.area() \<\< '\\n';   return 0; } | 20 10 |
| :---- | :---- |

For example, the following two statements would be equivalent in the previous example:

| 1 2 | ppoly1-\>set\_values (4,5); rect.set\_values (4,5); |
| ----: | :---- |

#### Virtual Members {#virtual-members}

**A virtual member is a member function that can be redefined in a derived class, while preserving its calling properties through references.** The syntax for a function to become virtual is to precede its declaration with the virtual keyword:

| // virtual members \#include \<iostream\> using namespace std; class Polygon {   protected:     int width, height;   public:     void set\_values (int a, int b)       { width=a; height=b; }     virtual int area ()       { return 0; } }; class Rectangle: public Polygon {   public:     int area ()       { return width \* height; } }; class Triangle: public Polygon {   public:     int area ()       { return (width \* height / 2); } }; int main () {   Rectangle rect;   Triangle trgl;   Polygon poly;   Polygon \* ppoly1 \= \&rect;   Polygon \* ppoly2 \= \&trgl;   Polygon \* ppoly3 \= \&poly;   ppoly1-\>set\_values (4,5);   ppoly2-\>set\_values (4,5);   ppoly3-\>set\_values (4,5);   cout \<\< ppoly1-\>area() \<\< '\\n';   cout \<\< ppoly2-\>area() \<\< '\\n';   cout \<\< ppoly3-\>area() \<\< '\\n';   return 0; } | 20 10 0 |
| :---- | :---- |

The member function area has been declared as virtual in the base class because it is later redefined in each of the derived classes. Non-virtual members can also be redefined in derived classes, but non-virtual members of derived classes cannot be accessed through a reference of the base class: i.e., **if virtual is removed from the declaration of area in the example above, all three calls to area would return zero, because in all cases, the version of the base class would have been called instead.**

Therefore, **essentially, what the virtual keyword does is to allow a member of a derived class with the same name as one in the base class to be appropriately called from a pointer**, and more precisely when the type of the pointer is a pointer to the base class that is pointing to an object of the derived class, as in the above example.

A class that declares or inherits a virtual function is called a ***polymorphic class*.**

#### Abstract Base Classes {#abstract-base-classes}

Abstract base classes are something very similar to the Polygon class in the previous example. **They are classes that can only be used as base classes, and thus are allowed to have virtual member functions without definition (known as pure virtual functions)**. 

The syntax is to **replace their definition by \=0** (an equal sign and a zero):

An abstract base Polygon class could look like this:

| 1 2 3 4 5 6 7 8 9 | // abstract class CPolygon class Polygon {   protected:     int width, height;   public:     void set\_values (int a, int b)       { width=a; height=b; }     virtual int area () \=0; };  |
| ----: | :---- |

* **Classes that contain at least one *pure virtual function* are known as *abstract base classes*.**  
* **Abstract base classes cannot be used to instantiate objects.**   
* But an *abstract base class* is not totally useless. **It can be used to create pointers to it, and take advantage of all its polymorphic abilities.** 

| 1 | Polygon mypolygon;   // not working if Polygon is abstract base class |
| ----: | :---- |

This works:

| 1 2 | Polygon \* ppoly1; Polygon \* ppoly2; |
| ----: | :---- |

And can actually be dereferenced when pointing to objects of derived (non-abstract) classes. Here is the entire example:

| // abstract base class \#include \<iostream\> using namespace std; class Polygon {   protected:     int width, height;   public:     void set\_values (int a, int b)       { width=a; height=b; }     virtual int area (void) \=0; }; class Rectangle: public Polygon {   public:     int area (void)       { return (width \* height); } }; class Triangle: public Polygon {   public:     int area (void)       { return (width \* height / 2); } }; int main () {   Rectangle rect;   Triangle trgl;   Polygon \* ppoly1 \= \&rect;   Polygon \* ppoly2 \= \&trgl;   ppoly1-\>set\_values (4,5);   ppoly2-\>set\_values (4,5);   cout \<\< ppoly1-\>area() \<\< '\\n';   cout \<\< ppoly2-\>area() \<\< '\\n';   return 0; } | 20 10 |
| :---- | :---- |

In this example, objects of different but related types are referred to using a unique type of pointer (Polygon\*) and the proper member function is called every time, just because they are virtual. This can be really useful in some circumstances. For example, it is even possible for a member of the abstract base class Polygon **to use the special pointer this to access the proper virtual members**, even though Polygon itself has no implementation for this function:

|  | // pure virtual members can be called // from the abstract base class \#include \<iostream\> using namespace std; class Polygon {   protected:     int width, height;   public:     void set\_values (int a, int b)       { width=a; height=b; }     virtual int area() \=0;     void printarea()       { cout \<\< this\-\>area() \<\< '\\n'; } }; class Rectangle: public Polygon {   public:     int area (void)       { return (width \* height); } }; class Triangle: public Polygon {   public:     int area (void)       { return (width \* height / 2); } }; int main () {   Rectangle rect;   Triangle trgl;   Polygon \* ppoly1 \= \&rect;   Polygon \* ppoly2 \= \&trgl;   ppoly1-\>set\_values (4,5);   ppoly2-\>set\_values (4,5);   ppoly1-\>printarea();   ppoly2-\>printarea();   return 0; } | 20 10  |
| ----: | :---- | :---- |

Just another example combining some things we learnt before- dynamic memory, constructor initializers and polymorphism:

| // dynamic allocation and polymorphism \#include \<iostream\> using namespace std; class Polygon {   protected:     int width, height;   public:     Polygon (int a, int b) : width(a), height(b) {}     virtual int area (void) \=0;     void printarea()       { cout \<\< this\-\>area() \<\< '\\n'; } }; class Rectangle: public Polygon {   public:     Rectangle(int a,int b) : Polygon(a,b) {}     int area()       { return width\*height; } }; class Triangle: public Polygon {   public:     Triangle(int a,int b) : Polygon(a,b) {}     int area()       { return width\*height/2; } }; int main () {   Polygon \* ppoly1 \= new Rectangle (4,5);   Polygon \* ppoly2 \= new Triangle (4,5);   ppoly1-\>printarea();   ppoly2-\>printarea();   delete ppoly1;   delete ppoly2;   return 0; } | 20 10 |
| :---- | :---- |

## Other Features {#other-features}

### Type Conversions {#type-conversions}

#### Implicit conversion {#implicit-conversion}

Implicit conversions are **automatically performed when a value is copied to a compatible type**. For example:

| 1 2 3 | short a=2000; int b; b=a; |
| ----: | :---- |

Here, the value of a is promoted from short to int **without the need of any explicit operator. This is known as a *standard conversion***. **Standard conversions affect fundamental data types, and allow the conversions between numerical types (short to int, int to float, double to int...), to or from bool, and some pointer conversions.**

* Converting to int from some smaller integer type, or to double from float is known as ***promotion***, and is guaranteed to produce the exact same value in the destination type. 

* Other conversions between arithmetic types may not always be able to represent the same value exactly: If a negative integer value is converted to an unsigned type, the resulting value corresponds to its 2's complement bitwise representation (i.e., \-1 becomes the largest value representable by the type, \-2 the second largest, ...).

* The conversions **from/to bool** consider false equivalent to zero (for numeric types) and to null pointer (for pointer types); true is equivalent to all other values and is converted to the equivalent of 1\.

* If the conversion is from a floating-point type to an integer type, **the value is truncated** (the decimal part is removed).

* If the result lies outside the range of representable values by the type, the conversion causes **undefined behavior**.

* Otherwise, if the conversion is between numeric types of the same kind (integer-to-integer or floating-to-floating), the conversion is valid, but the value is **implementation-specific** (and may not be portable).

* For non-fundamental types, arrays and functions implicitly convert to pointers, and pointers in general allow the following conversions:  
  * Null pointers can be converted to pointers of any type  
  * Pointers to any type can be converted to void pointers.  
  * Pointer upcast: pointers to a derived class can be converted to a pointer of an accessible and unambiguous base class, without modifying its const or volatile qualification.

#### Implicit conversions with classes {#implicit-conversions-with-classes}

In the world of classes, implicit conversions can be controlled by means of three member functions:

* **Single-argument constructors:** allow implicit conversion from a particular type to initialize an object.  
* **Assignment operator:** allow implicit conversion from a particular type on assignments.  
* **Type-cast operator:** allow implicit conversion to a particular type.

| 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 | // implicit conversion of classes: \#include \<iostream\> using namespace std; class A {}; class B { public:   // conversion from A (constructor):   B (const A& x) {}   // conversion from A (assignment):   B& operator\= (const A& x) {return \*this;}   // conversion to A (type-cast operator)   operator A() {return A();} }; int main () {   A foo;   B bar \= foo;    // calls constructor   bar \= foo;      // calls assignment   foo \= bar;      // calls type-cast operator   return 0; } |
| ----: | :---- |

#### Keyword explicit {#keyword-explicit}

Skipped

#### Type casting {#type-casting}

 There exist two main syntaxes for generic type-casting: *functional* and *c-like*:

| 1 2 3 4 | double x \= 10.3; int y; y \= int (x);    // functional notation y \= (int) x;    // c-like cast notation |
| ----: | :---- |

dynamic\_cast \<new\_type\> (expression)  
reinterpret\_cast \<new\_type\> (expression)  
static\_cast \<new\_type\> (expression)  
const\_cast \<new\_type\> (expression)

Details about these are skipped.

The traditional type-casting equivalents to these expressions would be:

(new\_type) expression  
new\_type (expression)

#### Typeid {#typeid}

typeid allows to check the type of an expression:

typeid (expression)

This operator returns a reference to a constant object of type [type\_info](https://cplusplus.com/type_info) that is defined in the standard header [\<typeinfo\>](https://cplusplus.com/%3Ctypeinfo%3E). A value returned by typeid can be compared with another value returned by typeid using operators \== and \!= or can serve to obtain a null-terminated character sequence representing the data type or class name by using its **name() member**.

| // typeid \#include \<iostream\> \#include \<typeinfo\> using namespace std; int main () {   int \* a,b;   a=0; b=0;   if (typeid(a) \!= typeid(b))   {     cout \<\< "a and b are of different types:\\n";     cout \<\< "a is: " \<\< typeid(a).name() \<\< '\\n';     cout \<\< "b is: " \<\< typeid(b).name() \<\< '\\n';   }   return 0; } | a and b are of different types: a is: int \* b is: int  |
| :---- | :---- |

When typeid is applied to classes, typeid uses the RTTI (*Run-Time Type Information)* to keep track of the type of dynamic objects. When typeid is applied to an expression whose type is a polymorphic class, the result is the type of the most derived complete object:

|  | // typeid, polymorphic class \#include \<iostream\> \#include \<typeinfo\> \#include \<exception\> using namespace std; class Base { virtual void f(){} }; class Derived : public Base {}; int main () {   try {     Base\* a \= new Base;     Base\* b \= new Derived;     cout \<\< "a is: " \<\< typeid(a).name() \<\< '\\n';     cout \<\< "b is: " \<\< typeid(b).name() \<\< '\\n';     cout \<\< "\*a is: " \<\< typeid(\*a).name() \<\< '\\n';     cout \<\< "\*b is: " \<\< typeid(\*b).name() \<\< '\\n';   } catch (exception& e) { cout \<\< "Exception: " \<\< e.what() \<\< '\\n'; }   return 0; } | a is: class Base \* b is: class Base \* \*a is: class Base \*b is: class Derived |
| ----: | :---- | :---- |

### Exceptions {#exceptions}

An exception is thrown by using the throw keyword from inside the try block. Exception handlers are declared with the keyword catch, which must be placed immediately after the try block:

|  | // exceptions \#include \<iostream\> using namespace std; int main () {   try   {     throw 20;   }   catch (int e)   {     cout \<\< "An exception occurred. Exception Nr. " \<\< e \<\< '\\n';   }   return 0; } | An exception occurred. Exception Nr. 20  |
| ----: | :---- | :---- |

**A throw expression accepts one parameter** (in this case the integer value 20), which is passed as an argument to the exception handler.

**Multiple handlers (i.e., catch expressions) can be chained**; each one with a different parameter type. Only the handler whose argument type matches the type of the exception specified in the throw statement is executed.

If an **ellipsis (...) is used as the parameter of catch, that handler will catch any exception no matter what** the type of the exception thrown. This can be used as a default handler that catches all exceptions not caught by other handlers:

| 1 2 3 4 5 6 | try {   // code here } catch (int param) { cout \<\< "int exception"; } catch (char param) { cout \<\< "char exception"; } catch (...) { cout \<\< "default exception"; }  |
| ----: | :---- |

**It is also possible to nest try-catch blocks within more external try blocks. In these cases, we have the possibility that an internal catch block forwards the exception to its external level.** This is done with the expression throw; with no arguments. For example:

| 1 2 3 4 5 6 7 8 9 10 11 | try {   try {       // code here   }   catch (int n) {       throw;   } } catch (...) {   cout \<\< "Exception occurred"; } |
| ----: | :---- |

### Exception specification {#exception-specification}

Older code may contain *dynamic exception specifications*. They are now deprecated in C++, but still supported. A ***dynamic exception specification*** follows the declaration of a function, appending a throw specifier to it. For example:

| 1 | double myfunction (char param) throw (int); |
| ----: | :---- |

This declares a function called myfunction, which takes one argument of type char and returns a value of type double. If this function throws an exception of some type other than int, the function calls [std::unexpected](https://cplusplus.com/unexpected) instead of looking for a handler or calling [std::terminate](https://cplusplus.com/terminate).

If this throw specifier is left empty with no type, this means that [std::unexpected](https://cplusplus.com/unexpected) is called for any exception. Functions with no throw specifier (regular functions) never call [std::unexpected](https://cplusplus.com/unexpected), but follow the normal path of looking for their exception handler.

| 1 2 | int myfunction (int param) throw(); // all exceptions call unexpected int myfunction (int param);         // normal exception handling |
| ----: | :---- |

### Standard exceptions {#standard-exceptions}

The C++ Standard library provides a base class specifically designed to declare objects to be thrown as exceptions. It is called [std::exception](https://cplusplus.com/exception) and is defined in the [\<exception\>](https://cplusplus.com/%3Cexception%3E) header. This class has a virtual member function called what that returns a null-terminated character sequence (of type char \*) and that can be overwritten in derived classes to contain some sort of description of the exception.

| // using standard exceptions \#include \<iostream\> \#include \<exception\> using namespace std; class myexception: public exception {   virtual const char\* what() const throw()   {     return "My exception happened";   } } myex; int main () {   try   {     throw myex;   }   catch (exception& e)   {     cout \<\< e.what() \<\< '\\n';   }   return 0; } | My exception happened. |
| :---- | :---- |

All exceptions thrown by components of the C++ Standard library throw exceptions derived from this exception class. These are:

| exception | description |
| :---- | :---- |
| [bad\_alloc](https://cplusplus.com/bad_alloc) | thrown by new on allocation failure |
| [bad\_cast](https://cplusplus.com/bad_cast) | thrown by dynamic\_cast when it fails in a dynamic cast |
| [bad\_exception](https://cplusplus.com/bad_exception) | thrown by certain dynamic exception specifiers |
| [bad\_typeid](https://cplusplus.com/bad_typeid) | thrown by typeid |
| [bad\_function\_call](https://cplusplus.com/bad_function_call) | thrown by empty [function](https://cplusplus.com/function) objects |
| [bad\_weak\_ptr](https://cplusplus.com/bad_weak_ptr) | thrown by [shared\_ptr](https://cplusplus.com/shared_ptr) when passed a bad [weak\_ptr](https://cplusplus.com/weak_ptr) |

Also deriving from exception, header [\<exception\>](https://cplusplus.com/%3Cexception%3E) defines two generic exception types that can be inherited by custom exceptions to report errors:

| exception | description |
| :---- | :---- |
| [logic\_error](https://cplusplus.com/logic_error) | error related to the internal logic of the program |
| [runtime\_error](https://cplusplus.com/runtime_error) | error detected during runtime  |

### Preprocessor directives {#preprocessor-directives}

**Preprocessor directives are lines included in the code of programs preceded by a hash sign (\#). These lines are not program statements but directives for the *preprocessor*. The preprocessor examines the code before actual compilation of code begins and resolves all these directives before any code is actually generated by regular statements.**

These *preprocessor directives* extend only across a single line of code. As soon as a newline character is found, the preprocessor directive ends. No semicolon (;) is expected at the end of a preprocessor directive. The only way a preprocessor directive can extend through more than one line is by preceding the newline character at the end of the line by a backslash (\\).

#### Macro definitions (\#define, \#undef) {#macro-definitions-(#define,-#undef)}

To define preprocessor macros we can use \#define. Its syntax is:

\#define identifier replacement

When the preprocessor encounters this directive, it replaces any occurrence of identifier in the rest of the code by replacement. This replacement can be an expression, a statement, a block or simply anything. The preprocessor does not understand C++ proper, it simply replaces any occurrence of identifier by replacement.

| 1 2 3 | \#define TABLE\_SIZE 100 int table1\[TABLE\_SIZE\]; int table2\[TABLE\_SIZE\]; |
| ----: | :---- |

After the preprocessor has replaced TABLE\_SIZE, the code becomes equivalent to:

| 1 2 | int table1\[100\]; int table2\[100\]; |
| ----: | :---- |

\#define can work also with parameters to define function macros:

| 1 | \#define getmax(a,b) a\>b?a:b |
| ----: | :---- |

This would replace any occurrence of getmax followed by two arguments by the replacement expression, but also replacing each argument by its identifier, exactly as you would expect if it was a function:

|  | // function macro \#include \<iostream\> using namespace std; \#define getmax(a,b) ((a)\>(b)?(a):(b)) int main() {   int x=5, y;   y= getmax(x,2);   cout \<\< y \<\< endl;   cout \<\< getmax(7,x) \<\< endl;   return 0; } | 5 7 |
| ----: | :---- | :---- |

Defined macros are not affected by block structure. A macro lasts until it is undefined with the \#undef preprocessor directive:

| 1 2 3 4 5 | \#define TABLE\_SIZE 100 int table1\[TABLE\_SIZE\]; \#undef TABLE\_SIZE \#define TABLE\_SIZE 200 int table2\[TABLE\_SIZE\]; |
| ----: | :---- |

This would generate the same code as:

| 1 2 | int table1\[100\]; int table2\[200\]; |
| ----: | :---- |

Function macro definitions accept two special operators (\# and \#\#) in the replacement sequence:  
The operator \#, followed by a parameter name, is replaced by a string literal that contains the argument passed (as if enclosed between double quotes):

| 1 2 | \#define str(x) \#x cout \<\< str(test); |
| ----: | :---- |

This would be translated into:

| 1 | cout \<\< "test"; |
| ----: | :---- |

The operator \#\# concatenates two arguments leaving no blank spaces between them:

| 1 2 | \#define glue(a,b) a \#\# b glue(c,out) \<\< "test"; |
| ----: | :---- |

This would also be translated into:

| 1 | cout \<\< "test"; |
| ----: | :---- |

Because preprocessor replacements happen before any C++ syntax check, macro definitions can be a tricky feature. But, be careful: code that relies heavily on complicated macros becomes less readable, since the syntax expected is on many occasions different from the normal expressions programmers expect in C++.

#### Conditional inclusions (\#ifdef, \#endif, \#ifndef, \#if, \#else and \#elif) {#conditional-inclusions-(#ifdef,-#endif,-#ifndef,-#if,-#else-and-#elif)}

**These directives allow to include or discard part of the code of a program if a certain condition is met.**

\#ifdef allows a section of a program to be compiled only if the macro that is specified as the parameter has been defined, no matter which its value is. For example:

| 1 2 3 | \#ifdef TABLE\_SIZE int table\[TABLE\_SIZE\]; \#endif  |
| ----: | :---- |

In this case, the line of code int table\[TABLE\_SIZE\]; is only compiled if TABLE\_SIZE was previously defined with \#define, independently of its value. If it was not defined, that line will not be included in the program compilation.

\#ifndef serves for the exact opposite: the code between \#ifndef and \#endif directives is only compiled if the specified identifier has not been previously defined. For example:

| 1 2 3 4 | \#ifndef TABLE\_SIZE \#define TABLE\_SIZE 100 \#endif int table\[TABLE\_SIZE\]; |
| ----: | :---- |

**Chained directives**  
The \#if, \#else and \#elif (i.e., "else if") directives serve to specify some condition to be met in order for the portion of code they surround to be compiled. The condition that follows \#if or \#elif can only evaluate constant expressions, including macro expressions. For example:

| 1 2 3 4 5 6 7 8 9 10 11 12 13 14 | \#if TABLE\_SIZE\>200 \#undef TABLE\_SIZE \#define TABLE\_SIZE 200   \#elif TABLE\_SIZE\<50 \#undef TABLE\_SIZE \#define TABLE\_SIZE 50   \#else \#undef TABLE\_SIZE \#define TABLE\_SIZE 100 \#endif   int table\[TABLE\_SIZE\]; |
| ----: | :---- |

The behavior of \#ifdef and \#ifndef can also be achieved by using the special operators defined and \!defined respectively in any \#if or \#elif directive:

| 1 2 3 4 5 6 7 | \#if defined ARRAY\_SIZE \#define TABLE\_SIZE ARRAY\_SIZE \#elif \!defined BUFFER\_SIZE \#define TABLE\_SIZE 128 \#else \#define TABLE\_SIZE BUFFER\_SIZE \#endif |
| ----: | :---- |

#### Line control (\#line) {#line-control-(#line)}

Skipped

#### Error directive (\#error) {#error-directive-(#error)}

This directive aborts the compilation process when it is found, generating a compilation error that can be specified as its parameter:

| 1 2 3 | \#ifndef \_\_cplusplus \#error A C++ compiler is required\! \#endif |
| ----: | :---- |

This example aborts the compilation process if the macro name \_\_cplusplus is not defined (this macro name is defined by default in all C++ compilers).

#### Source file inclusion (\#include) {#source-file-inclusion-(#include)}

**When the preprocessor finds an \#include directive it replaces it by the entire content of the specified header or file.**

## Input/Output with files {#input/output-with-files}

* [ofstream](https://cplusplus.com/ofstream): Stream class to write on files  
* [ifstream](https://cplusplus.com/ifstream): Stream class to read from files  
* [fstream](https://cplusplus.com/fstream): Stream class to both read and write from/to files.

| // basic file operations \#include \<iostream\> \#include \<fstream\> using namespace std; int main () {   ofstream myfile;   myfile.open ("example.txt");   myfile \<\< "Writing this to a file.\\n";   myfile.close();   return 0; } | \[file example.txt\] Writing this to a file. |
| :---- | :---- |

### Open a file {#open-a-file}

In order to open a file with a stream object we use its member function open:

open (filename, mode);

Where filename is a string representing the name of the file to be opened, and mode is an optional parameter with a combination of the following flags:

| ios::in | Open for input operations. |
| :---- | :---- |
| ios::out | Open for output operations. |
| ios::binary | Open in binary mode. |
| ios::ate | Set the initial position at the end of the file. If this flag is not set, the initial position is the beginning of the file. |
| ios::app | All output operations are performed at the end of the file, appending the content to the current content of the file. |
| ios::trunc | If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.  |

All these flags can be combined using the bitwise operator OR (|). For example, if we want to open the file example.bin in binary mode to add data we could do it by the following call to member function open:

|  | ofstream myfile; myfile.open ("example.bin", ios::out | ios::app | ios::binary); |
| :---- | :---- |

Each of the open member functions of classes ofstream, ifstream and fstream has a default mode that is used if the file is opened without a second argument:

| class | default mode parameter |
| :---- | :---- |
| ofstream | ios::out |
| ifstream | ios::in |
| fstream | ios::in | ios::out  |

File streams opened in *binary mode* perform input and output operations independently of any format considerations. Non-binary files are known as *text files*, and some translations may occur due to formatting of some special characters (like newline and carriage return characters).

Since the first task that is performed on a file stream is generally to open a file, these three classes include a constructor that automatically calls the open member function and has the exact same parameters as this member. Therefore, we could also have declared the previous myfile object and conduct the same opening operation in our previous example by writing:

| 1 | ofstream myfile ("example.bin", ios::out | ios::app | ios::binary);  |
| ----: | :---- |

To check if a file stream was successful opening a file, you can do it by calling to member is\_open. This member function returns a bool value of true in the case that indeed the stream object is associated with an open file, or false otherwise:

| 1 | if (myfile.is\_open()) { /\* ok, proceed with output \*/ } |
| ----: | :---- |

#### Closing a file {#closing-a-file}

This member function takes flushes the associated buffers and closes the file:

| 1 | myfile.close(); |
| ----: | :---- |

#### Text files {#text-files}

Text file streams are those where the ios::binary flag is not included in their opening mode. These files are designed to store text and thus all values that are input or output from/to them can suffer some formatting transformations, which do not necessarily correspond to their literal binary value.

Writing operations on text files are performed in the same way we operated with cout:

| // writing on a text file \#include \<iostream\> \#include \<fstream\> using namespace std; int main () {   ofstream myfile ("example.txt");   if (myfile.is\_open())   {     myfile \<\< "This is a line.\\n";     myfile \<\< "This is another line.\\n";     myfile.close();   }   else cout \<\< "Unable to open file";   return 0; } | \[file example.txt\] This is a line. This is another line. |
| :---- | :---- |

Reading from a file can also be performed in the same way that we did with cin:

| // reading a text file \#include \<iostream\> \#include \<fstream\> \#include \<string\> using namespace std; int main () {   string line;   ifstream myfile ("example.txt");   if (myfile.is\_open())   {     while ( getline (myfile,line) )     {       cout \<\< line \<\< '\\n';     }     myfile.close();   }   else cout \<\< "Unable to open file";    return 0; } | This is a line. This is another line.  |
| :---- | :---- |

[image1]: <data:image/png;base64,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>

[image2]: <data:image/png;base64,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>

[image3]: <data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAARsAAABZAgMAAABzpGhhAAAADFBMVEXAwMD///8AAP8AAACfbIs7AAAAAXRSTlMAQObYZgAAASxJREFUeF7t2LEKwjAQBuDWdBKhOjvoCwhd3ASLs+AT+AI+haPPIo7OUtEHKLiLuwgtdFSqbUNNMgQuOUHlviFt7uDnWoqVOg6mkVoAa9RniVCFq3KOShWuzGF3P2e+2gJhxZLvzpN5Z6X2IN73x84HcqL3KZxXLOwQZ8Fsr/bIS6DZAbjjSNymbXEHgTQP+S3K82MqdYd9cd+/mO26H/gds0I5epSjRzl6yDluKFXhkOfxjN/HHPI87fJ/mQWsefgcoVQ0wOfZXOUyGNp1NdfFId8v1A5Iyo+NpVg1gHVdlKNHOXqUo0c5ev+a85WY3be6mt0nthLWfS5zgmQcsbvaAnGLxU8Tp1e/o41U18Xi6SCL5A4M6v1BgJvzCLanVih3YPg8szi7yQ3y1557KizD60NrggAAAABJRU5ErkJggg==>