## Chapter 2 Data I

To **store** an item of information in a computer 

- Where the information is stored
- What value is kept there
- What kind of information is stored

#### 1 General knowledge

**Name of Variables**

- The only characters you can use in names are alphabetic characters, numeric digits,
  and the underscore (_) character.
- The first character in a name cannot be a numeric digit.
- Uppercase characters are considered distinct from lowercase characters.
- You can’t use a C++ keyword for a name.
- Names beginning with **two underscore** characters or with **an underscore character**
  **followed by an uppercase letter** are reserved for use by the implementation—that is,
  the compiler and the resources it uses. Names **beginning with a single underscore**
  **character are reserved for use as global identifiers** by the implementation.

If you want to form a name from two or more words:

```c++
int my_onions, myEyeTooth;
```

**Initialization**

Initialization combines assignment with declaration. 

```c++
int uncles = 5; // initialize uncles to 5
int aunts = uncles; // initialize aunts to 5
int chairs = aunts + uncles + 4; // initialize chairs to 14

int wrens(432); // alternative C++ syntax, set wrens to 432
int emus{7}; // set emus to 5
int rheas = {12}; // set rheas to 12
int rocs = {}; // set rocs to 0
int psychics{}; // set psychics to 0
```



#### 2 short, int, long and long long

Integers are numbers with no fractional part. A language can represent only
a subset of all integers.

The various C++ integer types differ in the amount of memory they use to hold an integer and thus the range of integers that they can represent.

- A short integer is **at least** 16 bits wide.
- An int is **at least** as big as short.
- A long is at least 32 bits wide and at least as big as int.
- A long long is at least 32 bits wide and at least as big as long.

You can set a 16-bit unit to 65,536 different values, a 32-bit unit to 4,294,672,296 different values, and a 64-bit unit to 18,446,744,073,709,551,616 different values. 

The four types—int, short, long,and long long—are **signed** types, meaning each
splits its range **approximately** equally between positive and negative values.

```c++
#include <iostream>
#include <cmath>
int main()
{
	using namespace std;
	int n_int = INT_MAX; // INI_MAX is included by iostream
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	// sizeof operator yields size of type or of variable
    // You can apply the sizeof operator to a type name or to a variable name.
	cout << "int is " << sizeof(int) << " bytes." << endl;
	cout << "short is " << sizeof n_short << " bytes." << endl;
	cout << "long is " << sizeof n_long << " bytes." << endl;
	cout << "long long is " << sizeof n_llong << " bytes." << endl;
	cout << endl;

	cout << "Maximum values:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl << endl;
	cout << "Minimum int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;
	cin.get();
	return 0;
}
/*
int is 4 bytes.
short is 2 bytes.
long is 4 bytes.
long long is 8 bytes.

Maximum values:
int: 2147483647
short: 32767
long: 2147483647
long long: 9223372036854775807

Minimum int value = -2147483648
Bits per byte = 8
*/
```

The preprocessor looks for independent tokens (separate words) and **skips embedded words.**

That is, the preprocessor does not replace PINT_MAXIM with P32767IM

```c++
#include <iostream>
int main()
{
	using namespace std;
	int chest = 42; // decimal integer literal
	int waist = 0x42; // hexadecimal integer literal
	int inseam = 042; // octal integer literal
	cout << "Monsieur cuts a striking figure!\n";
	cout << "chest = " << chest << " (42 in decimal)\n";
	cout << "waist = " << waist << " (0x42 in hex)\n";
	cout << "inseam = " << inseam << " (042 in octal)\n";
	return 0;
}
/*
Monsieur cuts a striking figure!
chest = 42 (42 in decimal)
waist = 66 (0x42 in hex)
inseam = 34 (042 in octal)
*/

// display values in hex and octal
#include <iostream>
using namespace std;
int main()
{
	using namespace std;
	int chest = 42;
	int waist = 42;
	int inseam = 42;
	cout << "Monsieur cuts a striking figure!" << endl;
	cout << "chest = " << chest << " (decimal for 42)" << endl;
	cout << hex; // manipulator for changing number base
	cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
	cout << oct; // manipulator for changing number base
	cout << "inseam = " << inseam << " (octal for 42)" << endl;
	cin.get();
	return 0;
}
/*
Monsieur cuts a striking figure!
chest = 42 (decimal for 42)
waist = 2a (hexadecimal for 42)
inseam = 52 (octal for 42)
*/
```

cout << hex does not display anything on the screen. Instead, it changes the way cout displays integers. hex is part of the std namespace and the usage of it relies on the code "using namespace std;".

#### 3 Unsigned type

```c++
unsigned short change; // unsigned short type
unsigned int rovert; // unsigned int type
unsigned quarterback; // also unsigned int
unsigned long gone; // unsigned long type
unsigned long long lang_lang; // unsigned long long type
```

**How C++ decides what type a constant is?**

```c++
cout << "Year = " << 1492 << "\n";
// What is the type of 1492?
// C++ stores integer constants as type int unless there is a reason to do otherwise
// Two such reasons are if you use a special suffix to indicate a particular type or if a value is too large to be an int.
```

- A decimal integer without a suffix is represented by the smallest of the following types that can hold it: : int, long, or long long
- A hexadecimal or octal integer without a suffix is represented by the smallest
  of the following types that can hold it: int, **unsigned int**, long, unsigned long, long
  long, or unsigned long long

#### 4 Char

The char type is another integer type. It’s guaranteed to be **large enough** to represent the entire
range of basic symbols—all the letters, digits, punctuation,and the like—for the target
computer system.

```c++
#include <iostream>
int main()
{
	using namespace std;
	char ch = 'M'; // assign ASCII code for M to ch
	int i = ch; // store same code in an int
	cout << "The ASCII code for " << ch << " is " << i << endl;
	cout << "Add one to the character code:" << endl;
	ch = ch + 1; // change character code in ch
	i = ch; // save new character code in i
	cout << "The ASCII code for " << ch << " is " << i << endl;
	// using the cout.put() member function to display a char
	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);
	// using cout.put() to display a char constant
	cout.put('!');
	cout << endl << "Done" << endl;
	return 0;
}
// Because ch is really an integer, you can apply integer operations to it, such as adding 1.
```

cin converts M to 77 for assignment of char variable. cout converts 77 to M for displaying.

We use cout.put(), a member function in the above program. A member function belongs to a **class** and describes a method for manipulating class data.

The ostream class has a put() member function that is designed to output **characters**.

The notation cout.put() means to use the class member function put() with the class object cout.

```c++
cout << '$'; 
cout.put('$')
    
#include <iostream>
int main()
{
	using namespace std;
	cout << "\aOperation \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\aYou entered " << code << "...\n";
	cout << "\aCode verified! Proceed with Plan Z3!\n";
	return 0;
}
/*
Operation "HyperHype" is now activated!
Enter your agent code:42007007
You entered 42007007...
Code verified! Proceed with Plan Z3!
*/
```

**signed char and unsigned char**

char is not signed **by default**.

```c++
char fodo; // may be signed, may be unsigned
unsigned char bar; // definitely unsigned
signed char snark; // definitely signed
```

These distinctions are particularly important if you use char as a **numeric type**. On the other hand, if you use a char variable to hold a standard ASCII character, it doesn’t really matter
whether char is signed or unsigned, so you can simply use char



#### 5 bool Type

In computing,a Boolean variable is one whose value can be either true or false.

C++ interprets nonzero values as true and zero values as false. 



```c++
bool is_ready = true;
// The literals true and false can be converted to int
int ans = true; // ans assigned 1
int promise = false; // promise assigned 0

bool start = -100; // start assigned true
bool stop = 0; // stop assigned false
```

#### 6 The const Qualifier

- suggest that the constant represents
- easy to modify

```c++
const int Months = 12; // Months is symbolic constant for 12
// A common practice is to capitalize the first character in a name to help remind yourself that Months is a constant

// The following initialization is invalid
const int toes; // value of toes undefined at this point
toes = 10; // too late!
```

#### 7 Float-Point Numbers

- represent numbers with fractional parts
- provide a much greater range in values

```c++
// writing floating-point numbers
12.34 // floating-point
939001.32 // floating-point
0.00023 // floating-point
8.0 // still floating-point
2.52e+8 // can use E or e, + is optional
8.33E-4 // exponent can be negative
7E5 // same as 7.0E+05
-18.32e13 // can have + or - sign in front
1.69e12 // 2010 Brazilian public debt in reais
5.98E24 // mass of earth in kilograms
9.11e-31 // mass of an electron in kilograms
```

 three floating-point types: float, double,and long double. You can look in the cfloat or
float.h header files to find the ranges of three types for your system.

```c++
// the following are the minimum number of significant digits
#define DBL_DIG 15 // double
#define FLT_DIG 6 // float
#define LDBL_DIG 18 // long double
// the following are the number of bits used to represent the mantissa
#define DBL_MANT_DIG 53
#define FLT_MANT_DIG 24
#define LDBL_MANT_DIG 64
// the following are the maximum and minimum exponent values
#define DBL_MAX_10_EXP +308
#define FLT_MAX_10_EXP +38
#define LDBL_MAX_10_EXP +4932
#define DBL_MIN_10_EXP -307
#define FLT_MIN_10_EXP -37
#define LDBL_MIN_10_EXP -4931
```

**Display the floating numbers**

Normally cout drops trailing zeros. The call to cout.setf() overrides that behavior,at least in new implementations

```c++
#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
	float tub = 10.0 / 3.0; // good to about 6 places
	double mint = 10.0 / 3.0; // good to about 15 places
	const float million = 1.0e6;
	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ",\nand ten million tubs = ";
	cout << 10 * million * tub << endl;
	cout << "mint = " << mint << " and a million mints = ";
	cout << million * mint << endl;
	return 0;
}
/*
tub = 3.333333, a million tubs = 3333333.250000,
and ten million tubs = 33333332.000000
mint = 3.333333 and a million mints = 3333333.333333
*/
```

**Floating-point Constants**

```c++
1.234f // a float constant
2.45E20F // a float constant
2.345324E28 // a double constant(default)
2.2L // a long double constant
```

#### 8 Arithmetic Operators

%: If one of the operands is negative, the sign of the result satisfies the following rule: (a/b)*b + a%b equals a.

**Remark**: the limited capacity of type float. 

#### 9 Type Conversions

- when you assign a value of one arithmetic type to a variable of another arithmetic type
- when you combine mixed types in expressions
- when you pass arguments to functions

**Initialization and Assignment**

You can assign a numeric value of one type to a variable of another type through (implicit) type conversions.

**Assigning a value to a type with a greater range usually poses no problem**

**However,assigning a large long value such as 2111222333 to a float variable results in the loss of some precision**.

double to float, bigger integer type to smaller integer type, floating type to integer type

A zero value assigned to a bool variable is converted to false,and a nonzero value is
converted to true

```c++
#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3; // int converted to float
	int guess(3.9832); // double converted to int
	int debt = 7.2E12; // result not defined in C++, too big for an int
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	return 0;
}
/*
tree = 3.000000
guess = 3
debt = 1634811904
*/
```

**Conversions in Expressions**

First, some types are automatically converted whenever they occur. Second, some types are converted when they are combined with other types in an expression.

```c++
short chickens = 20; // line 1
short ducks = 35; // line 2
short fowl = chickens + ducks; // line 3
```

To execute the statement in line 3, a C++ program convert chickens and ducks into type int and convert the result back to type short.

There are more integral promotions:The unsigned short type is converted to int if
short is smaller than int. If the two types are the same size, unsigned short is converted to unsigned int. This rule ensures that there’s no data loss in promoting
unsigned short.

1. If either operand is type **long double**, the other operand is converted to long
double.
2. Otherwise, if either operand is **double**, the other operand is converted to double.
3. Otherwise, if either operand is **float**, the other operand is converted to float.
4. Otherwise, the operands are **integer types** and the integral promotions are made.
5. In that case, if both operands are signed or if both are unsigned,and one is of lower
rank than the other, it is converted to the higher rank.
6. Otherwise, one operand is signed and one is unsigned. If the unsigned operand is of
higher rank than the signed operand, the latter is converted to the type of the
unsigned operand.
7. Otherwise, if the signed type can represent all values of the unsigned type, the
unsigned operand is converted to the type of the signed type.
8. Otherwise, both operands are converted to the unsigned version of the signed type.

**Conversions in Passing Arguments**



**Type casts**

```c++
(long) thorn // returns a type long conversion of thorn
long (thorn) // returns a type long conversion of thorn
cout << int('Q'); // displays the integer code for 'Q'

```



#### 10 Auto Declarations

```c++
auto n = 100; // n is int
auto x = 1.5; // x is double
auto y = 1.3e12L; // y is long double

auto x = 0.0; // ok, x is double because 0.0 is double
double y = 0; // ok, 0 automatically converted to 0.0
auto z = 0; // oops, z is int because 0 is int

std::vector<double> scores;
std::vector<double>::iterator pv = scores.begin();
// can be written as 
std::vector<double> scores;
auto pv = scores.begin();
```

Automatic type deduction becomes much more useful when dealing with complicated types, such as those in the STL (Standard Template Library).


