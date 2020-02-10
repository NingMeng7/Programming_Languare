# 特殊函数定制类
class Student(object):
	def __init__(self, name):
		self.name = name
	def __str__(self):
		return 'Student object (name: %s)' % self.name
  __repr__ = __str__
print(Student('Michael'))

class Fib(object):
	def __init__(self):
		self.a, self.b = 0, 1

	def __iter__(self):
		return self

	def __next__(self):
		self.a, self.b = self.b, self.a + self.b
		if self.a > 100000:
			raise StopIteration()
		return self.a

	def __getitem__(self, n):	# 让类可以像list一样用下标取数
		if isinstance(n, int):
			a, b = 1, 1
			for x in range(n):
				a, b = b, a + b
			return a
		if isinstance(n, slice):
			start = n.start
			stop = n.stop
			if start is None:
				start = 0
			a, b = 1, 1
			L = []
			for x in range(stop):
				if x >= start:
					L.append(a)
				a, b = b, a + b
			return L
	def __getattr__(self, attr):
		if attr == 'score':
			return 99
		elif attr == 'age':
			return lambda: 25
		else:
			raise AttributeError('\'Student\' object has no attribute \'%s\'' % attr)
	def __call__(self):
		print('My name is %s.' % 'Michael') # s()让实例变成可调用对象

count = 0
for n in Fib():
	print(n)
	count += 1
f = Fib()
print(f[5])
print(f[0:5])
print(f.score)
print(f.age())
print(f())
