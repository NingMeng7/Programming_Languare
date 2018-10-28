# Class(类) and instance(实例)
#	__init__ 的第一个参数一定是self表示实例自身，传入对应参数的时候self不需要显示传入
# 和普通的函数相比，类的方法在定义的时候第一个参数永远是实例变量self,并且在调用的时候隐式地传递这个参数，除此之外，类的方法和普通函数类似
class Student(object):	# 模板作用 object是继承的类
	def __init__(self, name, score):
		self.name = name
		self.score = score

bart = Student('Xiao Ming', 89)	# instance of class Student
print(bart.name)
print(bart.score)


# 封装
# 封装: 从外部看Student只需要知道创建Instance的时候要提供name score
# 打印的方法也是在Student类内部定义的
# 对Student进行操作不需要知道内部的细节，而只需要了解接口特性
# 方法是与实例instance绑定的函数
def print_score(std):
	print("%s: %s" % (std.name, std.score))

print_score(bart)

# 进一步可以把这种方法也封装到类里，成为类的方法
class Student(object):

	def __init__(self, name, score):
		self.name = name
		self.score = score

	def print_score(self):
		print('%s: %s' % (self.name, self.score))

	def get_grage(self):
		if self.score >= 90:
			return 'A'
		elif self.score >= 60:
			return 'B'
		else:
			return 'C'

bart = Student('Xiao Ming', 89)
bart.print_score()



bart.age = 10  
bart.score = 90
# 可以让实例绑定其他数据，因此两个同一个类的实例可能拥有不同的变量	
# 并且可以修改实例的某个变量的值
# 如果想要让内部属性不被外部访问
# __xx: Private变量
# __xx__: 特殊变量
# _xx: 可以访问，但是按照约定俗成的规矩，应当视作是私有变量，不要随意访问
class Student(object):

	def __init__(self, name, score):
		self.__name = name
		self.__score = score

	def print_score(self):
		print('%s: %S' % (self.__name, self.__score))

	def get_name(self):
		return self.__name
	def get_score(self):
		return self.__score
	
	def set_name(self, name):
		self.__name = name
	def set_score(self, score):
		if 0 <= score <= 100:
			self.__score = score
		else:
			raise ValueError('bad score')
