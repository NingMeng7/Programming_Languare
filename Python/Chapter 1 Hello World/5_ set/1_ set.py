# set only key but no value
# set 没有重复的元素, 而且无序，所以不能index， 有一个应用是比如决策树构造的时候需要去除重复的特征值
s = set([1,2,3])
print(s)

s.add(4)
print(s)

s.remove(4)
print(s)

s1 = set([1,2,3])
s2 = set([2,3,4])
print(s1 & s2)
print(s1 | s2)
