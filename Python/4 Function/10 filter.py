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
	return lambda x: x % n > 0

# prime 也是一个generator, 所以要yield
def primes():
	yield 2 # 2 是素数
	it = _odd_iter()	# it是一个generator 可迭代对象
	while True:
		n = next(it)
		yield n
		it = filter(_not_divisible(n), it) # 如果序列中数x整除比它小的奇数, 那么它会被删掉(不是素数)
        # 不用担心这种情况: 如果 x 整除9, 那么即使9提前被删, x必然整除3, 所以其实不需要测试9 
        
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
