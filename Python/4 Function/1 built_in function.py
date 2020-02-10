# 一些内置函数可以直接调用
print('|20| = ', abs(20))
print('|-20| = ', abs(-20))

print('max(1,2,3,4) = ', max(1,2,3,4))

# 类型转换
print(int('123'))
print(float('123'))
print(str(123))
print(bool(1))
print(bool(''))
print(int('123', 16)) # 以16进制解释整个字符串得到一个十进制数
print(bin(123)) # 转化为二进制数
print(hex(123)) # 转化为16进制数
printf = print
printf('printf(printf)')

L = [1, 10]

if(isinstance(L, Iterable)):
		print('Yes!')
