# reduce() 作用在一个有两个参数的函数，把结果和序列下一个继续运算
# f(f(f(x1,x2),x3),x4)
from functools import reduce
def add(x, y):
	return x + y
reduce(add, [1, 3, 5, 7, 8])

# str to int
DIGITS = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}
def add_(x, y):
	return x * 10 + y
def char_to_num(s):
	return DIGITS[s]
def str_to_int(s):
	return reduce(add_, map(char_to_num, s))
print(str_to_int('74242'))

input('waiting...')

#prod(list) 求积
def prod(L):
	def mult(x, y):
		return x * y
	print("The result is: ", reduce(mult, L))

# str2float(s)
def fun(x, y):
	return x * 10 + y
def str2float(s): # 分别转换int and decimal,然后对decimal进行移位
	s1, s2 = s.split('.')	
	_int = reduce(fun, map(int, s1[:]))
	temp = len(s2)
	_decimal = reduce(fun, map(int, s2[:]))
	_decimal /= pow(10, temp)
	return _int + _decimal
