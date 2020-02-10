# dict 初始化
iterator = [['ONE', 1], ['TWO', 2], ['THREE', 3]]
d = {key:value for (key, value) in iterator}

str1 = "k:1|k1:2|k2:3|k3:4"
def str2dict(str1):
    dict1 = {}
    for iterms in str1.split('|'):
        key,value = iterms.split(':')
        dict1[key] = value  # 计数产生新的dict
    return dict1
# 字典推导式
d = {k:int(v) for t in str1.split("|") for k, v in (t.split(":"), )}

# 如果知道keys的集合, 也可以
count_dict = dict.fromkeys(action, 0)  #以action中元素为keys, 0为value创建一个dict
