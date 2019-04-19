import tensorflow as tf
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# --------------------------------Load Data----------------------------------------------------------------------------
imdb = keras.datasets.imdb
(train_data, train_labels), (test_data, test_labels) = imdb.load_data(num_words=10000)  # 只保留词频前10000的词


def decode_review(text):
    return ' '.join([reverse_word_index.get(i, '?') for i in text])


word_index = imdb.get_word_index()
word_index = {k: (v+3) for k, v in word_index.items()}
word_index["<PAD>"] = 0
word_index["<START>"] = 1
word_index["<UNK>"] = 2  # unknown
word_index["<UNUSED>"] = 3

reverse_word_index = dict([(value, key) for (key, value) in word_index.items()])
# print(decode_review(train_data[0]))

# 让feature vector 的长度标准化(即让所有vector等长), 这样Data set 将会变成 25000 x max_length 维的一个矩阵
# 在朴素贝叶斯分类器里, 我们曾经把每个邮件转换为字典大小维度的一个向量，这会占据大量的内存
train_data = keras.preprocessing.sequence.pad_sequences(train_data,
                                                        value=word_index['<PAD>'],
                                                        padding='post',
                                                        maxlen=256)
test_data = keras.preprocessing.sequence.pad_sequences(test_data,
                                                       value=word_index['<PAD>'],
                                                       padding='post',
                                                       maxlen=256)
# print(train_data.shape)
# print(train_data[0])


# --------------------------------Model Setting-------------------------------------------------------------------------

vocab_size = 10000
model = keras.Sequential()
model.add(keras.layers.Embedding(vocab_size, 16))  # Input
model.add(keras.layers.GlobalAveragePooling1D())  # 池化层
model.add(keras.layers.Dense(16, activation=tf.nn.relu))  # Hidden 全连接
model.add(keras.layers.Dense(1, activation=tf.nn.sigmoid))  # Output

# Loss function and optimizer
model.compile(optimizer=tf.train.AdamOptimizer(),
              loss='binary_crossentropy',
              metrics=['accuracy'])
model.summary()

# --------------------------------Model training------------------------------------------------------------------------
'''
注意这里只是对第一维索引，实际上是对样本的选取
我们用了15000(10000->end)个样本用来训练
剩下的10000个样本用来作为validation set
'''
partial_x_train = train_data[10000:]  # Training set 15000x256
partial_y_train = train_labels[10000:]  # 15000

x_val = train_data[:10000]  # Validation set 10000x256
y_val = train_labels[:10000]  # 10000

'''
print(type(train_data))
print(train_data.shape)
print(train_labels.shape)
print(x_val.shape)
print(partial_x_train.shape)
print(y_val.shape)
print(partial_y_train.shape)
'''
history = model.fit(partial_x_train,
          partial_y_train,
          epochs=40,
          batch_size=512,
          validation_data=(x_val, y_val),
          verbose=1)

results = model.evaluate(test_data, test_labels)
print(results)  # Loss and Accuracy

history_dict = history.history
history_dict.keys()
dict_keys = (['val_loss', 'acc', 'loss', 'val_acc'])
acc = history.history['acc']
val_acc = history.history['val_acc']
loss = history.history['loss']
val_loss = history.history['val_loss']

epochs = range(1, len(acc) + 1)

# "bo" is for "blue dot"
plt.plot(epochs, loss, 'bo', label='Training loss')
# b is for "solid blue line"
plt.plot(epochs, val_loss, 'b', label='Validation loss')
plt.title('Training and validation loss')
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.legend()

plt.show()

acc_values = history_dict['acc']
val_acc_values = history_dict['val_acc']

plt.plot(epochs, acc, 'bo', label='Training acc')
plt.plot(epochs, val_acc, 'b', label='Validation acc')
plt.title('Training and validation accuracy')
plt.xlabel('Epochs')
plt.ylabel('Accuracy')
plt.legend()
plt.show()
