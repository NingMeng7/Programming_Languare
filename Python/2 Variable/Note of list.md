## Python 中的变量

- 整型: Python可以处理任意大小的整数, 而且支持二进制, 如0b100，换算成十进制是4）、八进制（如0o100，换算成十进制是64）、十进制（100）和十六进制（0x100，换算成十进制是256）的表示法。
- 浮点型：浮点数也就是小数，之所以称为浮点数，是因为按照科学记数法表示时，一个浮点数的小数点位置是可变的，浮点数除了数学写法（如123.456）之外还支持科学计数法(如1.23456e2).
- 字符串型: 字符串是以单引号或双引号括起来的任意文本.
- 布尔型: True, False. 布尔型可以通过布尔运算得到: 3 < 5 会产生True, 2 == 1 会产生 False
- 列表 list、 元祖 tuple
- 字典 dict 、 集合 set

#### 1 变量命名规则
- 变量用小写字母拼写, 多个单词用下划线连接
- 受保护的实例属性用单个下划线开头（后面会讲到）。
- 私有的实例属性用两个下划线开头（后面会讲到）。

#### 2 字符串

Python为字符串类型提供了非常丰富的运算符，我们可以使用+运算符来实现字符串的拼接，可以使用*运算符来重复一个字符串的内容，
可以使用in和not in来判断一个字符串是否包含另外一个字符串（成员运算），我们也可以用[]和[:]运算符从字符串取出某个字符或某些字符（切片运算），代码如下所示。

#### 2 list 
list 是python的一种基本类型，它和数组很类似，但是和C语言的数组还是有很大区别的

    L = [[1,2,3], 4, 5, 6]
    print(id(L[0]))
    print(id(L[1]))
    #list内的内存竟然可能不是连续的！！！
    
## list 的三种查找操作
1. in操作符: 判断值是否在list中
 
        L = ['a', 'b', 'c', 'd', 1, 2, 3, 4]
        print('a' in L)
        print(1 in L)

2. count方法: 判断指定值在list中出现的次数  

L.count('a')  : 统计'a'在L中出现的次数

注意list没有 L.count('a', begin, end)的方法，这个只有str有 

        L = ['a', 'b', 'b', 'd', 1, 2, 3, 4]
        print(L.count('b'))
        print(L.count('b'))

3. index方法: 查看指定值在list中的位置:

L.index('a')  : 返回'a'在L中第一次出现的位置

L.index('a', begin, end)  : 返回a在指定切片中第一次出现的位置 [begin, end)
    
## list的脚本操作符
1. len([1,2,3,4])                   4

2. [1,2,3] + ['a','b','c']          [1,2,3,'a','b','c']

3. ['a']\*3                          ['a','a','a']

4. 3 in [1,2,3,4]                   True

5. for i in [1,2,3,4]:                迭代器不断给出next，直到抛出错误

## list 函数 & 方法
1. L.append(obj)                      在列表末尾添加新的对象

2. L.count(obj)                        统计某个元素在列表中出现的次数

3. L.extend(seq)                       用新列表扩展原列表    和直接+相比可以保持地址不变

4. L.index(obj)                        切片可选,找出某个值的第一个匹配项索引位置

5. L.insert(index, obj)                 插入对象

6. a = L.pop()                          删除并返回L的最后一个元素

7. L.remove(obj)                        删除某个值的第一个匹配项

8. L.reverse()                          反向列表中的元素

9.L.sort(func)                                               
        
