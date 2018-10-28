# dict key 迭代
d = {'one': 1, 'two': 2, 'three': 3}
for key in d:
	print(key)
  
input('waiting')

# dict value 迭代
for value in d.values():
	print(value)
  
input('waiting')

# dict key 和 value 一起迭代 实际上这是一个多变量迭代的特殊例子
for k,v in d.items():
	print(k,v)
  
input('waiting')

# string迭代
for ch in 'ABCDEFG':
	print(ch)

# 多变量迭代
for x,y in [(1, 2), (3, 4), (5, 6)]:
	print(x, y)
