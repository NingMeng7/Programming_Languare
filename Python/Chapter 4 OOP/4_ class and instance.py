# 定义的类
# 实例instance的属性会覆盖类的属性，只有当实例的属性被删除后才会访问类的属性
class Student(object):
	name = 'Student'
s = Student()
print(s.name) # Student
s.name = 'Michael' 
print(s.name) # Michael

# 一个用count 计数多少instance被初始化的例子

class Cou_Student(object):
	count = [0] # work
	def __init__(self, name, age):
		#Cou_Student.count[0] = Cou_Student.count[0] + 1
		self.count[0] = self.count[0] + 1 # also work
		self.__name = name
		self.__age = age	
	def print_age(self):
		print('%s: %s' % (self.__name, self.__age))
	def set_age(self, age):
		self.__age = age
	def set_name(self, name):
		self.__name = name
	def get_number(self):
		#print(Cou_Student.count[0])
		print(self.count[0])
for i in range(1,10):
	x = Cou_Student('x', i)
	x.get_number()





