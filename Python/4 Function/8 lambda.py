# 匿名函数 lambda 只能有一个表达式，没有return，表达式就是它的return
# lambda x, y: x * y    (lambda variable: 表达式) ！！！ lambda是一个函数!!!

L = list(map(lambda x: x * x, list(range(1,10))))
print(L)

# lambda x: x * x   ~
# def f(x):
#	  return x * x

L = list(filter(lambda x: x % 2 == 1, range(1, 20)))
