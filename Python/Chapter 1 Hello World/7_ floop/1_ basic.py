# 一个基本类型的迭代
for n in range(1, 11):          # range左闭右开
  print(n)
input('waiting')

# list 迭代
names = ['Michael', 'Bob', 'Tracy']                 # list 也可以
for name in names:
	print(name)
input('waiting')

# tuple 迭代
names = ('Michael', 'Bob', 'Tracy')                 # tuple 也可以
for name in names:
  print(name)
input('waiting')

# while 循环
names = {}
sum = 0
n = 0
while n <= 4:
	sum = sum + n
	n = n + 1
print(sum)
input('waiting')


