# dict key 迭代
d = {'one': 1, 'two': 2, 'three': 3}
for key in d.keys():
	print(key)
  
input('waiting')

# dict value 迭代
for value in d.values():
	print(value)
  
input('waiting')

# dict key 和 value 一起迭代 实际上这是一个多变量迭代的特殊例子
for key, value in d.items():
	print(key,value)
  

