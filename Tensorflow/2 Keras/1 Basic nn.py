import tensorflow as tf
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# --------------------------------Load Data----------------------------------------------------------------------------
fashion_mnist = keras.datasets.fashion_mnist
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']   # Label names

'''
plt.figure()
plt.imshow(train_images[0])
plt.colorbar()
plt.grid(False)
plt.show()
'''
# Data pre-processing
train_images = train_images / 255.0
test_images = test_images / 255.0
'''
plt.figure(figsize=(10,10))
for i in range(25):
    plt.subplot(5,5,i+1)
    plt.xticks([])
    plt.yticks([])
    plt.grid(False)
    plt.imshow(train_images[i], cmap=plt.cm.binary)
    plt.xlabel(class_names[train_labels[i]])
plt.show()
'''
# --------------------------------Model setting-------------------------------------------------------------------------
'''
1. Input:  第一层是数据格式变换层, 28x28 到 1*784
2. Hidden: 第二、三层是全连接层，全连接层的每一个输出都可以看成前一层的
		每一个结点乘以一个权重系数W，最后加上一个偏置值b得到
3. Output: 最后一层是10个结点的 softmax 层
'''
model = keras.Sequential([
    keras.layers.Flatten(input_shape=(28, 28)),
    keras.layers.Dense(256, activation=tf.nn.relu),
    keras.layers.Dense(128, activation=tf.nn.relu),
    keras.layers.Dense(10, activation=tf.nn.softmax)
])

model.compile(optimizer=tf.train.AdamOptimizer(),
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# --------------------------------Model training------------------------------------------------------------------------
'''
1. 将training set 送到模型: train_images and train_labels
2. 训练
3. 在 test_images and test_labels 上测试
'''

model.fit(train_images, train_labels, epochs=10)
test_loss, test_acc = model.evaluate(test_images, test_labels)

print('Test accuracy:', test_acc)