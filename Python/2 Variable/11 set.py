# set only key but no value
# set 没有重复的元素, 而且无序，所以不能index， 有一个应用是比如决策树构造的时候需要去除重复的特征值
set1 = {1, 2, 3, 3, 3, 2}

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
print(s1 <= s2) # 子集关系

# 创建集合的推导式语法(推导式也可以用于推导集合)
set4 = {num for num in range(1, 100) if num % 3 == 0 or num % 5 == 0}