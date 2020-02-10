a = 100
def foo():
	a = 200  # 局部变量
	print(a)
foo()
print(a)

'''
200
100
'''

def foo2():
	global a # 指示下面的a来自于全局作用域
	a = 200
	print(a)
foo2()

'''
200
200
'''

# nonlocal 关键字可以指示变量来自于嵌套作用域