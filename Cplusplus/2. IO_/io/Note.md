```c++
#include <iostream> // a PREPROCESSOR directive
int main() // function header
{ // start of function body
using namespace std; // make definitions visible
cout << "Come up and C++ me some time."; // message
cout << endl; // start a new line
cout << "You won’t regret it!" << endl; // more output
return 0; // terminate main()
} // end of function body
```

#### 1 main function

C++ standard requires:

```c++
int main() // int
{
    /*
    statement;
    /*
    return 0; // explicitly return 0.
}
```

Although if the compiler reaches the end of main() without encountering a return statement, the effect will be the same as if you ended main() with this statement: 

return 0;

However, this implicit return is provided only for main() and not for any other function.

- When you run a C++ program, execution always begins at the beginning of the main() function. There are exceptions...
- You should use comments to document your programs. 

#### 2 Preprocessor and the iostream File

Line 1: Including header file iostream will causes the preprocessor to **add** the contents of the iostream file to your program.

(Preprocessor will add or replace text in the source code before compiling.)

 **Now h extension** is reserved for the old C header files and C++ header files have no extension.



#### 3 Namespace

```cpp
Microflop::wanda("go dancing?"); // use Microflop namespace version
Piscine::wanda("a fish named Desire"); // use Piscine namespace version
// Case 1
using namespace std;
// Case 2
using std::cout; // make cout available
using std::endl; // make endl available
using std::cin; // make cin available
// Case 3
std::cout << "I’m using cout and endl from the std namespace" << std::endl;
```

Namespace support is a C++ feature designed to simplify the writing of **large** programs and of programs that combine pre-existing code. **You might use two prepackaged products that have the same name of variable or function.**

You use **the** name in different namespace to indicate which version you want.(like line 3 and 4)

The current prevalent philosophy is that it’s **preferable to be more discriminating and**
**limit access to the std namespace to only those functions that need access**.

#### 4 Input and Output

Cout is a predefined object that knows how to display a variety of things, including strings, numbers and individual characters.

cin converts input, which is just **a series of characters typed from the keyboard**, into a **form acceptable to the variable** receiving the information

```c++
cout << "Now you have "
     << carrots
     << " carrots."
     << endl
```

cout 处理完第一个字符串之后, 会返回一个cout对象, 因此可以这样连接着使用。

**A touch of class**: cin & cout

A class is a **data type** the **user** defines.To define a class, you describe what **sort of information** it can represent and **what sort of actions** you can perform with that data.

cin & cout are objects created with the properties of isteam class and ostream class, respectively.

(Type(class), instance)

a)  cin.get(ch) :将字符赋给参数ch(事实上这里涉及到了引用)  ch = cin.get() : 将函数返回值赋值给ch
b)  cin.get(ch)的返回值是istream对象, bool转换后，当输入成功为true  ch = cin.get() :int类型的字符编码
c)  到达EOF的返回值:cin.get(ch) : istream对象，bool转换后为false ch = cin.get()  EOF(通常为 - 1)
d)  不能以 abcdef(EOF)的形式输入text，而只能先在f后进行回车，再输入EOF

#### 5 Code style

- One statement per line
- An opening brace and a closing brace for a function, each of which is on its own line
- Statements in a function indented from the braces
- No whitespace around the parentheses associated with a function name

```c++
doule MyFunction( );
```



#### 6 Declarations and Assignments of variables

C++ require the programmer to declare a variable before using it. The declaration identifies both the **storage location** and **how much memory storage space**.

```c++
int carrots; // int identifies the type of memory storage needed
					// and a label to attach to that storage
static int carrots;	// static explicitly identifies the storage location
```

C++ do not require that variables should be defined at the beginning of a function or procedure.

```c++
int steinway;
int baldwin;
int yamaha;
yamaha = baldwin = steinway = 88;

carrots = carrots - 1; // modify the variable
```

The declaration statement in the program is called a **defining declaration** statement, or
definition, for short.This means that its presence causes the compiler to allocate memory
space for the variable. In more complex situations, you can also have **reference declarations**.
These tell the computer to use a variable that has already been defined elsewhere.

**The C++ style for declaring variables is to declare a variable as close to its first use as
possible.**

#### 7 Functions

Main discussion of functions comes later, in Chapter 7

C++ functions come in two varieties: those with return values and those without
them.

```c++
x = sqrt(6.25) // sqrt is a function returning 2.5 here
    // function call, 6.25 is parameter
    
double sqrt(double); // function prototype
// Terminating semicolon ideitifies it as a prototype instead of a function header

double pow(double, double); // prototype of a function with two arguments
void bucks(double); // prototype for function with no return value

bucks(1234.56); // function call, no return value

```

**A function prototype does for functions what a variable declaration does for variables:**

function prototype: 函数原型

**Don’t confuse the function prototype with the function definition**

You should place a function prototype ahead of where you first use the function.The
usual practice is to place prototypes just before the definition of the **main()** function

```c++
#include <iostream>
void simon(int);

int main()
{
    using std::cout;
    using std::cin;
    simon(3);
    cout << "Pick an integer: ";
	int count;
	cin >> count;
	simon(count); // call it again
	cout << "Done!" << endl;
	return 0;
}

void simon(int n) // define the simon() function
{
	using namespace std;
	cout << "Simon says touch your toes " << n << " times." << endl;
} // void functions don’t need return statements
```

```c++
// convert.cpp -- converts stone to pounds
#include <iostream>
int stonetolb(int); // function prototype
int main()
{
	using namespace std;
	int stone;
	cout << "Enter the weight in stone: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " stone = ";
	cout << pounds << " pounds." << endl;
	return 0;
}

int stonetolb(int sts)
{
	return 14 * sts;
}
```

