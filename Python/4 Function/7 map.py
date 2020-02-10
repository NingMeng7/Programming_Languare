# map() 对每一个元素进行运算
def f(x):
	return x * x
r = map(f, [1, 2, 3, 4, 5, 6, 7, 8, 9]) # r is iterator!!!
print(list(r))
print(list(map(str, list(range(1,10)))))
input('waiting...')

# -*- coding: utf-8 -*-
#将用户输入的不规范的名字改成首字母大写其他小写的形式
def normalize(name):
	return name[0].upper() + name[1:].lower()
L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)

