# 可变参数,自动组装成一个tuple传入，如果不用可变参数要先定义一个list或者tuple
# 在list或者tuple前面加个*就能当成可变参数传入
def add(*numbers):
	sum = 0
	for n in numbers:
		sum = sum + n
	return sum	

print(add(1,2,3,4,5))

a = [1,2,3,4,5]
print('add(1,2,3,4,5) = ', add(*a)) 
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