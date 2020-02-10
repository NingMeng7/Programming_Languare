# list 的初始化与访问
classmates = ['Michael','KangKang','Jane','Maria'];
print(classmates);
print('The number of Classmates is:',len(classmates));

print(classmates[-1]); 	#访问最后一个元素 -2 -3...

list1 = [1] * 3 # [1, 1, 1]

for index in range(len(list1)):
    print(list1[index])
# 通过for循环遍历列表元素
for elem in list1:
    print(elem)
	
for index, elem in enumerate(list1):
    print(index, elem)
input('waiting...')

# list方法来增添成员
list1 = [1, 3, 5, 7, 100]
# 添加元素
list1.append(200)
list1.insert(1, 400) # 1 是索引位置
# 合并两个列表
# list1.extend([1000, 2000])
list1 += [1000, 2000]
print(list1) # [1, 400, 3, 5, 7, 100, 200, 1000, 2000]
print(len(list1)) # 9
# 先通过成员运算判断元素是否在列表中，如果存在就删除该元素
if 3 in list1:
	list1.remove(3)
if 1234 in list1:
    list1.remove(1234)
print(list1) # [1, 400, 5, 7, 100, 200, 1000, 2000]
# 从指定的位置删除元素
list1.pop(0)
list1.pop(len(list1) - 1)
print(list1) # [400, 5, 7, 100, 200, 1000]
# 清空列表元素
list1.clear()
print(list1) # []

# list作为成员的list(比多维数组更灵活)
L = ['Apple',123,True,['python','c++']];
print(L[3][1]);

input('waiting...')
