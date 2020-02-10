# 获取对象信息

# 判断对象的类型 
# 1. type() 
import types

print(type(123))
print(type('str'))
print(type(None))

def fn():
	pass
if type(123) == int:
	print('123 is int')
if type('str') == str:
	print('str is srt')
if type(fn) == types.FunctionType:
	print('fn is a function')

class Animal(object):
	pass
class Dog(Animal):
	pass
class Husky(Dog):
	pass

a = Animal()
b = Dog()
c = Husky()

if isinstance(c, Dog):
	print('Yes,c is Dog')	#T
if isinstance(c, Animal):
	print('Yes,c is Animal')	#T
if isinstance(b, Animal):
	print('Yes,b is Animal')	#T
if isinstance(a, Dog):
	print('Yes,a is Dog')	#F
# isinstance()可以判断指定类型，以及他的子类

# dir()获得一个对象的所有属性和方法
# 判断属性存在与设置属性
class MyObject(object):
	def __init__(self):
		self.x = 9
		def power(self):
			return self.x * self.x
obj = MyObject()

hasattr(obj, 'x')	# 有属性'x'吗
hasattr(obj, 'y')	# 有属性'y'吗
setattr(obj, 'y', 19) # 设置一个属性'y'
getattr(obj, 'y')	# 获取属性'y'
