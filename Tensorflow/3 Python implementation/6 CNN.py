import numpy as np
import sys
import matplotlib.pyplot as plt
from tensorflow import keras

# -----------------------------------Data Loading & transformation------------------------------------------------------
N = 100
M = 100
fashion_mnist = keras.datasets.fashion_mnist
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()
images, labels = (train_images[0:N].reshape(N, 28 * 28) / 255, train_labels[0:N])

one_hot_labels = np.zeros((len(labels), 10))
for i, j in enumerate(labels):
    one_hot_labels[i][j] = 1
labels = one_hot_labels

test_images = test_images[0:M].reshape(M, 28 * 28) / 255
test_labels_temp = np.zeros((len(labels), 10))
for i, j in enumerate(test_labels[0:M]):
    test_labels_temp[i][j] = 1
test_labels = test_labels_temp

# -------------------------------------Parameter setting----------------------------------------------------------------
np.random.seed(1)
relu = lambda x: (x >= 0) * x
relu2deriv = lambda x: x >= 0
tanh = lambda x: np.tanh(x)
tanh2deriv = lambda x: 1 - (x ** 2)
softmax = lambda x: np.exp(x) / np.sum(np.exp(x), axis=1, keepdims=True)


def get_image_section(layer, row_from, row_to, col_from, col_to):
    section = layer[:, row_from:row_to, col_from:col_to]
    # temp =  section.reshape(-1, 1, row_to-row_from, col_to - col_from)   # -1: calculate from the context, 1:length
    # print(temp.shape)
    # return temp
    return section.reshape(-1, 1, row_to-row_from, col_to - col_from)   # -1: calculate from the context, 1:length


alpha, iterations, hidden_size, pixels_per_image, num_labels = (1, 1000, 100, 784, 10)   # 在一开始alpha==0.005, 准确率一直降低
batch_size = 100
input_rows = 28
input_cols = 28
kernel_rows = 3
kernel_cols = 3
num_kernels = 16

hidden_size = ((input_rows - kernel_rows + 1) * (input_cols - kernel_cols + 1)) * num_kernels
kernels = 0.02 * np.random.random((kernel_rows * kernel_cols, num_kernels)) - 0.01
weights_1_2 = 0.2 * np.random.random((hidden_size, num_labels)) - 0.1
# -------------------------------------Relu activation function---------------------------------------------------------

for j in range(iterations):
    correct_cnt = 0
    for i in range(int(len(images) / batch_size)):
        batch_start, batch_end = ((i * batch_size), ((i + 1) * batch_size))
        layer_0 = images[batch_start:batch_end]
        layer_0 = layer_0.reshape(layer_0.shape[0], 28, 28)
        layer_0.shape

        sects = list()
        for row_start in range(layer_0.shape[1] - kernel_rows + 1):
            for col_start in range(layer_0.shape[2] - kernel_cols + 1):
                sect = get_image_section(layer_0,
                                         row_start,
                                         row_start+kernel_rows,
                                         col_start,
                                         col_start+kernel_cols)
                sects.append(sect)

        # print(len(sects))
        expanded_input = np.concatenate(sects, axis=1)
        es = expanded_input.shape   # (100, 625, 3, 3)
        # print(es)
        flattened_input = expanded_input.reshape(es[0] * es[1], -1)
        # print(flattened_input.shape)    # 67600, 9(26 * 26 * 100 x 9)
        kernel_output = flattened_input.dot(kernels)
        layer_1 = tanh(kernel_output.reshape(es[0], -1))
        dropout_mask = np.random.randint(2, size=layer_1.shape)
        layer_1 *= dropout_mask * 2
        layer_2 = softmax(np.dot(layer_1, weights_1_2))

        for k in range(batch_size):
            labelset = labels[batch_start + k:batch_start + k + 1]
            _inc = int(np.argmax(layer_2[k:k + 1]) ==
                       np.argmax(labelset))
            correct_cnt += _inc

        layer_2_delta = (labels[batch_start:batch_end] - layer_2) \
                        / (batch_size * layer_2.shape[0])
        layer_1_delta = layer_2_delta.dot(weights_1_2.T) * \
                        tanh2deriv(layer_1)
        layer_1_delta *= dropout_mask
        weights_1_2 += alpha * layer_1.T.dot(layer_2_delta)
        l1d_reshape = layer_1_delta.reshape(kernel_output.shape)
        k_update = flattened_input.T.dot(l1d_reshape)
        kernels -= alpha * k_update

    test_correct_cnt = 0

    for i in range(len(test_images)):

        layer_0 = test_images[i:i + 1]
        #         layer_1 = tanh(np.dot(layer_0,weights_0_1))
        layer_0 = layer_0.reshape(layer_0.shape[0], 28, 28)
        layer_0.shape

        sects = list()
        for row_start in range(layer_0.shape[1] - kernel_rows + 1):
            for col_start in range(layer_0.shape[2] - kernel_cols + 1):
                sect = get_image_section(layer_0,
                                         row_start,
                                         row_start + kernel_rows,
                                         col_start,
                                         col_start + kernel_cols)
                sects.append(sect)

        expanded_input = np.concatenate(sects, axis=1)
        es = expanded_input.shape
        flattened_input = expanded_input.reshape(es[0] * es[1], -1)

        kernel_output = flattened_input.dot(kernels)
        layer_1 = tanh(kernel_output.reshape(es[0], -1))
        layer_2 = np.dot(layer_1, weights_1_2)

        test_correct_cnt += int(np.argmax(layer_2) ==
                                np.argmax(test_labels[i:i + 1]))


    if (j % 1 == 0):
        sys.stdout.write("\n" + \
                         "I:" + str(j) + \
                         " Test-Acc:" + str(test_correct_cnt / float(len(test_images))) + \
                         " Train-Acc:" + str(correct_cnt / float(len(images))))


