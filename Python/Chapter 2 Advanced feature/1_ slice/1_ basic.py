# 切片索引是左闭右开的
# L[0:3]  表示从0开始取，但是不包括3！！！ 0 1 2
# 开始索引或者结束索引如果是0可以省略
L = list(range(100))
print('0->99: ')
print(L)
print(L[0:10])
print(L[-10:])
print(L[10:20])

# print(begin:end:step)   
print(L[:10:2])
print(L[::5])

# string slice
string = 'ABCDEFG'
print(string)
print(string[2:4])
print(string[2])



# -*- coding: utf-8 -*-
def trim(s):
	i = 0
	j = len(s) - 1
	while i < len(s) and s[i] == ' ':
		if s[i] == ' ':
			i =	 i + 1
	while j > 0 and s[j] == ' ':
		if s[j] == ' ':
			j = j - 1
	s = s[i:j+1] #	切片左闭右开
	print(s)
	return s

if trim('hello  ') != 'hello':
    print('测试失败!')
elif trim('  hello') != 'hello':
    print('测试失败!')
elif trim('  hello  ') != 'hello':
    print('测试失败!')
elif trim('  hello  world  ') != 'hello  world':
    print('测试失败!')
elif trim('') != '':
    print('测试失败!')
elif trim('    ') != '':
    print('测试失败!')
else:
    print('测试成功!')	
  
