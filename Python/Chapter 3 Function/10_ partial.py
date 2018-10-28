print(int('12345'))
print(int('12345', base = 16))

# 偏函数 partial，固定住函数的某些参数
import functools
int2 = functools.partial(int, base = 2)

#等价于

def int2_(x, base=2)：
	return int(x, base)
