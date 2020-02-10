# 命名关键字参数：关键字参数可以有任意个，但是命名关键字参数只接收city job作为关键字参数(避免乱传数据进来)
# 命名关键字参数一定要带有参数名
# 命名关键字可以有缺省值
def person3(name, age, *, city, job):  # *，后的字符被认为命名关键字参数
	print(name, age, city, job)

person3('Jane', 23, city='Beijing', job='Engineer')	
input('waiting...')

# 如果函数定义中已经有了一个可变参数，后面的命名关键字参数就不需要特殊分隔符*，了
def person4(name, age, *args, city, job):
	print(name, age, args, city, job)
input('waiting...')

def person5(name, age, *, city='Beijing', job): #命名关键字可以有缺省值
	print(name, age, city, job)
person5('Jack', 24, job='Engineer')  #可以不传入city	
input('waiting...')


# 整体的一个例子
def func1(a, b, c=0, *args, **kw):
	print('a=', a, 'b=', b, 'c=', c, 'args', args, 'kw=', kw)

func1(1, 2)
func1(1, 2, 3)  # 3是默认参数
func1(1, 2, 3, 'a', 'b')
func1(1, 2, 3, 'a', 'b', job='Engineer', x=77)
tup = ('a', 'b')
kw = {'job':'Engineer', 'x':77}
func1(1, 2, 3, *tup, **kw)