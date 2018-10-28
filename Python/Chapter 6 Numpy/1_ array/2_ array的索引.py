# 一维数组 trivial

# 1. 多维数组
a = np.arange(12).reshape(3, 4)
a[(0, 0)] = 5   # 多维数组索引一个子元素由tuple给出index
print(a[0], a[1], a[2])  # 少于ndim的index给出的时候，默认未给出的维度索引是整个切片,a[0]~a[0, :]
print(a)

# 2. slice of matrix
# 切片的时候索引规则仍然是左开右闭
# 混合整型索引和切片索引得到的数组rank会降低
# 对索引矩阵修改会体现在原矩阵上
a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])  # 3X4

print(a[:2, 1:3])

row_r1 = a[1, :]  # shape(4,)
row_r2 = a[1:2, :]  # shape(1,4)
print(row_r1, row_r1.shape)  # row_r1 ndim==1 即tuple的长度
print(row_r2, row_r2.shape)  # row_r2 ndim==2

input('waiting')

# 3. 整型索引
print(a[[0, 1, 2], [0, 1, 2]])  # 整型索引~ print(a[0, 0], a[1, 1], a[2, 2)
a[np.arange(3), [0, 1, 2]] += 10    # 整型索引一个作用是对矩阵特定值进行修改
print(a)

# 4. 条件索引(Bool 索引)
a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])  # 3X4
bool_idx = (a > 3)
print(a)
print(bool_idx)
print(a[a > 3])  # rank1 array
input('waiting...')
