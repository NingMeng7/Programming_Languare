# 以函数作为返回值
def lazy_sum(*args):
	def sum():
		ax = 0
		for n in args:
			ax = ax + n
		return ax
	return sum
f1 = lazy_sum(1, 3, 5, 7, 9) #可变参数自动组装成一个tuple传入
f2 = lazy_sum(1, 3, 5, 7, 9) #得到的返回值是以传入参数为参数的一个还没有执行的函数sum!!!
if f1 == f2:
	print('Yes! f1==f2')

# 在函数lazy_sum 中又定义了sum，而内部函数sum又可以引用外部函数lazy_sum的参量和局部参数
# 但是要注意的是，尽管从上面看见两次返回的两个函数是互不影响的
# 但是返回的函数并没有立刻执行，因此返回函数不应该引用任何循环变量或者后续会变化的变量

def count():
	fs = []
	for i in range(1,4):
		def f():
			return i * i
		fs.append(f)
	return fs
f1, f2, f3 = count()

print(f1())
print(f2())
print(f3())
# 结果都为9

# 解决办法,另外再建立一个函数，提前执行最底层函数
def count_():
	def f(j):
		def g():
			return j * j
		return g
	fs = []
	for i in range(1, 4):
		fs.append(f(i))
	return f  s

print(f1())
print(f2())
print(f3())
# 结果为1,4,9

# 递增函数
# 内层函数修改外层变量的时候要求外层变量必须得是可变类型，因此用list
  def CreateCounter():
    s = [0]
    def counter()：
      s[0] = s[0] + 1
      return s[0]
    return counter	

f = CreateCounter()
for i in range(1, 10):
    print(f())
# 这里的s[0] 定义在外部函数，而之前的求和函数ax=0是在内部函数定义的, 要引用s[0]必须要求它是一个可变对象
# 因此这里的s[0] 的结果在多次调用中会被记忆，而求和函数每次都会把ax=0，是不会被记忆的
