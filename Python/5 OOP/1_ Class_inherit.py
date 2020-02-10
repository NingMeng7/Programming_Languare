# 类 与 继承

# 从父类，基类，超类（Base or super class) Animal 继承
# 子类获得了父类的全部方法
class Animal(object):
	def run(self):
		print('Animal is running...')

class Dog(Animal):
	pass
class Cat(Animal):
	pass

dog = Dog()
dog.run()
cat = Cat()
cat.run()
