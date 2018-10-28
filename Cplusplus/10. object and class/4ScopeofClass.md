# The scope of class
## introduction
 a) 全局变量可以在所属文件的任何地方使用，而局部变量只能在其所属的代码块中使用。
  
 b) 函数名称的作用域也可以是全局的，但是不能是局部的。
  
 c) C++引入了一种新的作用域: 类作用域
 
## 类作用域

 类中定义的名称(例如数据成员和类成员函数名）的作用域都为整个类，其只在该类中是已知的，因此可以在不同的类中定义相同的名称，而不会冲突。 这也意味着，不
能从外部直接访问类的成员，即使是公有函数，要调用类的成员，只能通过对象，我们必须通过context来使用"." 或者 “->" 或者 ”::"来实现访问。

    class IK
    {
      private:
        int fuss;
      public:
        Ik(inf f = 9) {fuss = f;}
        void ViewIk() const;
    };
    
    void Ik::ViewIk() const
    {
      cout << fuss << endl;
    }
    
    int main()
    {
      Ik * pik = new Ik;
      Ik ee = Ik(8);
      ee.ViewIk();
      pik->ViewIk();
    }
    
## 类中的常量

让符号常量的作用域为类很多时候是很有用的，例如，给类中数组长度一个常量30,但是下面这种方法是行不通的。

    class Bakery {
    private:
      const int Months = 12;
      double costs[Month];
      ...
    };
一定要记得，声明类只是描述了对象的形式，而并没有创建一个对象，在创建对象前，我们并没有存储值的空间,我们有两种方法来实现这个目标.

### method 1: 声明枚举量来创建符号常量
    class {
    private:
      enum {Months = 12};
      double costs[Months];
    };

### method 2: 关键词static
    class {
    private:
      static const int Monhts = 12;
      double costs[Monhts];
    };

## 作用域内枚举
传统的枚举类型可能会带来冲突的问题，例如，在一个项目中我们需要定义如下的两种枚举量:

    enum egg {Small, Medium, Large, Jumbo};
    enum t_shirt {Small, Medium, Large, Xlarge};
    //  无法通过编译,两个Small位于相同的作用域中，将会冲突.
    
    enum class egg {Small, Medium, Large, Jumbo};
    enum class t_shirt {Small, Medium, Large, Xlarge};
    //  可以用关键字 struct 代替 class
    
    //  需要使用枚举名来限定枚举量
    egg choice = egg::Large;
    t_shirt Floyd = t_shirt::Large;

### 同时,这种作用域内的枚举量还被限制不能隐式地转化为整型量:

    enum egg_old {Small, Medium, Large, Jumbo}; //  not scoped
    enum class t_shirt {Small, Medium, Large, Xlarge};  //  scoped
    egg_old one = Medium; //  unscopded
    t_shirt rolf = t_shirt::Large;  //  scoped
    int king = one; //  allowed
    int king = rolf;  //  invalid
    if (king < Jumbo) //  allowed
      std::cout << "Jumbo converted to int before comparison.\n";
    if (king < t_shirt::Medium) //  not allowed
      std::cout << "Not allowed: <not defined for scoped enum.\n";
	  
	  // 当然，允许**显式**地 int Frodo = int(t_shirt::Small);
	  
### scoped 枚举由某种底层整型类实现，可以作出选择
    enum class : short pizza {Small, Medium, Large, Xlarge};
     


