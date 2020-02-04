## Chapter 3 Data II

#### 1 array, vector

An array is a data form that can hold several values, **all of one type**. To create an array, you use a declaration statement. Each element of the array, in essence, is a variable that you can treat as a simple variable.

```c++
// typeName arrayName[arraySize]
short months[12]; // Creates array of 12 shorts
```

arraySize cannot be a variable whose value is set while the program is running. (See **new**)

```c++
#include <iostream>
int main()
{
	using namespace std;
	int yams[3]; // creates array with three elements
	yams[0] = 7; // assign value to first element
	yams[1] = 8;
	yams[2] = 6;
	int yamcosts[3] = {20, 30, 5}; // create, initialize array
	// NOTE: If your C++ compiler or translator can't initialize
	// this array, use static int yamcosts[3] instead of
	// int yamcosts[3]
	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs ";
	cout << yamcosts[1] << " cents per yam.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "The total yam expense is " << total << " cents.\n";
	cout << "\nSize of yams array = " << sizeof yams;
	cout << " bytes.\n";
	cout << "Size of one element = " << sizeof yams[0];
	cout << " bytes.\n";
	return 0;
}
```

- If you don’t initialize an array that’s defined inside a function, the element values remain undefined.That means the element takes on whatever value previously resided at that location in memory.
- Note that if you use the sizeof operator with an array name, you get the number
  of bytes in the whole array

**Initialization**

You can use the initialization form **only when defining the array**. You cannot use it later,
and you cannot assign one array wholesale to another:

```c++
int cards[4] = {3, 6, 8, 10}; // okay
int hand[4]; // okay
hand[4] = {5, 6, 7, 9}; // not allowed
hand = cards; // not allowed

// If you partially initialize an array, the compiler sets the remaining elements to zero
long totals[500] = {0}; // set all elements to 0
long totals[500] = { }; // set all elements to 0, OK in C++11	

short things[] = {1, 5, 3, 8}; // compiler will count the elements
int num_elements = sizeof things / sizeof (short);
```

#### 2 Strings

A string is a series of characters stored in consecutive bytes of memory. C++ has two ways of dealing with strings.

- C-style: char array ends with '\0'
- string class

```c++
char bird[11] = "Mr. Cheeps"; // the \0 is understood
char fish[] = "Bubbles"; // let the compiler count

#include <iostream>
#include <cstring> // for the strlen() function
int main()
{
	using namespace std;
	const int Size = 15;
	char name1[Size]; // empty array
	char name2[Size] = "C++owboy"; // initialized array
	// NOTE: some implementations may require the static keyword
	// to initialize the array name2
	cout << "Howdy! I'm " << name2;
	cout << "! What's your name?\n";
	cin >> name1;
	cout << "Well, " << name1 << ", your name has ";
	cout << strlen(name1) << " letters and is stored\n";
	cout << "in an array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	name2[3] = '\0'; // set to null character
	cout << "Here are the first 3 characters of my name: ";
	cout << name2 << endl;
	return 0;
}
/*
Howdy! I'm C++owboy! What's your name?
Basicman
Well, Basicman, your name has 8 letters and is stored
in an array of 15 bytes.
Your initial is B.
Here are the first 3 characters of my name: C++
*/
```

Sizeof operator gives the size of the **entire array**,  but the strlen() function returns the size of the string stored in the array and not the size of the array itself. Also strlen() counts just the visible characters and **not the null character.**

**C-style String input**

```c++
#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your favorite dessert:\n";
	cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}
/*
Enter your name:
Alistair Dreeb
Enter your favorite dessert:
I have some delicious Dreeb for you, Alistair.
*/
```

 This code is not good! How cin determines when you’ve finished entering a string? In this example, cin stop the input of the string when it meets a space.

You can’t enter the null character from the keyboard, so cin needs some other means for
locating the end of a string. The cin technique is to use whitespace—spaces, tabs,and
newlines—to delineate a string

The input string might turn out to be longer than the destination array. 

Thus, cin is not good enough for string input.

```c++
// cin.getline(stringName, int maxLength), maxLength includes null character
cin.getline(name, 20);
// cin.getline(name, 20) ends with a tab, so it can receive blace
// cin read and discard the tab
#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "Enter your name:\n";
	cin.getline(name, ArSize); // reads through newline
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}

// cin.get(name, ArSize)
// cin.get() leaves tab in the input queue!!!
cin.get(name, ArSize);
cin.get(dessert, Arsize); // a problem

cin.get(name, ArSize); // read first line
cin.get(); // read newline
cin.get(dessert, Arsize); // read second line

cin.get(name, ArSize).get(); // cin.get(name, ArSize) returns the cin object, so it also work
cin.get(dessert, Arsize); // read second line

cin.getline(name1, ArSize).getline(name2, ArSize);// work

```

**Trick**: How can you tell if it read the whole line rather than stopped because the array was filled? Look at the next input character. If it is a tab, then the whole line was read.

**failbit**

If cin.get() reads an empty line, it sets something called failbit and blocks the input.

You can restore input with cin.clear();

If the input line is longer than the number of characters specified, both get and getline will leave the remaining characters in the input queue. However, only getline() will set the failbit.

```c++
#include <iostream>
int main()
{
	using namespace std;
	cout << "What year was your house built?\n";
	int year;
	cin >> year;
	cout << "What is its street address?\n";
	char address[80];
	// cin.get();
    cin.getline(address, 80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";
	return 0;
}
// doesnot work without line 10
// since cin leave the tab in the input queue
```

**String class**

To use string class, you must include the string header file.

```c++
#include <iostream>
#include <string> // make string class available
int main()
{
	using namespace std;
	char charr1[20]; // create an empty array
	char charr2[20] = "jaguar"; // create an initialized array
	// The class design allows the program to handle the sizing automatically!!
    string str1; // create an empty string object
	string str2 = "panther"; // create an initialized string
	
    cout << "Enter a kind of feline: ";
	cin >> charr1;
	cout << "Enter another kind of feline: ";
	cin >> str1; // use cin for input
	cout << "Here are some felines:\n";
	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2 // use cout for output
		<< endl;
	cout << "The third letter in " << charr2 << " is "
		<< charr2[2] << endl;
	cout << "The third letter in " << str2 << " is "
		<< str2[2] << endl; // use array notation
	return 0;
}
/*
Enter a kind of feline: ocelot
Enter another kind of feline: tiger
Here are some felines:
ocelot jaguar tiger panther
The third letter in jaguar is g
The third letter in panther is n
*/
```

- You can initialize a string object to a C-style string
- You can use cin to store keyboard input in a string object.
- You can use cout to display a string object.
- You can use array notation to access individual characters stored in a string object.

cin 接受一个字符串，通过 blank,TAB,\n来确定字符串结束位置, 遇到blank,tab结束输入,两个cin之间任意多的tab blank将会被舍弃.

**Note that you can add and append C-style strings as well as string objects to a string object.**

```c++
char charr1[20]; // create an empty array
char charr2[20] = "jaguar"; // create an initialized array
string str1; // create an empty string object
string str2 = "panther"; // create an initialized string
charr1 = charr2; // INVALID, no array assignment
str1 = str2; // VALID, object assignment ok

string str3;
str3 = str1 + str2; // assign str3 the joined strings
str1 += str2; // add str2 to the end of str1

char str1[] = "This is a c-style string";
string str2 = "This is a cpp-style string";
string str3 = str1 + str2; // valid

#include <iostream>
#include <string> // make string class available
int main()
{
	using namespace std;
	string s1 = "penguin";
	string s2, s3;
	cout << "You can assign one string object to another: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "You can assign a C-style string to a string object.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;
	cout << "You can concatenate strings: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "You can append strings.\n";
	s1 += s2;
	cout <<"s1 += s2 yields s1 = " << s1 << endl;
	s2 += " for a day";
	cout <<"s2 += \" for a day\" yields s2 = " << s2 << endl;
	return 0;
}
```

**More string class operation**

There are some functions to assign c-style strings. 

```c++
strcpy(charr1, charr2); // copy charr2 to charr1
strcat(charr1, charr2); // append contents of charr2 to char1

#include <iostream>
#include <string> // make string class available
#include <cstring> // C-style string library
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";	
	string str1;
	string str2 = "panther";
	// assignment for string objects and character arrays
	str1 = str2; // copy str2 to str1
	strcpy(charr1, charr2); // copy charr2 to charr1
	// appending for string objects and character arrays
	str1 += " paste"; // add paste to end of str1
	strcat(charr1, " juice"); // add juice to end of charr1
	// finding the length of a string object and a C-style string
	int len1 = str1.size(); // obtain length of str1
	int len2 = strlen(charr1); // obtain length of charr1
	cout << "The string " << str1 << " contains "
		<< len1 << " characters.\n";
	cout << "The string " << charr1 << " contains "
		<< len2 << " characters.\n";
	return 0;
}
/*
The string panther paste contains 13 characters.
The string jaguar juice contains 12 characters.
*/
```

Note that both str.size() and strlen does not count the null.

**string input and output**

```c++
#include <iostream>
#include <string> // make string class available
#include <cstring> // C-style string library
int main()
{
	using namespace std;
	char charr[20];
	string str;
	cout << "Length of string in charr before input: "
		<< strlen(charr) << endl;
	cout << "Length of string in str before input: "	
		<< str.size() << endl;
	cout << "Enter a line of text:\n";
	cin.getline(charr, 20); // indicate maximum length
	cout << "You entered: " << charr << endl;
	cout << "Enter another line of text:\n";
	getline(cin, str); // cin now an argument; no length specifier
	cout << "You entered: " << str << endl;
	cout << "Length of string in charr after input: "
		<< strlen(charr) << endl;
	cout << "Length of string in str after input: "
		<< str.size() << endl;
	return 0;
}
/*
Length of string in charr before input: 27 (possibly different)
Length of string in str before input: 0
Enter a line of text:
peanut butter
You entered: peanut butter
Enter another line of text:
blueberry jam
You entered: blueberry jam
Length of string in charr after input: 13
Length of string in str after input: 13
*/
```

#### 4 Structure

A structure can hold items of more than one data type. A structure is a user-definable type, with a structure declaration serving to define the type’s data properties.

```c++
struct inflatable // structure declaration
{
	char name[20];
	float volume;
	double price;
};
struct inflatable goose; // keyword struct required in C
inflatable vincent; // keyword struct not required in C++
// In C++, the structure tag is used just like a fundamental type name.This change emphasizes that a structure declaration defines a new type.
```

**More operations of structure**

```c++
#include <iostream>
struct inflatable // structure declaration
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
    // As with arrays, you use a comma-separated list of values enclosed in a pair of braces
	inflatable guest =
	{
		"Glorious Gloria", // name value
		1.88, // volume value
		29.99 // price value
	}; // guest is a structure variable of type inflatable
// It's initialized to the indicated values
	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	}; // pal is a second variable of type inflatable
// NOTE: some implementations require using
// static inflatable guest =
	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n";
// pal.name is the name member of the pal variable
	cout << "You can have both for $";
	cout << guest.price + pal.price << "!\n";
	return 0;
}
```

**Using a string class in structure**

```c++
#include <string>
// using namespace std
struct inflatable // structure definition
{
	std::string name;
	float volume;
	double price;
};
// Make sure that the structure definition has access to the std namespace
// You can do this by moving the using directive so that it is above the structure definition.The better choice,as shown previously, is to declare name as having type std::string
```

you can pass structures as arguments to a function,and you can have a function use a structure
as a return value.Also you can use the assignment operator (=) to assign one structure to
another of the same type.

```c++
#include <iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable bouquet =
	{
		"sunflowers",
		0.20,
		12.49
	};
	inflatable choice;
	cout << "bouquet: " << bouquet.name << " for $";
	cout << bouquet.price << endl;
	choice = bouquet; // assign one structure to another
	cout << "choice: " << choice.name << " for $";
	cout << choice.price << endl;
	return 0;
}
/*
bouquet: sunflowers for $12.49
choice: sunflowers for $12.49
*/
```

**Use array of structures**

```c++
inflatable gifts[100]; // array of 100 inflatable structures
cin >> gifts[0].volume; // use volume member of first struct
cout << gifts[99].price << endl; // display price member of last struct

inflatable guests[2] = // initializing an array of structs
{
	{"Bambi", 0.5, 21.99}, // first structure in array
	{"Godzilla", 2000, 565.99} // next structure in array
};
```

#### 5 Unions

A union is a data format that can hold different data types but **only one type at a time**.

```c++
union one4all
{
	int int_val;
	long long_val;
	double double_val;
};

one4all pail;
pail.int_val = 15; // store an int
cout << pail.int_val;
pail.double_val = 1.38; // store a double, int value is lost
cout << pail.double_val;

struct widget
{
	char brand[20];
	int type;
	union id // format depends on widget type
	{
		long id_num; // type 1 widgets
		char id_char[20]; // other widgets
	} id_val;
};

...
widget prize;
...
if (prize.type == 1) // if-else statement (Chapter 6)
	cin >> prize.id_val.id_num; // use member name to indicate mode
else
	cin >> prize.id_val.id_char;

// You can also use union in a structure like this
struct widget
{
	char brand[20];
	int type;
	union // anonymous union
	{
		long id_num; // type 1 widgets
		char id_char[20]; // other widgets
	};
};
// id_num and id_char are treated as two members of prize that share the same address
...
widget prize;
...
if (prize.type == 1)
	cin >> prize.id_num;
else
	cin >> prize.id_char;
```

**6 Enumerations**

enum is an alternative to const for creating symbolic constants.

```c++
enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};
// red=0, orange=1...
spectrum band; // band a variable of type spectrum

band = blue; // valid, blue is an enumerator
band = 2000; // invalid, 2000 not an enumerator

band = orange; // valid
++band; // not valid, ++ discussed in Chapter 5
band = orange + red; // not valid, but a little tricky
band = spectrum(orange + red); // valid
// spectrum will be converted into int for calculation, but you cannot assign a spectrum with an int

int color = blue; // valid, spectrum type promoted to int
band = 3; // invalid, int not converted to spectrum
color = 3 + red; // valid, red converted to int
```

- It makes spectrum the name of a new type; spectrum is termed an enumeration, much as a struct variable is called a structure.
- It establishes red, orange, yellow,and so on,as symbolic constants for the integer values 0–7.These constants are called enumerators.
- By default, enumerators are assigned integer values starting with 0 for the first enumerator, 1 for the second enumerator,and so forth.

```c++
enum bits{one = 1, two = 2, four = 4, eight = 8};

// Subsequent uninitialized enumerators are larger by 1
one than their predecessors
enum bigstep{first, second = 100, third}; // first=0,third=101
enum {zero, null = 0, one, numero_uno = 1}; // zero=0,one=1
```

**Value range for enumeration**

C++ expands the **list of valid values** that can be assigned to an enumeration variable through the use of a type cast

```c++
enum bits{one = 1, two = 2, four = 4, eight = 8};
bits myflag;

myflag = bits(6); // valid, because 6 is in bits range

```



#### 7 Pointer

A special type of variable— the pointer—holds the address of a value.Thus, the name of the pointer represents the location.

Note that pointer itself is a variable whose value is address and thus we can use another pointer to point to the address of the pointer.

```c++
#include <iostream>
int main()
{
	using namespace std;
	int updates = 6; // declare a variable
	int * p_updates; // declare pointer to an int
    p_updates = &updates; // assign address of int to pointer
	// express values two ways
	cout << "Values: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;
	// express address two ways
	cout << "Addresses: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;
	// use pointer to change value
	*p_updates = *p_updates + 1;
	cout << "Now updates = " << updates << endl;
	return 0;
}
/*
Values: updates = 6, *p_updates = 6
Addresses: &updates = 0x0065fd48, p_updates = 0x0065fd48
Now updates = 7
*/
```

**Declaring and Initializing Pointers**

A computer needs to **keep track of the type** of value to which a pointer refers. (这决定了编译器怎么解释这个地址的bit)

Therefore,a pointer declaration must specify what type of data to which the pointer points.

p_updates **is pointer-to-int** or, more concisely, int * and *p_updates is an int.

```c++
// The following  declaration creates one pointer (p1) and one ordinary int (p2):
int* p1, p2;
// To create two pointers:
int *p1, *p2;

```

**Always initialize a pointer to a definite and appropriate address before you apply the dereferencing operator (*) to it.**

**Allocating Memory with new**

The true worth of pointers comes into play when you allocate unnamed memory during runtime to hold values. In this case, pointers become **the only access to that memory.**

```c++
int * pn = new int;
...
delete pn; // free memory with delete when done
// delete removes the memory to which ps points;

#include <iostream>
int main()
{
	using namespace std;
	int nights = 1001;
	int * pt = new int; // allocate space for an int
	*pt = 1001; // store a value there
	cout << "nights value = ";
	cout << nights << ": location " << &nights << endl;
	cout << "int ";
	cout << "value = " << *pt << ": location = " << pt << endl;
	double * pd = new double; // allocate space for a double
	*pd = 10000001.0; // store a double there
	cout << "double ";
	cout << "value = " << *pd << ": location = " << pd << endl;
	cout << "location of pointer pd: " << &pd << endl;
	cout << "size of pt = " << sizeof(pt);
	cout << ": size of *pt = " << sizeof(*pt) << endl;
	cout << "size of pd = " << sizeof pd;
	cout << ": size of *pd = " << sizeof(*pd) << endl;
	return 0;
}    
/*
nights value = 1001: location 0028F7F8
int value = 1001: location = 00033A98
double value = 1e+007: location = 000339B8
location of pointer pd: 0028F7FC
size of pt = 4: size of *pt = 4
size of pd = 4: size of *pd = 8
*/
```

new uses a different block of memory(**heap**) than do the ordinary variable definitions that we have been using(**stack**).

You should **always** balance a use of new with a use of delete; otherwise, you can wind up with a memory leak.

You should use delete only to free memory **allocated with new**. However, it is safe to apply
delete to a null pointer.

```c++
int * ps = new int; // ok
delete ps; // ok
delete ps; // not ok now
int jugs = 5; // ok
int * pi = &jugs; // ok
delete pi; // not allowed, memory not allocated by new

// You can delete the memory through another pointer
int * ps = new int; // allocate memory
int * pq = ps; // set second pointer to same block
delete pq; // delete with second pointer
```

**Creating a Dynamic Array with new**

```c++
// The new operator returns the address of the first element of the block
// type_name * pointer_name = new type_name [num_elements];
int * psome = new int [10]; // get a block of 10 ints
...
delete [] psome; // free a dynamic array

int * pt = new int;
short * ps = new short [500];
delete [] pt; // effect is undefined, don't do it
delete ps; // effect is undefined, don't do it
```

- Don’t use delete to free memory that new didn’t allocate.
- Don’t use delete to free the same block of memory twice in succession
- It’s safe to apply delete to the null pointer (nothing happens)

you can’t use the sizeof operator to find the number of bytes in a dynamically allocated array

**Use the dynamic array: pointer and array, pointer arithmetic**

```c++
#include <iostream>
int main()
{
	using namespace std;
	double * p3 = new double [3]; // space for 3 doubles
	p3[0] = 0.2; // treat p3 like an array name
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 + 1; // okay for pointers, wrong for array names
	cout << "Now p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 - 1; // point back to beginning
	delete [] p3; // free the memory
	return 0;
}
```

Adding one to a pointer to double adds 8 to the numeric value on systems with 8-byte double, whereas adding one to a pointer-to-short adds two to the pointer value if short is 2 bytes

```c++
#include <iostream>
int main()
{
	using namespace std;
	double wages[3] = {10000.0, 20000.0, 30000.0};
	short stacks[3] = {3, 2, 1};
	// Here are two ways to get the address of an array
    // In most contexts, C++ interprets the name of an array as the address of its first element.
	double * pw = wages; // name of an array = address
	short * ps = &stacks[0]; // or use address operator
	// with array element
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "add 1 to the pw pointer:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;	
	ps = ps + 1;
	cout << "add 1 to the ps pointer:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";
	cout << "access two elements with array notation\n";
	cout << "stacks[0] = " << stacks[0]
		<< ", stacks[1] = " << stacks[1] << endl;
	cout << "access two elements with pointer notation\n";
	cout << "*stacks = " << *stacks
		<< ", *(stacks + 1) = " << *(stacks + 1) << endl;
	cout << sizeof(wages) << " = size of wages array\n";
	cout << sizeof(pw) << " = size of pw pointer\n";
	return 0;
}

arrayname[i] becomes *(arrayname + i)
pointername[i] becomes *(pointername + i)
pointername = pointername + 1; // valid
arrayname = arrayname + 1; // not allowed
```

A difference is that applying the sizeof operator to an array name yields the
size of the array, but applying sizeof to a pointer yields the size of the pointer, even if the
pointer points to the array

**Pointer for string**

- Initialization: "="

- Use strcpy() or strncpy(), not the assignment operator, to assign a string to an array.

```c++
#include <iostream>
#include <cstring> // declare strlen(), strcpy()
int main()
{
	using namespace std;
	char animal[20] = "bear"; // animal holds bear
	const char * bird = "wren"; // bird holds address of string
	char * ps; // uninitialized
	cout << animal << " and "; // display bear
	cout << bird << "\n"; // display wren
	// cout << ps << "\n"; //may display garbage, may cause a crash
	cout << "Enter a kind of animal: ";
	cin >> animal; // ok if input < 20 chars
	// cin >> ps; Too horrible a blunder to try; ps doesn't
	// point to allocated space
	ps = animal; // set ps to point to string
	cout << ps << "!\n"; // ok, same as using animal
	cout << "Before using strcpy():\n";
	cout << animal << " at " << (int *) animal << endl;
	cout << ps << " at " << (int *) ps << endl;
	ps = new char[strlen(animal) + 1]; // get new storage
	strcpy(ps, animal); // copy string to new storage
    cout << "After using strcpy():\n";
	cout << animal << " at " << (int *) animal << endl;
	cout << ps << " at " << (int *) ps << endl;
	delete [] ps;
	return 0;
}
/*
bear and wren
Enter a kind of animal: fox
fox!
Before using strcpy():
fox at 0x0065fd30
fox at 0x0065fd30
After using strcpy():
fox at 0x0065fd30
fox at 0x004301c8
*/
// strncpy(char*, char*, maximumNumber)
// it doesn’t add the null character if stop ealier
strncpy(food, "a picnic basket filled with many goodies", 19);
food[19] = '\0';
```

Normally, if you give cout a pointer, it prints an address. But if the pointer is type
char *, cout displays the pointed-to string. Therefore, in line 24 25 we apply a type cast to display the address.

```c++
char *str3 = "test2"; // invalid
const char *str3 = "test2"; // valid
char *str4;
// str4 = new char [20];
cin >> str4; // without line 4, invalid
```

**Dynamic structures**

Again, dynamic means the memory is allocated during runtime, not at compile time.

Note that difference between ways of visiting elements of pointer and structure.

```c++
#include <iostream>
struct inflatable // structure definition
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
    inflatable * ps = new inflatable; // allot memory for structure
	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20); // method 1 for member access
	cout << "Enter volume in cubic feet: ";
	cin >> (*ps).volume; // method 2 for member access
	cout << "Enter price: $";
	cin >> ps->price;
    cout << "Name: " << (*ps).name << endl; // method 2
	cout << "Volume: " << ps->volume << " cubic feet\n"; // method 
	cout << "Price: $" << ps->price << endl; // method 1
	delete ps; // free memory used by structure
	return 0;
}
/*
Enter name of inflatable item: Fabulous Frodo
Enter volume in cubic feet: 1.4
Enter price: $27.99
Name: Fabulous Frodo
Volume: 1.4 cubic feet
Price: $27.99
*/
```

**Automatic Storage**

In this example, the program allocate memory in a function and free it in main() which is just not good.

```c++
#include <iostream>
#include <cstring> // or string.h
using namespace std;
char * getname(void); // function prototype
int main()
{
	char * name; // create pointer but no storage
	name = getname(); // assign address of string to name
	cout << name << " at " << (int *) name << "\n";
	delete [] name; // memory freed
	name = getname(); // reuse freed memory
	cout << name << " at " << (int *) name << "\n";
	delete [] name; // memory freed again
	return 0;
}
char * getname() // return pointer to new string
{
	char temp[80]; // temporary storage
	cout << "Enter last name: ";
	cin >> temp;
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp); // copy string into smaller space
	return pn; // temp lost when function ends
}
```

C++ has three ways of managing memory for data, depending on the method used to
allocate memory:automatic storage, static storage,and dynamic storage,:automatic storage, static storage,and dynamic storage.

**Automatic storage**

Automatic variables typically are stored on a stack

This means that when program execution enters a block of code, its variables are added consecutively to the stack in memory and then are freed in reverse order when execution leaves the block. (A LIFO process!)

**Static storage**

Static storage is storage that exists throughout the execution of an entire program.

**Dynamic storage: heap**

The new and delete operators provide a more flexible approach than automatic and static variables.

**These methods rigidly define the lifetime of a variable**



```c++
const antarctica_years_end ** ppa = arp;

// mixtypes.cpp -- some type combinations
#include <iostream>
struct antarctica_years_end
{
	int year;
	/* some really interesting data, etc. */
};
int main()
{
	antarctica_years_end s01, s02, s03;
	s01.year = 1998;
	antarctica_years_end * pa = &s02;
	pa->year = 1999;
	antarctica_years_end trio[3]; // array of 3 structures
	trio[0].year = 2003;
	std::cout << trio->year << std::endl;
	const antarctica_years_end * arp[3] = {&s01, &s02, &s03};
	std::cout << arp[1]->year << std::endl;
	const antarctica_years_end ** ppa = arp;
	auto ppb = arp; // C++11 automatic type deduction
	// or else use const antarctica_years_end ** ppb = arp;
	std::cout << (*ppa)->year << std::endl;
	std::cout << (*(ppb+1))->year << std::endl;
	return 0;
}
/*
2003
1999
1998
1999
*/
```

#### 8 vector

Vector is a dynamic array. You can set the size of a vector object during runtime,and you can append new data to the end or insert new data in the middle

Actually, the vector class does **use new and delete** to manage memory,
but it does so automatically.

```c++
#include <vector>
...
// the vector identifier is part of the std namespace, so you can use a using directive,a using declaration, or std::vector.
using namespace std;
// vector<typeName> vt(n_elem);
vector<int> vi; // create a zero-size array of int
int n;
cin >> n; // n can be variable!!!
vector<double> vd(n); // create an array of n doubles
```

#### 9 array

Array template class is part of the std namespace. An array object has a fixed size and uses the stack instead of free store.

```c++
#include <array>
...
using namespace std;
array<int, 5> ai; // create array object of 5 ints
array<double, 4> ad = {1.2, 2.1, 3.43. 4.3};
// More general, the following declaration creates an array object arr with n_elem elements of typeName:
// array<typeName, n_elem> arr;
// Unlike the case for vector, n_elem can’t be a variable.

```



#### 10 Summary

```c++
// choices.cpp -- array variations
#include <iostream>
#include <vector> // STL C++98
#include <array> // C++11
int main()
{
	using namespace std;
	// C, original C++
	double a1[4] = {1.2, 2.4, 3.6, 4.8};
	// C++98 STL
	vector<double> a2(4); // create vector with 4 elements
	// no simple way to initialize in C98
	a2[0] = 1.0/3.0;
	a2[1] = 1.0/5.0;
	a2[2] = 1.0/7.0;
	a2[3] = 1.0/9.0;
	// C++11 -- create and initialize array object
	array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
	array<double, 4> a4;
	a4 = a3; // valid for array objects of same size
	// use array notation
	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	// misdeed
	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] <<" at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	return 0;
}
/*
a1[2]: 3.6 at 0x28cce8
a2[2]: 0.142857 at 0xca0328
a3[2]: 1.62 at 0x28ccc8
a4[2]: 1.62 at 0x28cca8
a1[-2]: 20.2 at 0x28ccc8
a3[2]: 20.2 at 0x28ccc8
a4[2]: 1.62 at 0x28cca8
*/
```

- All data-type access the individual element in the same way (index).

-  you can assign an array object to another array object. For built-in arrays, you have to copy the data element-by-element

1) 模板类vector



  #include <vector>
  a)  定义： int * ps = new int; // ok
delete ps; // ok
delete ps; // not ok now
int jugs = 5; // ok
int * pi = &jugs; // ok
delete pi; // not allowed, memory not allocated by new
            vector <int> a1;      //定义长度为0的int型vector
            vector <int> a2(10);  //定义长度为10的int型vector 
  b)  vector类似string类，是一种动态数组，可以在运行阶段设置vector对象的长度，可以在末尾附加信数据，在中间插入新数据
  c)  vector和string类一样，需要std::vector
  d)  在C++11中可以用一个列表初始化vector，而C++98不可以
  e)  vector的空间在堆中，事实上vector是自动完成new和delete的

(2) 模板类array
  #include <array>
  vector 功能很强大，但是长度可变的代价是效率比较低，如果需要长度固定的数组，可以考虑使用array
  a)  定义:
            array<int, 5> ai;  //  5个int的array
            array<double, 4> ad = {1.2,2.1,3.43,4.3};
            与vector不同，array的长度指示不能是变量
  b)  array的空间也在栈中
  c)  可以将一个array对象赋给另一个array对象

vector 和 array 都可以用标准数组表示法来访问元素

a)  一定要在使用接触引用运算符(*)之前给指针赋予一个确定的地址！！ 切忌野指针
b)  不要使用delete来释放不是new分配的内存，例如变量
c)  如果使用new []为数组分配内存，则应该使用delete [] 来进行释放
d)  如果使用new 为一个实体来分配内存，则应该使用delete(无方括号) 来进行释放
e)  对空指针应用delete是安全的

RK: 在cout和大多数的C++表达式中，char数组名、char指针以及用引号括起的字符串常量都被解释成字符串中第一个地址的地址。
    一般而言，给cout提供一个指针，它将打印地址(值)，但是对char*，它将打印这个字符串，要打印字符串的地址，应当做(int *)ps的强制转换
     
(a) 将函数参数(变量化)
(b) 实现在不同时间传递不同的函数参数

(1) 获取函数的地址:eg: int think();
process(think); //  将函数名(不跟参数)传入就是将函数地址传入
thought(think()); //  将函数返回值作为参数传入

(2) 函数指针: 指明函数类型
double pam(int);
double (*pf)(int);  //  pf是一个函数指针，他指向一个有一个int参数，返回值为double的函数
一般而言，将函数声明中的函数名替换为(*pf)就是这类函数的指针。
pf = pam;
使用函数指针的时候，只需要把(*pf)~函数名pam即可





The sample of Union's syntax

union one4all
{
  int int_val;
  long long_val;
  double double_val;
};

one4fall pail;
pail.int_val = 16;
pail.double_val = 1.38;

a)  one4all共用体可能是int,long,double，但某一时间它只能是其中一种类型，因此共用体的长度为最大成员的长度
b)  共用体常常用于(但并非只用于)节省内存
c)  在一些有数据的类型不定的情形共用体得到应用(见sample code)





a)  Compare char[Size] with string, string更像是字符串的instance，而前者更像是存储一个字符串的存储单元
b)  类设计让程序可以自动处理string的大小，例如str1声明长度是0，而cin之后将自动调整其长度





(1) 基本输入
  对C-style的数组字符串，在初始化的时候可以用 '='
  而在之后进行赋值应该使用strcpy(charr1,charr2)  strncpy(charr1,charr2,n) 最多复制n个字符到charr1，而后自动补'\0'

(2) 利用C++中的几个函数进行输入

C++ primer plus 对C 风格的字符串的输入主要是针对三个函数 cin/cin.getline()/cin.get()来进行讨论的

cin:

a)  cin 接受一个字符串，通过 blank,TAB,\n来确定字符串结束位置 
b)  遇到blank,tab,\n结束输入,两个cin之间任意多的tab blank \n 将会被舍弃

cin.getline(arrname, N):

a)  cin.getline()读取整行，通过回车键输入的换行符确定输入结尾,因此可以接受空格 
b)  最多读取N-1个字符到arrname中,多余的字b)  cin.getline()读取整行，通过回车键输入的换行符确定输入结尾 留在缓冲区，这些字符将会被之后的输入函数捕获
c)  RK: getline会将缓冲区的换行符直接读入结束输入！getline会读取换行符，但是会把它替换为空,这意味着如果你在连续cin.getline()读取数据的时候，不必担心上一个getline留下的回车
d)  当输入的字符串比分配的空间要更长的时候，cin.getline()会将余下的字符留在输入队列中，并且设置失效位，关闭输入，可以通过clear再次打开输入

a = cin.get() || cin.get(a)
a)  读取一个字符，包括blank,tab,\n,连续多个cin.get()使用的时候，当输入足够多字符后回车结束，enter也认为是有效字符被接收

cin.get(arrname, N):

a)  类似getline，但是换行符将留在输入缓冲区！ 
b)  cin.get():读取下一个字符，哪怕是换行符 
c)  留换行符的办法使得我们可以通过检查队列里第一个字符来确定cin是得到N-1个字符停止还是得到一行而停止,但是同时你也必须在循环输入的时候处理这些被留在缓
    冲区的换行符.
d)  当输入字符串比分配的空间长，get会截取N-1个字符，将余下的字符留在输入队列中，但是get不会设置失效位关闭输入

bad input 将会封锁输入



