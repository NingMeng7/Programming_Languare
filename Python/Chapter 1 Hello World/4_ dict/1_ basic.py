# dict: Hash 	key->value
# 通过hash访问元素
d = {'Michael':95,'Bod':90,'Tracy':97}
print(d)
print('The score of Michael is : ',d['Michael'])
d['KangKang'] = 100
print('The score of KangKang is : ',d['KangKang'])

print('KangKang in dict? ','KangKang' in d)
print('LiLei in dict? ','LiLei' in d)

print(d.get('Bod'))
d.pop('KangKang') # del d['KangKang']
print('KangKang in dict? ','KangKang' in d)

# key一定要为不可变对象如str，而可变对象list之类的因为不能判断是否相等不能作为key
# 对不可变对象的操作只是返回一个新的值，而没有对本身进行修改
a = 'abc'
b = a.replace('a','A')
print(a)
print(b)
