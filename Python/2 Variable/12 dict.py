# dict: Hash 	key->value
# 创建字典
scores = {'骆昊': 95, '白元芳': 78, '狄仁杰': 82}
# 创建字典的构造器语法
items1 = dict(one=1, two=2, three=3, four=4)
# 通过zip函数将两个序列压成字典
items2 = dict(zip(['a', 'b', 'c'], '123'))
# 创建字典的推导式语法
items3 = {num: num ** 2 for num in range(1, 10)}
# 更新字典中的元素
scores['白元芳'] = 65
scores['诸葛王朗'] = 71
scores.update(冷面=67, 方启鹤=85)
print(scores.pop('骆昊', 100))

# 通过hash访问元素
d = {'Michael':95,'Bod':90,'Tracy':97}
print(d)
print('The score of Michael is : ',d['Michael'])
d['KangKang'] = 100
print('The score of KangKang is : ',d['KangKang'])

