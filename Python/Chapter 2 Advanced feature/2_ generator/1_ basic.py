# generator: generate the factors during the floop
# 产生一个generator的语法
g = (x * x for x in range(10))

for n in g:
	print(n)

# almost generator
def fib(max):
	n, a, b = 0, 0, 1
	while n < max:
		print(b)
		a, b = b, a + b
		n = n + 1
	return 'done'

# generator: 顺序执行，碰到yield返回，再次调用next的时候从上次yield返回处继续执行
def fib_(max):
	n, a, b = 0, 0, 1
	while n < max:
		yield b
		a, b = b, a + b
		n = n + 1
	return 'done'

# Yang
def Yang(max):
	temp = [1,]
	n = 1
	while n <= max:
		yield temp
		temp.insert(0, 0)	# insert(index, object)
		temp = [temp[x] + temp[x+1] for x in range(n)]
		temp.append(1)
		n = n + 1
	return 'done'
#	生成第n行的时候为n-1，insert0后共有 0，1，2 ... n
#	range(n-1): 0 ... n-2  (n-2)+(n-1)完成后再append个1，共n个元素
