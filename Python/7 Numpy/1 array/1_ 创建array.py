import numpy as np
import  math

# 1. 用arange创建一个array
a = np.arange(12).reshape(3, 4)
print(a[0], a[1], a[2])  # 少于ndim的index给出的时候，默认索引的是整个切片,a[0]~a[0, :]
a[(0, 0)] = 5
print(a)

input('waiting...')

# 2. linespace创建array np.linspace(begin, end, len(array))

b = np.linspace(0, math.pi, 3)  # 0->pi 1X3 array
print(b)
# 3. 用array创建一个array
b = np.array([[1, 2, 3], [4, 5, 6]])
print(b.shape)
print(b[0, 0], b[1, 1])

input('waiting...')

# 4. Create special array
a = np.zeros((2, 2))    # 2X2 matrix of all zeros
print(a)
b = np.ones((1, 2),dtype = 'float64')     # 1X2 matrix of all ones
print(b)
c = np.full((2, 2), 7)  # 2X2 matrix of a constant array
print(c)
d = np.eye(2)   # 2X2 identity matrix
print(d)
e = np.random.random((2, 2))    # 2X2 matrix with random values between 0->1
print(e)
f = np.empty((2, 3))
print(f)
g = np.array([[1,2],[3,4]], dtype = complex)
print(g)

# reshape & resize
# reshape 不修改原对象，返回一个形状改变的对象
# resize 原地改变
a = np.arange(12).reshape(3,4)
print(a.shape)
a.resize(4,3)
print(a.shape)
