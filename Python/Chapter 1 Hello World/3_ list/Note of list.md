## list 
list 是python的一种基本类型，它和数组很类似，但是和C语言的数组还是有很大区别的

    L = [[1,2,3], 4, 5, 6]
    print(id(L[0]))
    print(id(L[1]))
    #list内的内存竟然可能不是连续的！！！
    
## list 的三种查找操作
1. in操作符: 判断值是否在list中
 
        L = ['a', 'b', 'c', 'd', 1, 2, 3, 4]
        print('a' in L)
        print(1 in L)

2. count方法: 判断指定值在list中出现的次数  

L.count('a')  : 统计'a'在L中出现的次数

注意list没有 L.count('a', begin, end)的方法，这个只有str有 

        L = ['a', 'b', 'b', 'd', 1, 2, 3, 4]
        print(L.count('b'))
        print(L.count('b'))

3. index方法: 查看指定值在list中的位置:

L.index('a')  : 返回'a'在L中第一次出现的位置

L.index('a', begin, end)  : 返回a在指定切片中第一次出现的位置 [begin, end)
    
## list的脚本操作符
1. len([1,2,3,4])                   4

2. [1,2,3] + ['a','b','c']          [1,2,3,'a','b','c']

3. ['a']\*3                          ['a','a','a']

4. 3 in [1,2,3,4]                   True

5. for i in [1,2,3,4]:                迭代器不断给出next，直到抛出错误

## list 函数 & 方法
1. L.append(obj)                      在列表末尾添加新的对象

2. L.count(obj)                        统计某个元素在列表中出现的次数

3. L.extend(seq)                       用新列表扩展原列表    和直接+相比可以保持地址不变

4. L.index(obj)                        切片可选,找出某个值的第一个匹配项索引位置

5. L.insert(index, obj)                 插入对象

6. a = L.pop()                          删除并返回L的最后一个元素

7. L.remove(obj)                        删除某个值的第一个匹配项

8. L.reverse()                          反向列表中的元素

9.L.sort(func)                                               
        
