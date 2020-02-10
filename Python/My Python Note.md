# Python learning

Wei Xiong | Computer Science and Math

Undergraduate student of University of Science and Technology of China

## 1 PE8 & Standard form

1 缩进： **Remark** 始终使用Tab，尽管这与PE8要求不同

```python
# 续行
# Aligned with opening delimiter.
foo = long_function_name(var_one, var_two,
                         var_three, var_four)

# More indentation included to distinguish this from the rest.
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)

# Hanging indents should add a level.
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)

# 长条件判断换行
if (this_is_one_thing and
    that_is_another_thing):
    do_something()

# 在多行结构中的右圆括号、右中括号、右大括号应该放在最后一行的第一个非空白字符的正下方，如下所示：
my_list = [
    1, 2, 3,
    4, 5, 6,
    ]
result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
    )
```

2 空行

```python
'''
1 顶级函数和类定义上下使用两个空行分隔。
2 类内的方法定义使用一个空行分隔。
3 可以使用额外的空行（有节制的）来分隔相关联的函数组。在一系列相关联的单行代码中空行可以省略（e.g. 一组虚拟的实现）。
4 import不同的模块应该独立一行, import 应在文件顶部, 在注释之下, 全局变量常量之前
5 import i 标准库 ii 相关第三方库 iii  自己写的库， 避免 import *
'''
```

3 表达式

```python
'''
1 字符串单引号和双引号: 坚持使用单引号
2 逗号左连续, 右加一空格
3 切片冒号左右对称
4 在二元操作符两侧加入一个空格
5 参数的默认值左右不加空格
'''
ham[1:9], ham[1:9:3], ham[:9:3], ham[1::3], ham[1:9:]
ham[lower:upper], ham[lower:upper:], ham[lower::step]
ham[lower+offset : upper+offset]
ham[: upper_fn(x) : step_fn(x)], ham[:: step_fn(x)]
ham[lower + offset : upper + offset]

def complex(real, imag=0.0):
    return magic(r=real, i=imag)
```

4 注释

1 块注释通常用来说明跟随在其后的代码，与代码有相同的缩进层次。块注释每一行以`#`起头，并且`#`后要跟一个空格

2 行内注释应该至少与语句相隔两个空格。以`#`打头，`#`后接一个空格，**有节制的使用**

3 文档字符串

```python
'''Return a foobang

Optional plotz says to frobnicate the bizbaz first.
'''
```

5 命名

```python
''' 命名约定
don't:
i 单个字母作为变量, 特别是类似l这种难以区分的, 除非是习惯性的迭代性变量
ii 模块名 短 且 小写, 必要时可以增加下划线改善可读性

1 lower_case_with_underscores
2 函数名应该是小写的，有必要的话用下划线来分隔单词提高可读性。
3 异常名: 以Error作为后缀
4 global variable: 我们希望这些变量只在一个模块内被使用, 用__all__ 机制表明那些可导出的全局变量
5 用一个且有一个前导的下划线来表明非公有的方法和实例变量。
6 常量应该全部大写, 单词间使用下划线分割: MAX_OVERFLOW
'''
```

6 编程建议

```python
'''
1 string: ''.joint 而不是 a += b (性能稳定)
2 None 比较: is/is not 而不是 ==
3 一个空的except:语句将会捕获到SystemExit和KeyboardInterrupt异常，很难区分程序的中断到底是Ctrl+C还是其他问题引起的。
因此, 应当限制使用空except除非异常处理程序提供的信息能让用户意识到错误所在, 代码做一些处理工作, 在后面用raise抛出错误
4 对象类型的比较应该始终使用isinstance()而不是直接比较。

'''
try:
    process_data()
except Exception as exc:
    raise DataProcessingFailedError(str(exc))
   

Yes: if isinstance(obj, int):
No:  if type(obj) is type(1):
```

## 2 e.g.

1 文件操作

```python
def get_lines():
	with open('file.txt', 'rb') as f:
        return f.readlines()

def get_lines2():	# 内存不足以一次读入，分次读入
	with open('file.txt', 'rb') as f:
        for i in f:
            yield i

for e in get_lines():
    process(e)
```

2 判断输入日期是第几天

```python
import datetime
def dayofyear():
    year = input("请输入年份: ")
    month = input("请输入月份: ")
    day = input("请输入天: ")
    date1 = datetime.date(year=int(year),month=int(month),day=int(day))
    date2 = datetime.date(year=int(year),month=1,day=1)
    return (date1-date2).days+1
```

3 打乱一个排好序的list

```python
import random
alist = [1,2,3,4,5]
random.shuffle(alist)
```

4 字典按value/key/both

```python
sorted(d.items(),key=lambda x:x[1])	# value
sorted(d.items(),key=lambda x:ord(x[0]))	# key
```

5 字典

```python
d = {key:value for (key, value) in iterator} # Remark: the keys must be different
```

6 反转字符串

```python
print(astr[::-1])
```

7 切割分段处理字符串生成字典

```python
str1 = "k:1|k1:2|k2:3|k3:4"
def str2dict(str1):
    dict1 = {}
    for iterms in str1.split('|'):
        key,value = iterms.split(':')
        dict1[key] = value
    return dict1
#字典推导式
d = {k:int(v) for t in str1.split("|") for k, v in (t.split(":"), )}
```

8 按age元素大小从大到小排序

```python
alist = [{'name':'a','age':20},{'name':'b','age':30},{'name':'c','age':25}]
def sort_by_age(list1):
    return sorted(alist,key=lambda x:x['age'],reverse=True)
```

9 求两个列表相同和不同的元素，删除重复元素

```python
l1 = [1, 2, 3]
l2 = [3, 4, 5]
set1 = set(l1)
set2 = set(l2)
print(set1 & set2)
print(set1 ^ set2)

l3 = list(set(l1))
l1 = ['b','c','d','c','a','a']
l2 = []
for i in l1:
    if not i in l2:
        l2.append(i)
print(l2)
```

10 python 数据类型

a. 整型 int、 长整型 long、浮点型 float、 复数 complex

b. 字符串 str、 列表 list、 元祖 tuple

c. 字典 dict 、 集合 set

d. Python3 中没有 long，只有无限精度的 int

11 反转一个整数

```python
class Solution(object):
    def reverse(self,x):
        if -10<x<10:
            return x
        str_x = str(x)
        if str_x[0] !="-":
            str_x = str_x[::-1]
            x = int(str_x)
        else:
            str_x = str_x[1:][::-1]
            x = int(str_x)
            x = -x
        return x if -2147483648<x<2147483647 else 0
if __name__ == '__main__':
    s = Solution()
    reverse_int = s.reverse(-120)
    print(reverse_int)
```

12 遍历目录和子目录抓取文件

第一种方法：

```python
import os

def get_files(dir,suffix):
    res = []
    for root,dirs,files in os.walk(dir):
        for filename in files:
            name,suf = os.path.splitext(filename)
            if suf == suffix:
                res.append(os.path.join(root,filename))

    print(res)

get_files("./",'.pyc')
```

第二种方法：

```python
import os

def pick(obj):
    if ob.endswith(".pyc"):
        print(obj)
    
def scan_path(ph):
    file_list = os.listdir(ph)
    for obj in file_list:
        if os.path.isfile(obj):
    pick(obj)
        elif os.path.isdir(obj):
            scan_path(obj)
    
if __name__=='__main__':
    path = input('输入目录')
    scan_path(path)
```

第三种方法

```python
from glob import iglob


def func(fp, postfix):
    for i in iglob(f"{fp}/**/*{postfix}", recursive=True):
        print(i)

if __name__ == "__main__":
    postfix = ".pyc"
    func("K:\Python_script", postfix)
```

13 list 遍历删除元素

```python
#filter
a=[1,2,3,4,5,6,7,8]
b = filter(lambda x: x>5,a)
print(list(b))

a=[1,2,3,4,5,6,7,8]
b = [i for i in a if i>5]
print(b)
```

14 给出输入句子中没出现的26字母

```python
def get_missing_letter(a):
    s1 = set("abcdefghijklmnopqrstuvwxyz")
    s2 = set(a)
    ret = "".join(sorted(s1-s2))
    return ret
    
print(get_missing_letter("python"))
```

15 可变类型与不可变类型

1,可变类型有list,dict.不可变类型有string，number,tuple.

2,当进行修改操作时，可变类型传递的是内存中的地址，也就是说，直接修改内存中的值，并没有开辟新的内存。

3,不可变类型被改变时，并没有改变原内存地址中的值，而是开辟一块新的内存，将原地址中的值复制过去，对这块新开辟的内存中的值进行操作。

16 is 和 ==

is：比较的是两个对象的id值是否相等，也就是比较俩对象是否为同一个实例对象。是否指向同一个内存地址

== ： 比较的两个对象的内容/值是否相等，默认会调用对象的eq()方法

17 1+2+3+10248

```python
from functools import reduce
#1.使用sum内置求和函数
num = sum([1,2,3,10248])
print(num)
#2.reduce 函数
num1 = reduce(lambda x,y :x+y,[1,2,3,10248])
print(num1)
```

## Python 3 practice

- 使用 4 个空格来缩进
- 永远不要混用空格和制表符
- 在函数之间空一行
- 在类之间空两行
- 字典，列表，元组以及参数列表中，在 `,` 后添加一个空格。对于字典，`:` 后面也添加一个空格
- 在赋值运算符和比较运算符周围要有空格（参数列表中除外），但是括号里则不加空格：`a = f(1, 2) + g(3, 4)`
- 你应该总是在 `#` 后跟一个空格，然后再写注 



**1 Input**

```python
#!/usr/bin/env python3
amount = float(input("Enter amount: "))  # 输入数额
inrate = float(input("Enter Interest rate: "))  # 输入利率
period = int(input("Enter period: "))  # 输入期限
value = 0
year = 1
while year <= period:
    value = amount + (inrate * amount)
    print("Year {} Rs. {:.2f}".format(year, value))
    amount = value
    year = year + 1
```

2 **赋值**

```python
a, b = 45, 54
a, b = b, a	# Exchange the value of two variables

data = ("shiyanlou", "China", "Python")
name, country, language = data

a, b = 0, 1
while b < 100:	# python 先对赋值符右边的符号求值，再把它赋给左边的对象
    print(b)
    a, b = b, a + b
```

3 **Operator**

- 只要有一个操作数是浮点数，结果就是浮点数

```python
14 % 3 # 2
14 // 3 # 4

# python 的逻辑运算符从左到右解析, 一旦结果确定就会停止

# python 提供类型转换, 需要注意input输入的是字符串
float(string)
int(string)
str(integer)
str(float)
```

4 **If**

```python
if x > 100:
	pass
elif x > 90:
    pass
elif x > 50:
 	pass
else:
    pass

if x:	# instead of if x == True:
    pass
```

5 **Loop**

```python
a, b = 0, 1

while b < 100:
    print(b, end='')	# 把每次输出的换行符改成空格
    a, b = b, a + b

    
i = 1
print("-" * 50)	# 字符串 * n 返回 n个这个字符串拼接起来的字符串
while i < 11:
    n = 1
    while n <= 10:
        print("{:5d}".format(i * n), end=' ')
        n += 1
    print()
    i += 1
print("-" * 50)
```

```python
# slide 遵循左闭右开规则
# left:right 左边省略默认是0, 右边省略默认走到尾
# begin:end:step

a + [36, 49, 64, 81, 100]	# 拼接两个list
letter = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
letter[2:5] = ['C', 'D', 'E']	# 对list进行修改
‘Linux’ in letter	# 检查某个量是否在list
```

```python
# for 
range(begin, end, step)	# 生成一个等差数列

```

## Python: Function

1 **definition**

```python
def palindrome(s):
    return s == s[::-1]
```

2 global and local variable 

```python
a = 9
def change():
    print(a)	# error! a is regarded as a local variable which is not defined
    a = 100
change()

def change():
    global a
    a = 90
    print(a)
a = 9
print("Before the function call ", a)	# 9
print("inside change function", end=' ')	# 90
change()
print("After the function call ", a)	# 90
```

3 **parameter**

```python
# 必选参数: 		 最普通的参数 x
# 默认参数: 		 n=2 
# 可变参数: 	 	 *numbers  !!tuple
# 关键字参数:     **kw      !!dict   关键字参数一定要带参数名传入 
# 命名关键字参数:  *, city, age
# 参数组合顺序必须是：  必选参数，默认参数，可变参数，命名关键字参数，关键字参数


# n = 2 为默认参数，当不输入n的时候相当于认为n=2
# 需要注意的是，对于可变对象List/dict的默认参数，由于原地修改值，在后续调用过程中会累积（前面）传给它的参数的影响
def power(x, n=2):
	s = 1
	while n > 0:
		n = n - 1
		s = s * x
	return s
	
print(power(4,2))
print(power(4))

# 一个用可变对象当默认参数的例子
def f(a, data=[]):
	data.append(a)
	return data
print(f(1))	# [1]
print(f(2))	# [1, 2]
print(f(3))	# [1, 2, 3]

# 考虑将默认参数改为不可变对象，加入判断
def f(a, date=None):
    if date is None:
        date = []
    date.append(a)
    return date

# 多个默认参数,可以通过指定名称的形式来给值(而不必像C++那样受到参数给出顺序的限制)
def enroll(name, gender, age=6, city='Beijing'):
	print('name: ', name)
	print('gender: ', gender)
	print('age: ', age)
	print('city: ', city)
	print('\n')

enroll('KangKang','M')
enroll('Michael','M',7,'London')
enroll('LiLei','M',city='SiChuan')
input('waiting...')

# 可变参数,自动组装成一个tuple传入，如果不用可变参数要先定义一个list或者tuple
# 在list或者tuple前面加个*就能当成可变参数传入
def add(*numbers):
	sum = 0
	for n in numbers:
		sum = sum + n
	return sum	

print('add(1,2,3,4,5) = ',add(1,2,3,4,5))
a = [1,2,3,4,5]
print('add(1,2,3,4,5) = ',add(*a)) 
input('waiting...')

# 关键字参数: 可以输入任意个数的关键字参数，自动组装成一个dict,可以先组装一个dict，然后加**传入
def person(name, age, **kw):
	print('name:', name, ' age:', age, ' other:', kw)

person('Michael', 30)
person('KangKang', 30, gender='M', city='Beijing')
extra = {'city':'Beijing','job':'Engineer'}
person('Jack', 24, city=extra['city'], job=extra['job'])  # kw获得的是extra的拷贝，无法对原extra进行修改
person('Jcak', 24, **extra)
input('waiting...')

# 命名关键字参数：关键字参数可以有任意个，但是命名关键字参数只接收city job作为关键字参数(避免乱传数据进来)
# 命名关键字参数一定要带有参数名
# 命名关键字可以有缺省值
def hello(*, name='User'):
    print('Hello', name)
hello('Yaya')	# error! must be name = 'Yaya

def person3(name, age, *, city, job):  # *，后的字符被认为命名关键字参数
	print(name, age, city, job)

person3('Jane', 23, city='Beijing', job='Engineer')	
input('waiting...')

# 如果函数定义中已经有了一个可变参数，后面的命名关键字参数就不需要特殊分隔符*，了
def person4(name, age, *args, city, job):
	print(name, age, args, city, job)

def person5(name, age, *, city='Beijing', job): #命名关键字可以有缺省值
	print(name, age, city, job)
person5('Jack', 24, job='Engineer')  #可以不传入city	


# 整体的一个例子
def func1(a, b, c=0, *args, **kw):
	print('a=', a, 'b=', b, 'c=', c, 'args', args, 'kw=', kw)

func1(1, 2)
func1(1, 2, 3)  # 3是默认参数
func1(1, 2, 3, 'a', 'b')
func1(1, 2, 3, 'a', 'b', job='Engineer', x=77)
tup = ('a', 'b')
kw = {'job':'Engineer', 'x':77}
func1(1, 2, 3, *tup, **kw)
```

4 **Higher-order function**

```python
# Higher-order function: 可以以函数作为参数传入, 任何函数都可以作为高阶函数

# map(function, iterator)
# 对iterator的每一个值应用function, 返回生成序列的迭代器
lst = list(range(6))
def square(num):
    return num * num
print(list(map(square, lst)))

def normalize(name):
	return name[0].upper() + name[1:].lower()
L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)
```

5 **Function involved file**

```python
# open(file_name/path, mode='r)
# 'r': 只读, 'w':写入, 'a':追加
fobj = open("sample.txt")
fobj.close()	# 关闭文件

fobj.read()	# 一次读取整个文件
fobj.read()	# 再次调用将会返回空字符串
fobj.read(size)	# 指定读取字符串长度, 不指定或者负数都会读取整个文件

for x in fobj:
	fobj.readlines()	# 循环每次读取一行

fobj = open("ircnicks.txt", 'w')
fobj.write('powerpork\n')
fobj.write('indrag\n')
fobj.write('mishti\n')
fobj.write('sankarshan')
fobj.close()

# 使用 with 自动关闭, 即使发生异常也没关系, with 是 try-finally 块的简写
with open('sample.txt') as fobj:
    pass
```

e.g.

```python
# sys.argv传入三个参数，第一个是命令行，第二个是源文件名，第三个是目标文件名
# copy argv[1] to argv[2]
import sys
if len(sys.argv) < 3:
    print("Wrong parameter")
    print("./copyfile.py file1 file2")
    sys.exit(1)
f1 = open(sys.argv[1])
s = f1.read()
f1.close()
f2 = open(sys.argv[2], 'w')
f2.write(s)
f2.close()

import sys
print("First value", sys.argv[0])
print("All values")
for i, x  in enumerate(sys.argv):
    print(i, x)
```

E.G. 字符计数

```python
import os
import sys


def parse_file(path):
    """
    分析给定文本文件，返回其空格、制表符、行的相关信息

    :arg path: 要分析的文本文件的路径

    :return: 包含空格数、制表符数、行数的元组
    """
    fd = open(path)
    i = 0
    spaces = 0
    tabs = 0
    for i,line in enumerate(fd):
        spaces += line.count(' ')
        tabs += line.count('\t')
    # 现在关闭打开的文件
    fd.close()

    # 以元组形式返回结果
    return spaces, tabs, i + 1

def main(path):
    """
    函数用于打印文件分析结果

    :arg path: 要分析的文本文件的路径
    :return: 若文件存在则为 True，否则 False
    """
    if os.path.exists(path):
        spaces, tabs, lines = parse_file(path)
        print("Spaces {}. tabs {}. lines {}".format(spaces, tabs, lines))
        return True
    else:
        return False


if __name__ == '__main__':
    if len(sys.argv) > 1:
        main(sys.argv[1])
    else:
        sys.exit(-1)
    sys.exit(0)
```

6 **Error!**

- 首先，执行 `try` 子句 （在 [`try`](https://docs.python.org/3/reference/compound_stmts.html#try) 和 [`except`](https://docs.python.org/3/reference/compound_stmts.html#except) 关键字之间的部分）。

- 如果没有异常发生，`except` 子句 在 [`try`](https://docs.python.org/3/reference/compound_stmts.html#try) 语句执行完毕后就被忽略了。

- 如果在 `try` **子句**执行过程中发生了异常，那么该子句其余的部分就会被忽略。

  如果异常匹配于 [`except`](https://docs.python.org/3/reference/compound_stmts.html#except) 关键字后面指定的异常类型，就执行对应的 `except` 子句。然后继续执行 [`try`](https://docs.python.org/3/reference/compound_stmts.html#try) **语句**之后的代码。

- 如果发生了一个异常，在 [`except`](https://docs.python.org/3/reference/compound_stmts.html#except) 子句中没有与之匹配的分支，它就会传递到上一级 [`try`](https://docs.python.org/3/reference/compound_stmts.html#try) 语句中。

  如果最终仍找不到对应的处理语句，它就成为一个 *未处理异常*，终止程序运行，显示提示信息

- 如果还有可选字句 finally, 程序离开try后不论什么情况，都会执行finally字句，当try语句中发生未被except捕获的异常，在finally子句后会重新被抛出

```python
try:
    statements to be inside try clause
    do something
except ExpectionName:
    statements to evaluated in case of ExceptionName happens

def get_number():
	"Returns a float number"
	number = float(input("Enter a float number: "))
	return number

	while True:
	try:
		print(get_number())
	except ValueError:
		print("You entered a wrong value.")
'''
Enter a float number: 45.0
45.0
Enter a float number: 24,0
You entered a wrong value.
Enter a float number: Traceback (most recent call last):
  File "<stdin>", line 3, in <module>
  File "<stdin>", line 3, in get_number
KeyboardInterrupt
'''
# KeyboardInterrupt 无法被ValueError捕获, 因此程序会停止运行(最后一条)
# 空的except 能捕获任何异常
try:
    input()
except:
    print("Unknown Exception")
    
# 我们可以主动raise(抛出)异常
raise ValueError("A value error happened.")

# Finally 子句(可选)

```

e.g. 时间转换

```python
import sys

# 转换函数
def Hours(minute):
    # 如果为负数则 raise 异常
    if minute < 0:
        raise ValueError("Input number cannot be negative")
    else:
        print("{} H, {} M".format(int(minute / 60), minute % 60))

# 函数调用及异常处理逻辑
try:
    Hours(int(sys.argv[1]))
except:
    print("Parameter Error")
```

7 **Class**

Python: Everything is object

```python
# Define a class
class complex(parent_class):
    i = 12345
    def __init__(self, real, imag):
        self.r = real
        self.i = imag
    def method(self):
        return True

# Get an instance of the class
x = complex(1, 1)
```

**Inherent**

新定义的class 可以继承 一个或者多个父类，并获得父类的所有变量和方法

```python
class Person(object):
    """
    返回具有给定名称的 Person 对象
    """

    def __init__(self, name):
        self.name = name

    def get_details(self):
        """
        返回包含人名的字符串
        """
        return self.name


class Student(Person):
    """
    返回 Student 对象，采用 name, branch, year 3 个参数
    """

    def __init__(self, name, branch, year):
        Person.__init__(self, name)
        self.branch = branch
        self.year = year

    def get_details(self):
        """
        返回包含学生具体信息的字符串
        """
        return "{} studies {} and is in {} year.".format(self.name, self.branch, self.year)


class Teacher(Person):
    """
    返回 Teacher 对象，采用字符串列表作为参数
    """
    def __init__(self, name, papers):
        Person.__init__(self, name)
        self.papers = papers

    def get_details(self):
        return "{} teaches {}".format(self.name, ','.join(self.papers))


person1 = Person('Sachin')
student1 = Student('Kushal', 'CSE', 2005)
teacher1 = Teacher('Prashad', ['C', 'C++'])

print(person1.get_details())
print(student1.get_details())
print(teacher1.get_details())
```

**Delete**

```python
del s	# 删除一个对象
```

**Attributes**

```python
class Student(object):
	def __init__(self, name):
		self.name = name

std = Student("Kushal Das")
print(std.name)	#	Kushal Das
std.name = "Python"
print(std.name)	#	Python
```

**e.g. Decorator**

直接引用属性虽然方便，但是有时候我们希望对交互进行检查，例如，赋值的学生分数是否在正确的范围, 这种情况可以采用装饰器实现

```python
class Account(object):
    """账号类,
    amount 是美元金额.
    """
    def __init__(self, rate):
        self.__amt = 0
        self.rate = rate

    @property
    def amount(self):
        """账号余额（美元）"""
        return self.__amt

    @property
    def cny(self):
        """账号余额（人民币）"""
        return self.__amt * self.rate

    @amount.setter
    def amount(self, value):
        if value < 0:
            print("Sorry, no negative amount in the account.")
            return
        self.__amt = value

if __name__ == '__main__':
    acc = Account(rate=6.6) 
    acc.amount = 20
    print("Dollar amount:", acc.amount)
    print("In CNY:", acc.cny)
    acc.amount = -100
    print("Dollar amount:", acc.amount)
```

**8 Module**

```python
import module	# 导入模块
from module import func	# 导入指定函数
```

**os**: 与操作系统相关的功能

```python
os.getuid()		# 返回当前进程的有效用户id
os.getpid()		# 返回当前进程id
os.getppid()	# 返回父进程的id

os.getcwd()		# 获取path
os.chdir(path)	# 更改当前目录到
os.listdir(path)	# 或者path下所有文件和目录

def view_dir(path='.'):
    """
    这个函数打印给定目录中的所有文件和目录
    :args path: 指定目录，默认为当前目录
    """
    names = os.listdir(path)
    names.sort()
    for name in names:
        print(name, end =' ')
    print()
```

**request**

```python
req = requestget('https://github.com')	# 获取网页

#!/usr/bin/env python3
import requests

def download(url):
    '''
    从指定的 URL 中下载文件并存储到当前目录
    url: 要下载页面内容的网址
    '''
    # 检查 URL 是否存在
    try:
        req = requests.get(url)
    except requests.exceptions.MissingSchema:
        print('Invalid URL "{}"'.format(url))
        return
    # 检查是否成功访问了该网站
    if req.status_code == 403:
        print('You do not have the authority to access this page.')
        return
    filename = url.split('/')[-1]
    with open(filename, 'w') as fobj:
        fobj.write(req.content.decode('utf-8'))
    print("Download over.")

if __name__ == '__main__':
    url = input('Enter a URL: ')
    download(url)
```

**collection**

```python
from collections import Counter
import re
path = '/usr/lib/python3.5/LICENSE.txt'
words = re.findall('\w+', open(path).read().lower())
Counter(words).most_common(10)
# [('the', 80), ('or', 78), ('1', 66), ('of', 61), ('to', 50), ('and', 48), ('python', 46), ('in', 38), ('license', 37), ('any', 37)]

c = Counter(a=4, b=2, c=0, d=-2)
list(c.element())	# ['b','b','a', 'a', 'a', 'a']

# defaultdict

from collections import defaultdict
s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
d = defaultdict(list)
for k, v in s:
	d[k].append(v)	# 当dict不存在某个key, 它会自动创建一个空列表
d.items()
dict_items([('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])])
```

**9 Iterator**

```python
# __iter__()，返回迭代器对象自身。这用在 for 和 in 语句中。
# __next__()，返回迭代器的下一个值。如果没有下一个值可以返回，那么应该抛出 StopIteration 异常。

class My_counter(object):
    def __init__(self, low, high):
        self.current = low
        self.high = high

    def __iter__(self):
        return self

    def __next__(self):
        #返回下一个值直到当前值大于 high
        if self.current > self.high:
            raise StopIteration
        else:
            self.current += 1
            return self.current - 1
# Remark: iterator 只能使用一次, 一旦抛出异常, 就会一直抛出异常(这是为什么每个epoch要重新初始化的原因)
iterator = iter(c)
while True:
	try:
		x = iterator.__next__()
		print(x, end=' ')
	except StopIteration as e:
		break
```

10 **generator**

```python
def my_generator():
    print('Inside my generator')
    yield 'a'
    yield 'b'
    yield 'c'
for char in my_generator():
    print(char)
# a b c

>>> def counter_generator(low, high):
...     while low <= high:
...        yield low
...        low += 1
... 
>>> for i in counter_generator(5,10):
...     print(i, end=' ')
... 
5 6 7 8 9 10
'''
每次执行到 yield, 将会返回 low 的值, 并且将生成器状态挂起, 下一次调用的时候从上次冻结的地方恢复执行, 生成器也无法重复使用
'''
```

## 测试代码

**Unit testing**

是针对程序模块(软件设计最小单位)来进行正确性检测的测试工作. 程序单元是应用的最小可测试部件。

在过程化编程中，一个单元就是单个程序、函数、过程等；

对于面向对象编程，最小单元就是方法，包括基类（超类）、抽象类、或者派生类（子类）中的方法。 

**例子**

```python
import sys

def fact(n):
    """
    阶乘函数

    :arg n: 数字
    :returns: n 的阶乘

    """
    if n == 0:
        return 1
    return n * fact(n -1)

def div(n):
    """
    只是做除法
    """
    res = 10 / n
    return res


def main(n):
    res = fact(n)
    print(res)

if __name__ == '__main__':
    if len(sys.argv) > 1:
        main(int(sys.argv[1]))
```

```python
import unittest
from factorial import fact, div

class TestFactorial(unittest.TestCase):
    """
    我们的基本测试类
    """

    def test_fact(self):
        """
        实际测试
        任何以 `test_` 开头的方法都被视作测试用例
        """
        res = fact(5)
        self.assertEqual(res, 120)

    def test_error(self):
        """
        测试由运行时错误引发的异常
        """
        self.assertRaises(ZeroDivisionError, div, 0)

if __name__ == '__main__':
    unittest.main()
    
'''
assertEqual(a, b)	
assertNotEqual(a, b)	
assertTrue(x)	
assertFalse(x)
assertIs(a, b)
self.assertRaises(ZeroDivisionError, div, 0)

e.t.c.
'''
```



**例子2**

```python
import os

def parse_mounts():
    """
    分析 /proc/mounts 并 返回元祖的列表
    """
    result = []
    if os.path.exists('/proc/mounts'):
        fd = open('/proc/mounts')
        for line in fd:
            line = line.strip()
            words = line.split()
            if len(words) > 5:
                res = (words[0],words[1],words[2],'({})'.format(' '.join(words[3:-2])))
            else:
               res = (words[0],words[1],words[2])
            result.append(res)
        fd.close()
    return result

def mount_details():
    """
    打印挂载详细信息
    """
    result = parse_mounts()
    for line in result:
        if len(line) == 4:
            print('{} on {} type {} {}'.format(*line))
        else:
            print('{} on {} type {}'.format(*line))


if __name__ == '__main__':
    mount_details()
```

```python
#!/usr/bin/env python
import unittest
from mounttab2 import parse_mounts

class TestMount(unittest.TestCase):
    """
    我们的基本测试类
    """

    def test_parsemount(self):
        """
        实际测试
        任何以 `test_` 开头的方法都被视作测试用例
        """
        result = parse_mounts()
        self.assertIsInstance(result, list)
        self.assertIsInstance(result[0], tuple)

    def test_rootext4(self):
        """
        测试找出根文件系统
        """
        result = parse_mounts()
        for line in result:
            if line[1] == '/' and line[2] != 'rootfs':
                self.assertEqual(line[2], 'ext4')


if __name__ == '__main__':
    unittest.main()
```

