# 多态
# 子类的 run() 覆盖了父类的run()
# 一个类其实就相当于一种数据类型，需要注意的是，子类仍然是父类，反之不成立
class Animal(object):
	def run(self):
		print('Animal is running...')

class Dog(Animal):
	def run(self):
		print('Dog is running')

dog = Dog()
dog.run() # Dog is running

a = list()
b = Animal()
c = Dog()

print(isinstance(a, list))	#True
print(isinstance(b, Animal))	#True
print(isinstance(c, Dog))	#True
print(isinstance(c, Animal))	#True
print(isinstance(b, Dog))	#False


# 鸭子类型:看起来像鸭子，走起路像鸭子，就可以视作鸭子
class Timer(object):
	def run(self):
		print('Duck is running...')

def func(Animal):
	Animal.run()	# 调用的时候不需要self参数，只有在类的内部定义需要self参数

a = Animal()
b = Dog()
c = Timer()
func(b)
func(a)
func(c)

# 尽管c Timer 不是Animal的子类，但是他也有run方法，也能作为func的参数，而java等静态语言不可以
