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

# 可变参数,自动组装成一个tuple传入，如果不用可变参数要先定义一个list或者tuple
# 在list或者tuple前面加个*就能当成可变参数传入
def add(*numbers):
	sum = 0
	for n in numbers:
		sum = sum + n
	return sum	

print('add(1,2,3,4,5) = ',add(1,2,3,4,5))
a = [1,2,3,4,5]
print('add(1,2,3,4,5) = ',add(*a)) 
input('waiting...')

# 关键字参数: 可以输入任意个数的关键字参数，自动组装成一个dict,可以先组装一个dict，然后加**传入
def person(name, age, **kw):
	print('name:', name, ' age:', age, ' other:', kw)

person('Michael', 30)
person('KangKang', 30, gender='M', city='Beijing')
extra = {'city':'Beijing','job':'Engineer'}
person('Jack', 24, city=extra['city'], job=extra['job'])  # kw获得的是extra的拷贝，无法对原extra进行修改
person('Jcak', 24, **extra)
input('waiting...')

# 命名关键字参数：关键字参数可以有任意个，但是命名关键字参数只接收city job作为关键字参数(避免乱传数据进来)
# 命名关键字参数一定要带有参数名
# 命名关键字可以有缺省值
def person3(name, age, *, city, job):  # *，后的字符被认为命名关键字参数
	print(name, age, city, job)

person3('Jane', 23, city='Beijing', job='Engineer')	
input('waiting...')

# 如果函数定义中已经有了一个可变参数，后面的命名关键字参数就不需要特殊分隔符*，了
def person4(name, age, *args, city, job):
	print(name, age, args, city, job)
input('waiting...')

def person5(name, age, *, city='Beijing', job): #命名关键字可以有缺省值
	print(name, age, city, job)
person5('Jack', 24, job='Engineer')  #可以不传入city	
input('waiting...')


# 整体的一个例子
def func1(a, b, c=0, *args, **kw):
	print('a=', a, 'b=', b, 'c=', c, 'args', args, 'kw=', kw)

func1(1, 2)
func1(1, 2, 3)  # 3是默认参数
func1(1, 2, 3, 'a', 'b')
func1(1, 2, 3, 'a', 'b', job='Engineer', x=77)
tup = ('a', 'b')
kw = {'job':'Engineer', 'x':77}
func1(1, 2, 3, *tup, **kw)
