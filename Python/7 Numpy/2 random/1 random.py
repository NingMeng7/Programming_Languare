import numpy.random as random

# 1. 产生一个随机数矩阵,元素0->1
x = random.rand()   #   产生一个单一的[0,1)之间的float随机数
a = random.random((3,4))
print(a)
print(a*5 + 1)  # 可以这样得到不同范围内的随机数

input('waiting')
# 2. 产生整型随机数:
# random.randint(begin, end, number) 产生number个[begin, end) 的随机整数
print(random.randint(1, 6, 10))

input('waiting')
# 3. 概率分布随机数产生
# 3.1 正态分布 
# np.random.normal(loc=0.0, scale=1.0, size=None)
# np.random.randn(d0, d1, d2,...,dn) 返回一个d0*d1*d2*...*dn维的标准正态分布                  
norm = random.normal(10, 1, (3,3))
print(norm)
norm = random.randn(3,3)
print(norm)

input('waiting')
# 3.2 二项分布
# np.random.binomial(n, p, size=None)
print(sum(np.random.binomial(100,0.5,1000))/1000/100)

input('waiting')
# 5 随机打乱序列,多维数组只针对第一个轴进行打乱
x = list(range(1,10))
random.shuffle(x)
print(x)

# 6 随机抓取序列的一个元素
# numpy.random.choice(a, size=None, replace=True, p=None)
# 如果a是整数,就在range(a)中抓取,如果a是列表就在列表中抓取,size是抓取的次数
print(random.choice(['a', 'b', 'c', 'd', 'e']))
print(random.choice(5, 3, p=[0.1,0.3,0.2,0.3,0.1])) 

