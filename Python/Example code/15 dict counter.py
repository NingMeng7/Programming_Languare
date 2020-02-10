# action is a list whose element takes value in [K-1], so the choice of arm m is represented by m-1
# 为了判断collision, 我们需要对各个arm被选中的次数进行计数
action = np.random.randint(0, self.k, self.M)
count_dict = dict.fromkeys(action, 0)  #以action中元素为keys, 0为value创建一个dict
for selected_arm in action:
    count_dict[selected_arm] += 1

'''Remark:
random.randint() 不能一次生成多个随机整数, 且它的范围取的是闭区间
np.random.randint() 可以一次生成多个随机整数, 它的范围是左闭右开
'''