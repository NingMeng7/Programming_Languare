# 可变对象(对象内容可变)： list, dict.
# 不可变对象有(对象内容不可变): int, string, float, tuple

# 不可变对象
# 可以发现,在改变a的值后,id的地址也随之改变,实际上我们改变a的值并不是原地改变,而是创建一个新的对象再返回给a。
a = 2
print(id(a))
a = 3
print(id(3))

# 可变对象
a = [1, 2, 3]
print(id(a))
a[0] = 10
print(id(a))

# is 与 == 的差别
# is: id
# ==: 内容
a = 2
b = 2.0
print(a == b) # True
print(a is b) # False
