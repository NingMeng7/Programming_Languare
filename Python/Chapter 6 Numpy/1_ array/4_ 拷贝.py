# numpy 的拷贝分为 1.安全不拷贝 2.浅拷贝 3.深拷贝

import numpy as np
# 1.1 简单赋值二者指向同一个对象 完全不拷贝
a = np.arange(12)
b = a
if a is b:
    print('Yes, 简单赋值, a和b指向同一个对象!')

# 2.1 视图view()  浅拷贝,a与a.view()共享数据
# a 与 c 拥有相同的数据，但是地址不同，对c的shape改变不会影响到a，但是改变c的数据会影响到a
c = a.view()
print(a == c)
if not(a is c):
    print('No, a is not c!')
print(c.base is a)

# 2.2 对视图的shape改变并没有影响到a
c.resize(3,4)
print(c)
print(a)

input('waiting')

# 2.3 对视图数据改变对a也产生了影响
c.resize(1,12)
c[(0,0)] = 33
print(c)
print(a)


# 3.1 深拷贝: 完全复制 b doesn't share anything with a
a = np.arange(12)
b = a.copy()

if not (a is b):
    print('No! a is not b!')
print(b.base is a)

# 3.2 对b改变数据并不会影响到a
b[0] = 33
print(b)
print(a)

