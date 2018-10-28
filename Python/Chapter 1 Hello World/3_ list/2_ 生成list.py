# List 生成的几种方法

# 1. 用循环append的方法产生List
L = []
for x in range(1,11):
	L.append(x * x)
print(L)

input('waiting')

# 2. [生成元素 for x in list]
L = [x * x for x in range(1,11)] #要生成的元素x*x写在前面，后面是for循环
print(L)

# 后边加上if判断进行筛选也可以
L = [x * x for x in range(1,11) if x % 2 == 0]
print(L)

# 多层循环
L = [m + n for m in 'ABC' for n in 'XYZ']
print(L)

# 多变量循环 dict -> list
d = {'one':1, 'two':2, 'three':3}
L = [k + '=' + str(v) for k,v in d.items()]
print(L)

# Sample codes
# -*- coding: utf-8 -*-
L1 = ['Hello', 'World', 18, 'Apple', None]
L2 = [s.lower() for s in L1 if isinstance(s, str)]
if L2 == ['hello', 'world', 'apple']:
  print('测试通过!')
else:
  print('测试失败!')	
