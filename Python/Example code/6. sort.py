# sorted(list, func(可选))
L = sorted([36, 5, -12, 9, -21])
print(L)
# 按绝对值大小进行排序
L = sorted([36, 5, -12, 9, -21], key = abs)
print(L)
# 字符串按ASCII排序
L = sorted(['bob', 'about', 'Zoo', 'Credit'])
print(L)
# 字符串忽略大小写进行排序
L = sorted(['bob', 'about', 'Zoo', 'Credit'], key = str.lower)
print(L)
# 从大到小排序
L = sorted([36, 5, -12, 9, -21], reverse = True, key = abs)
print(L)

L1 = sorted(L, key = lambda x:x[0])
L2 = sorted(L, key = lambda x:x[1])
