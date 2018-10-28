# @property
# motivation: 单纯的 s.score = 1000 会使得属性被设置成不合理的值，显然我们需要进行参数检查
# 而利用方法s.setscore()会让代码变长,且调用不方便
class Student(object):
	def get_score(self):
		return self._score

	def set_score(self, value):
		if not isinstance(value, int):
			raise ValueError('score must be an integer!')
		if value < 0 or value > 100:
			raise ValueError('score must between 0~100！')
		self._score = Value

bart = Student()
#bart.set_score(101) 
#bart.set_score(-1)
#bart.set_score('89') 

# 上述实现虽然使得参数得到了检查，但是也让代码变长，调用有一些不方便
# property类似于装饰器,可以对调用方法进行一些修饰
class Student(object):
	
	@property
	def score(self):
		return self._score

	@score.setter
	def score(self, value):
		if not isinstance(value, int):
			raise ValueError('Score must be an integer!')
		if value < 0 or value > 100:
			raise ValueError('Score must between 0~100!')
		self._score = value

s = Student()
s.score = 60  # 像调用属性一样调用方法
print(s.score)
#s.score = 9999 # 出错		

# getter and setter： 只读 || 读写
class Student(object):

	@property
	def birth(self):
		return self._birth

	@birth.setter
	def birth(self, value):
		self._birth = value

	@property
	def age(self):
		return 2018 - self._birth

# run the method just like a attribute
bart = Student()
bart.birth = 2000
print(bart.age)
print(bart.birth)



# Sample codes of class Screen
class Screen(object):

	@property
	def width(self):
		return self._width

	@width.setter
	def width(self, value):
		if not (isinstance(value, int) or isinstance(value, float)):
			raise ValueError('Width must be int or float!')
		if value <= 0:
			raise ValueError('Width must be larger than zero!')
		self._width = value

	@property
	def height(self):
		return self._height

	@height.setter
	def height(self, value):
		if not (isinstance(value, int) or isinstance(value, float)):
			raise ValueError('Height must be int or float!')
		if value <= 0:
			raise ValueError('Height must be larger than zero!')
		self._height = value

	@property
	def resolution(self):
		return self._width * self._height

s = Screen()
s.width = 1024
s.height = 768
print('resolution =', s.resolution)
if s.resolution == 786432:
    print('测试通过!')
else:
    print('测试失败!')
