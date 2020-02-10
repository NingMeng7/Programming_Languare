# 当调用一个instance的属性或者方法的时候,优先查询instance的属性或者方法,因此instance的属性方法会屏蔽类的属性方法
# __slots__
class Student(object):
	pass

# 1. 给instance绑定属性
s = Student()
s.name = 'Michael'	# 给Student的实例s绑定属性name

# 2. 给instance绑定方法
from types import MethodType
def set_age(self, age):
	self.age = age
#s.set_age = set_age
s.set_age = MethodType(set_age, s)
if hasattr(s, 'set_age'):
	print('Yes,s has a set_age')

# 3. 给class 绑定属性的方法
Student.age = 18

# 4. 给class!!类!!在定义之后动态绑定方法
Student.set_age = set_age
s2 = Student()
if hasattr(s2, 'set_age'):
	print('Yes,s2 has a set_age attribute')

# 如果我们不想让实例的属性绑定太过于自由，例如只允许对Student添加 name or age 可以采用__slots__
# __slots__ 不会被子类继承
class Student(object):
	__slots__ = ('name', 'age')
class GraduateStudent(Student):
	pass
bart = Student()
# bart.score = 90	 wrong
bart_ = GraduateStudent()
bart_.score = 90 # OK, __slots__ 不会被子类继承
