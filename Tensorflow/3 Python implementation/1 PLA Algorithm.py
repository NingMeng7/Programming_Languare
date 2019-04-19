import numpy as np
import matplotlib.pyplot as plt
'''
实现感知机算法：对所有 W·X * Label <= 0 的样本进行更新, 其中Label 取值为{+1, -1}
'''


def Plot(Data, Label, weight):
    # plot the result and training set
    weights = np.array(weight)
    m = Data.shape[0]
    xrecord1 = []
    yrecord1 = []
    xrecord2 = []
    yrecord2 = []
    for i in range(m):
        if int(Label[i] == 1):
            xrecord1.append(Data[i, 0])
            yrecord1.append(Data[i, 1])
        else:
            xrecord2.append(Data[i, 0])
            yrecord2.append(Data[i, 1])
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    ax.scatter(xrecord1, yrecord1, s=30, c='red', marker='s')
    ax.scatter(xrecord2, yrecord2, s=30, c='green')

    if weights[0] == 0:
        x = np.arange(-1.5, 1.5, 0.1)  # arange(start, stop, step)
        y = np.zeros(x.shape[0]) + -weights[2] / weights[1]
    elif weights[1] == 0:
        y = np.arange(-1.5, 1.5, 0.1)  # arange(start, stop, step)
        x = np.zeros(y.shape[0]) + -weights[2] / weights[0]
    else:
        y = (-weights[2] - weights[0] * x) / weights[1]  # 蕴含了θ'X=0(边界线g(0)=0.5)
    ax.plot(x, y)

    plt.xlabel('X1')
    plt.ylabel('X2')

    plt.show()


def PLA(Data, Label, MaxIteration):
    '''
    :param Data: Training set (sample feature vector with additional '1')
    :param Label: The class label of each sample
    :param MaxIteration: Max round
    :return: weight W
    '''
    m, n = Data.shape
    weights = np.ones(n)  # w0x+w1y+w2 = 0
    flag = 1  # flag 表示是否找到完全分开数据的超平面
    count = 0  # 控制最大迭代次数(防止非线性可分情况死循环)
    while flag == 1:
        flag = 0
        count = count + 1
        for i in range(m):
            print(weights)
            if Label[i] * np.dot(Data[i], weights.T) <= 0:  # 如果第i个样本被误分类
                diff = np.array(alpha * Label[i] * Data[i])
                weights = weights + diff
                flag = 1
        if count > MaxIteration:
            break
    return weights


alpha = 1   # learning rate
Data = np.array([[0.0, 0.0, 1.0], [0.0, 1.0, 1.0], [1.0, 0.0, 1.0], [1.0, 1.0, 1.0]])   # Data
Label = np.array([[1], [1], [-1], [-1]])  # Label
weights = PLA(Data, Label, 1000)
print('The hyperplane can be written by:')
print(weights[0], '* x1 + ', weights[1], '* x2 + ', weights[2], ' = 0')
Plot(Data, Label, weights)

