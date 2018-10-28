# This file shows some methods of str
t = 'He is a string. Who are you?'

print(t.capitalize()) # Cap first letter

print(t.split()) #split by word

a, b = t.split('.') # 根据'.'两侧进行str的划分

print(t.find('i'))
print(t.find('Python'))
print(t[0:4])
print(t.replace(' ', '|'))

w = 'http://www.google.com'
print(w.strip('http://'))	#delete 'http://'

print(t.upper())  # string 变大写
print(t.lower())  # string 变小写
print(t + 'HaHaHa') # string 的附加可以直接用+完成

print(t.count('e', 0, len(t)))  # 从0->len-1 中有多少个'e', 这里也是左闭右开

print(t.isalpha()) # string至少有一个字符并且所有字符都是字母则True
print(t.isalnum()) # string至少有一个字符并且所有字符都是字母或者数字则True
