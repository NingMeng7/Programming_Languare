## (1) 类的构造函数与析构函数
  
  仅仅有了成员函数的实现对于一个类来说还不够，因为我们并不能像初始化标准类型一样进行初始化,这是因为出于数据隐藏的目的，类的数据只能被成员函数来访问.
例如:
    
    int year = 2000;
    struct thing {
      char * pn;
      int m;
    };
  
  而创建示例的时候进行初始化是有必要的，这样能防止在没有初始化之前对数据进行使用，为了解决这个问题,C++提供了一个特殊的成员函数——类构造函数用于构造
新对象并将值赋给它们的数据成员，构造函数没有返回值也不被声明为 void 类型，构造函数没有声明类型。

## (2) 构造函数的实现
a)  原型提供
  
  	public:
  		...
  		Stock(const string & co = "No name", long n = 0, double pr = 0);
  		...
b) 细节实现
  
  	Stock::Stock(const string & co, long n, double pr)  //  注意默认参数只在原型给出.
	  {
    		...;
  	  }
c)  构造函数的使用

  (i)   Stock fluffy_the_cat = Stock("NanoSmart", 20, 12.50);	//	这里可能涉及到临时对象的产生与删除，也可能和第二种实现完全相同，取决于编译器
  
  (ii)  Stock fluffy_the_cat("NanoSmart", 20, 12.50);
  
  (iii) Stock *pstock = new Stock("NanoSmart", 20, 12.50);
  
  (iv)  括号列表初始化
  
    Stock hot_tip {"Derivatives Plus Plus", 100, 45.0}; //  constructor
    Stock jack {"Sport Age Storage, Inc"};  //  constructor
    Stock temp {};  //  default constructor

## (3) 默认构造函数
  
  默认构造函数是在未显示给出初始值的时候用来创建对象的构造函数,例如:
    
    Stock fluffy_the_cat; 
  
  在给出自定义的构造函数之后,上面这个声明gg了,这是因为C++编译器只会在你没有自定义构造函数的时候会帮你提供一个系统版的默认构造函数，当你给出了一个自
定义的默认函数之后，原先的系统版的不接受任何参数的默认构造函数不再被提供，需要你自己来给出一个默认构造函数，有两种方法，请注意，不要同时使用两种方法
来实现:

  (i) 给构造函数的所有参数都提供一个默认参数
      事实上在上面的例子里已经这么做了.
  
  (ii)  通过函数重载来实现.
      
      public:    
         Stock();    
      Stock::Stock()
      {
        company = "No name";
        shares = 0;
        share_val = 0.0;
        total_val = 0.0;
      }
  
  需要注意的一点是，由于默认构造函数的调用是隐式的，会有一些地方容易搞错，看下面的例子:
  Stock("Concrete Conglometrate");  //  calls constructor
  Stock second(); //  declares a function
  Stock third();  //  calls default constructor

## (4) 析构函数
  
  用构造函数创建对象之后，程序将会跟踪对象，当对象过期之后，程序将会自动调用一个特殊的成员函数  ——  析构函数来完成清理工作。 如果在构造函数里使用了
new,则必须在析构函数里提供delete来释放这部分内存.

  析构函数没有参数，没有返回值，没有声明类型，其名称很特殊： 在类名前面加上~.
  
  a)  原型声明
  ~Stock();
  
  b)  细节实现
  
  	Stock::~Stock()
  	{
    		std::cout << "Bye, " << company << "!\n";
  	}
  
  c)  析构函数的使用
  
    析构函数一般不显示调用，一般而言，如果是静态变量，析构函数将会在程序结束的时候被调用，而如果是一个自动变量，将会在代码块结束的时候被调用，当没
  有自定义析构函数的时候，编译器将会提供一个默认的析构函数。
    
## (5) 初始化 与 赋值

		Stock stock2 = Stock("Boffo Objects", 2, 2.0);  //  初始化,创建有指定值的对象，可能会创建临时对象。
    		Stock stock1;
		Stock stock1("NanoSmart", 12, 20.0);  //  赋值,这种赋值语句在使用构造函数前总会创建一个临时对象。
  
  一般而言,初始化的效率更高，能用初始化尽量用初始化。
  
## (6) C++11 列表初始化
  
  列表初始化的语法同样适用于类,只要提供与某个构造函数的参数列表相匹配的内容即可.
  
  	Stock hot_tip {"Derivatives Plus Plus", 100, 45.0}; //  constructor
  	Stock jack {"Sport Age Storage, Inc"};  //  constructor
  	Stock temp {};  //  default constructor
  
## (7) const成员函数
  
  	const Stock land = Stock("Kludgehorn Properties");
  	land.show();  //  invalid
  
  对于这种形参无法接受const类型的情况，我们过去采用的是采用const形参来解决，但是问题是，show()本身是不接受参数的，相反，它对调用它的这个对象进行操
作，为了解决这个问题，C++对于不会改变类对象的成员函数引入了const 成员函数.

	void show() const;
	void Stock::show() const
	{
	  ...;
	}

## (8) 接受一个参数的 construtor

	Bozo nedribble = Bozo(44);  //  显示调用构造函数
	Bozo nedribble(44); //  隐式调用
	Bozo nedribble = 44;  //  单参数 construtor 的特殊用法

