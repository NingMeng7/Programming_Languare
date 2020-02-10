# 必选参数: 		 最普通的参数 x
# 默认参数: 		 n=2 
# 可变参数: 	 	 *numbers  !!tuple
# 关键字参数:     **kw      !!dict   关键字参数一定要带参数名传入 
# 命名关键字参数:  *, city, age
# 参数组合顺序必须是：  必选参数，默认参数，可变参数，命名关键字参数，关键字参数


# n = 2 为默认参数，当不输入n的时候相当于认为n=2
# 需要注意的是，对于可变对象List/dict的默认参数，由于原地修改值，会被记忆，所以应当用不可变对象作为默认参数
def power(x, n=2):
	s = 1
	while n > 0:
		n = n - 1
		s = s * x
	return s
	
print(power(4,2))
print(power(4))
input('waiting...')

# 一个用可变对象当默认参数的错误例子
def test(L=[]):
	L.append('END')
	print(L)
test()
test()

input('waiting...')

# 多个默认参数,可以通过指定名称的形式来给值(而不必像C++那样受到参数给出顺序的限制)
def enroll(name, gender, age=6, city='Beijing'):
	print('name: ', name)
	print('gender: ', gender)
	print('age: ', age)
	print('city: ', city)
	print('\n')

enroll('KangKang','M')
enroll('Michael','M',7,'London')
enroll('LiLei','M',city='SiChuan')
input('waiting...')



