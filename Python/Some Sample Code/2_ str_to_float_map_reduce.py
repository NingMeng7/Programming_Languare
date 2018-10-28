from functools import reduce
DIGITS = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}

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
