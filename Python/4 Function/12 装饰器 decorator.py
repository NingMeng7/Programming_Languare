
# decorator 装饰器: 返回函数的高阶函数
# why decorator?
# 不修改被装饰函数的源代码
# 不改变被装饰函数的调用方式
# 在以上原则下为程序增加新的功能
# 返回一个函数继续利用后面的参数这个操作有点骚

# 基本形式

import functools
def log__(func): # 将目标函数func传进来
	@functools.wraps(func) # 对函数名进行包装
	def wrapper(*args, **kw): 
		print('call %s():' % func.__name__)
		return func(*args, **kw)
	return wrapper
@log__	# ~ now = log(now)
def now():
	print('2018-3-12')
now() # 调用now其实是调用log(now)(参数)传入wrapper,最后wrapper返回func实现目标函数
input('waiting...')

# if decotator need paraments： 三重嵌套

import functools
def log___(text):
	def decorator(func):
		@functools.wraps(func)
		def wrapper(*args, **kw):
			print('%s %s():' % (text, func.__name__))
			return func(*args, **kw)
		return wrapper
	return decorator

@log___('execute')	# now = log_('execute')(now) now是返回的decorator的参数
def now(name):
	print(name, '2018-3-12')
now('XW')
input('waiting')

# 计算执行时间
import time
def metric(fn):
	@functools.wraps(fn)
	def wrapper(*args, **kw):
		start = time.time()
		f = fn(*args, **kw)		#提前执行，保留返回值
		end = time.time()
		print('%s excuted in %s ms' % (fn.__name__, end - start))
		return f
	return wrapper
@metric
def fn(L):
	return sorted(L)
print(fn([2,4,1,2,3,5,6,6,6754,4,645,4,32,2,1,23,1,23,123,12,4,1,2,12,41,24,12,45,4,665,6,56,5,]))
