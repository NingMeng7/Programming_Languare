import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt

mpl.rcParams['xtick.labelsize'] = 24
mpl.rcParams['ytick.labelsize'] = 24

np.random.seed(42)

# 画出二维图像
x = np.linspace(0,5,100)
y = 2*np.sin(x) + 0.3*x**2  
y_data = y + np.random.normal(scale = 0.3, size = 100)  #   加上噪声

plt.figure('data')  # 指定图表的名字
plt.plot(x, y_data, '.')    # 加了参数'.'画散点图，每个散点形状为.

plt.figure('model')
plt.plot(x, y)  #   plot函数默认画连线图

plt.figure('data & model')
plt.plot(x,y,'k',lw=3) 
plt.scatter(x,y_data)
plt.show()
