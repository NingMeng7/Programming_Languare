# numpy提供很多对数组按元素进行运算的函数
# 数组的运算是按照元素进行的，矩阵乘法通过函数和矩阵对象实现

# 1. 对每个元素进行相同的处理
a = np.array([20, 30, 40, 50])
b = np.arange(4)
print(a-b)
print(b**2) # 所有元素平方
print(10 * np.sin(a))

a = np.random.random((2, 3))
print(a)
print(a.sum())
print(a.min())
print(a.max())

# 2. 矩阵乘法
A = np.array([[1, 1],
              [0, 1]])
B = np.array([[2, 0],
              [3, 4]])
print(A * B)
print(np.dot(A, B))



# 3. 也可以把一些运算对特定轴进行
a = np.arange(12).reshape(3, 4)
print(a)
print(a.sum(axis=0))  # 沿着行加,即变量是行,所以得到的结果(a01+a11+21)
print(a.sum(axis=1))
print(a.cumsum(axis=0)) # cumulative sum aloing the row
print(a.cumsum(axis=1))

input('waiting...')
# array的迭代
b = np.array([[0, 1, 2, 3],
              [10, 11, 12, 13],
              [20, 21, 22, 23],
              [30, 31, 32, 33],
              [40, 41, 42, 43]])
for row in b:   # 按行
    print(row)
for element in b.flat:  # 按元素
    print(element)
    
# 4. stack 组合不同的数组
a = np.floor(10*np.random.random((2, 2)))
b = np.floor(10*np.random.random((2, 2)))
print(a)
print(b)
print(np.vstack((a, b)))    # vstack沿着第一个轴组合(行为变量)
print(np.hstack((a, b)))    # hstack沿着第二个轴组合
