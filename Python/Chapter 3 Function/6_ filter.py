# filter(function, list[]) 筛选序列:只有被function作用后返回True的才会被保留

def is_odd(n):
	return n % 2 == 1
L = list(filter(is_odd,[1,2,4,5,6,9,10,15]))
print(L)
input('waiting...')

# 1. filter 删除空字符
def not_empty(s):
	return s and s.strip()	# s:去除None or ''   s.strip()：去除s内的white space

L = list(filter(not_empty, ['A', '', 'B', None, 'C', ' ']))
print(L)
input('waiting...')

# 2. filter 求素数
def _odd_iter(): # 奇数生成器generator
	n = 1
	while True:
		n = n + 2
		yield n

def _not_divisible(n):
	return lambda x: x % n > 0	# 如果==0说明它以n为因子，就肯定不是素数了 返回一个函数，再对it序列作用

def primes():
	yield 2
	it = _odd_iter()	# it是一个generator 可迭代对象
	while True:
		n = next(it)
		yield n
		it = filter(_not_divisible(n), it) # 构造新序列

for n in primes() :
	if n < 1000:
		print(n)
	else:
		break
    
input('waiting')

# filter 回文判断
def judge(s):
	s = str(s)
	i = 0;
	j = len(s) - 1
	while i < j:
		if(s[i] != s[j]):
			return False
		i = i + 1
		j = j - 1
	return True
output = list(filter(judge, range(1, 1000)))
print(output)
