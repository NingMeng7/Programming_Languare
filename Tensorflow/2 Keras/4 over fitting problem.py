import tensorflow as tf
import numpy as np
import pandas as pd
from tensorflow import keras
import matplotlib.pyplot as plt
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# ------------------------------------Data Load-------------------------------------------------------------------------
'''
1. 这里采用将每个评论转化为一个字典长度的向量, 如果这个词有出现就为1，没有出现为0
2. 字词索引按照频率排序, 因此较小的索引具有更大的出现概率
'''
NUM_WORDS = 10000

(train_data, train_labels), (test_data, test_labels) = keras.datasets.imdb.load_data(num_words=NUM_WORDS)


def multi_hot_sequences(sequences, dimension):
    # Create an all-zero matrix of shape (len(sequences), dimension)
    results = np.zeros((len(sequences), dimension))
    for i, word_indices in enumerate(sequences):
        results[i, word_indices] = 1.0  # set specific indices of results[i] to 1s
    return results


train_data = multi_hot_sequences(train_data, dimension=NUM_WORDS)
test_data = multi_hot_sequences(test_data, dimension=NUM_WORDS)

plt.plot(train_data[0])
plt.show()

# ------------------------------------Baseline model -------------------------------------------------------------------
'''
1. 我们将创建三个版本的模型, 考察欠拟合,过拟合以及基准模型的情况
2. 大量的参数意味着良好的拟合能力，但是真正重要的事实上是泛化能力
3. 模型的大小(结构,参数)需要不断尝试+经验来设置
'''

baseline_model = keras.Sequential([
    keras.layers.Dense(16, activation=tf.nn.relu, input_shape=(NUM_WORDS,)),
    keras.layers.Dense(16, activation=tf.nn.relu),
    keras.layers.Dense(1, activation=tf.nn.sigmoid)
])

baseline_model.compile(optimizer='adam',
                       loss='binary_crossentropy',
                       metrics=['accuracy', 'binary_crossentropy'])

baseline_model.summary()

baseline_history = baseline_model.fit(train_data,
                                      train_labels,
                                      epochs=20,
                                      batch_size=512,
                                      validation_data=(test_data, test_labels),
                                      verbose=2)

# ------------------------------------Simple Model----------------------------------------------------------------------
smaller_model = keras.Sequential([
    keras.layers.Dense(4, activation=tf.nn.relu, input_shape=(NUM_WORDS,)),
    keras.layers.Dense(4, activation=tf.nn.relu),
    keras.layers.Dense(1, activation=tf.nn.sigmoid)
])

smaller_model.compile(optimizer='adam',
                      loss='binary_crossentropy',
                      metrics=['accuracy', 'binary_crossentropy'])

smaller_model.summary()

smaller_history = smaller_model.fit(train_data,
                                    train_labels,
                                    epochs=20,
                                    batch_size=512,
                                    validation_data=(test_data, test_labels),
                                    verbose=2)

# -------------------------------------Large Model----------------------------------------------------------------------

bigger_model = keras.models.Sequential([
    keras.layers.Dense(512, activation=tf.nn.relu, input_shape=(NUM_WORDS,)),
    keras.layers.Dense(512, activation=tf.nn.relu),
    keras.layers.Dense(1, activation=tf.nn.sigmoid)
])

bigger_model.compile(optimizer='adam',
                     loss='binary_crossentropy',
                     metrics=['accuracy','binary_crossentropy'])

bigger_model.summary()

bigger_history = bigger_model.fit(train_data, train_labels,
                                  epochs=20,
                                  batch_size=512,
                                  validation_data=(test_data, test_labels),
                                  verbose=2)

# -------------------------------------Plot History---------------------------------------------------------------------


def plot_history(histories, key='binary_crossentropy'):
    plt.figure(figsize=(16, 10))

    for name, history in histories:
        val = plt.plot(history.epoch, history.history['val_'+key],
                       '--', label=name.title()+'Val')
        plt.plot(history.epoch, history.history[key], color=val[0].get_color(),
                 label=name.title()+'Train')

        plt.xlabel('Epochs')
        plt.ylabel(key.replace('-', ' ').title())
        plt.legend()

        plt.xlim([0, max(history.epoch)])
    plt.show()

plot_history([('baseline', baseline_history),
              ('smaller', smaller_history),
              ('bigger', bigger_history)])

# -------------------------------------L2-Regularization Model----------------------------------------------------------
'''
1. L2 正则化，其中所添加的代价与权重系数值的平方（即所谓的权重“L2 范数”）成正比
2. Input 层的 loss函数将会添加一项权重为0.001的L2范数惩罚项, 其只在训练的时候添加，因此训练loss将会大大增大
'''
l2_model = keras.models.Sequential([
    keras.layers.Dense(16, kernel_regularizer=keras.regularizers.l2(0.001),
                       activation=tf.nn.relu, input_shape=(NUM_WORDS,)),
    keras.layers.Dense(16, kernel_regularizer=keras.regularizers.l2(0.001),
                       activation=tf.nn.relu),
    keras.layers.Dense(1, activation=tf.nn.sigmoid)
])

l2_model.compile(optimizer='adam',
                 loss='binary_crossentropy',
                 metrics=['accuracy', 'binary_crossentropy'])

l2_model_history = l2_model.fit(train_data, train_labels,
                                epochs=20,
                                batch_size=512,
                                validation_data=(test_data, test_labels),
                                verbose=2)

# --------------------------------------Drop-out Model------------------------------------------------------------------
'''
1. 丢弃指的是将其值设置为0
2. Drop-out for a layer: 在训练期间随机丢弃某个层的多个输出特征
3. e.g. Output-vector [0.2, 0.5, 1.3, 0.8, 1.1] to [0, 0.5, 1.3, 0, 1.1]
4. 丢弃率值得是变为0的特征占据的比例，通常设置在0.2到0.5之间
5. 测试的时候, 网络不丢弃任何单元，但将层的输出值按照等同于丢弃率的比例缩减
'''
'''
def dropout(x, drop_rate):
    :param x: Original output vector
    :param drop_rate: drop-out rate
    :return: drop-out output vector
    keep_rate = 1 - drop_rate
    assert 0 <= keep_rate <= 1
    if keep_rate == 0:
        return x.zeros_like()
    mask = np.random.uniform(0, 1.0, x.shape, ctx=x.context) < keep_rate
    scale = 1 / keep_rate  # Make sure that E[drop-out x] = X
    return mask * x * scale
'''

dpt_model = keras.models.Sequential([
    keras.layers.Dense(16, activation=tf.nn.relu, input_shape=(NUM_WORDS,)),
    keras.layers.Dropout(0.5),
    keras.layers.Dense(16, activation=tf.nn.relu),
    keras.layers.Dropout(0.5),
    keras.layers.Dense(1, activation=tf.nn.sigmoid)
])


dpt_model.compile(optimizer='adam',
                  loss='binary_crossentropy',
                  metrics=['accuracy','binary_crossentropy'])

dpt_model_history = dpt_model.fit(train_data, train_labels,
                                  epochs=20,
                                  batch_size=512,
                                  validation_data=(test_data, test_labels),
                                  verbose=2)

plot_history([('baseline', baseline_history),
              ('dropout', dpt_model_history)])
