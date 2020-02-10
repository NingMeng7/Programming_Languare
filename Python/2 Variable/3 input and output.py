"""
input()从键盘获取的是字符串
int()将输入的字符串转换成整数
"""
import decimal
print("chr(65): ", chr(65))	
print("ord('A'): ", ord('A'))
dic = {'runoob': 'runoob.com', 'google': 'google.com'}
print(str(dic))

print(round(3.1415, 2))
print(round(9.995, 2))
print(decimal.Decimal(9.995))

a = 1
b = 4 
print('{0} * {1} = {2}'.format(a, b, a * b))

name = input('Please enter your name:');
if 'YuHui' in name or 'YH' in name:
	print('Hi！')
else:
	print('Hello', name);


