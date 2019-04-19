import numpy as np
import sys
from tensorflow import keras

# -----------------------------------Data Loading & transformation------------------------------------------------------
N = 1000
fashion_mnist = keras.datasets.fashion_mnist
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()
images, labels = (train_images[0:N].reshape(N, 28 * 28) / 255, train_labels[0:N])
'''
one hot coding: 用10位二进制码来表示状态, 如果该状态为真,则为1,和贝叶斯里字典长度作为特征向量的方法一致
e.g. 
label = 9: 0000 0000 01
label = 3: 0001 0000 00
'''
one_hot_labels = np.zeros((len(labels), 10))
for i, j in enumerate(labels):
    one_hot_labels[i][j] = 1
labels = one_hot_labels

test_images = test_images[0:N].reshape(N, 28 * 28) / 255
test_labels_temp = np.zeros((len(labels), 10))
for i, j in enumerate(test_labels[0:N]):
    test_labels_temp[i][j] = 1
test_labels = test_labels_temp

# -------------------------------------Parameter setting----------------------------------------------------------------
np.random.seed(1)
relu = lambda x:(x >= 0) * x
relu2deriv = lambda x: x>=0
alpha, iterations, hidden_size, pixels_per_image, num_labels = (0.005, 350, 40, 784, 10)

weights_0_1 = 0.2 * np.random.random((pixels_per_image, hidden_size)) - 0.1
weights_1_2 = 0.2 * np.random.random((hidden_size, num_labels)) - 0.1

# -------------------------------------Model training-------------------------------------------------------------------
'''
for j in range(iterations):
    error, correct_cnt = (0.0, 0)

    for i in range(len(images)):
        layer_0 = images[i:i+1]
        layer_1 = relu(np.dot(layer_0, weights_0_1))
        layer_2 = np.dot(layer_1, weights_1_2)

        error += np.sum((labels[i:i+1] - layer_2) ** 2)
        correct_cnt += int(np.argmax(layer_2) == np.argmax(labels[i:i+1]))

        layer_2_delta = (labels[i:i+1] - layer_2)
        layer_1_delta = layer_2_delta.dot(weights_1_2.T) * relu2deriv(layer_1)

        weights_1_2 += alpha * layer_1.T.dot(layer_2_delta)
        weights_0_1 += alpha * layer_0.T.dot(layer_1_delta)

    sys.stdout.write("\r I:" + str(j) + \
                     " Train-Err:" + str(error / float(len(images)))[0:5] + \
                     " Train-Acc:" + str(correct_cnt / float(len(images))))

    if j % 10 == 0 or j == iterations - 1:
        error, correct_cnt = (0.0, 0)

        for i in range(len(test_images)):
            layer_0 = test_images[i:i + 1]
            layer_1 = relu(np.dot(layer_0, weights_0_1))
            layer_2 = np.dot(layer_1, weights_1_2)

            error += np.sum((test_labels[i:i + 1] - layer_2) ** 2)
            correct_cnt += int(np.argmax(layer_2) == \
                               np.argmax(test_labels[i:i + 1]))
        sys.stdout.write(" Test-Err:" + str(error / float(len(test_images)))[0:5] + \
                         " Test-Acc:" + str(correct_cnt / float(len(test_images))) + "\n")
        print()
'''

# ----------------------------------Drop-out training-------------------------------------------------------------------

'''
def dropout(x, drop_rate):

    keep_rate = 1 - drop_rate
    assert 0 <= keep_rate <= 1
    if keep_rate == 0:
        return x.zeros_like()
    mask = np.random.uniform(0, 1.0, x.shape) < keep_rate
    scale = 1 / keep_rate  # Make sure that E[drop-out x] = X
    return mask * x * scale


for j in range(iterations):
    error, correct_cnt = (0.0, 0)

    for i in range(len(images)):
        layer_0 = images[i:i+1]
        layer_1 = relu(np.dot(layer_0, weights_0_1))
        dropout_mask = np.random.randint(2, size=layer_1.shape)
        layer_1 *= dropout_mask * 2
        layer_2 = np.dot(layer_1, weights_1_2)

        error += np.sum((labels[i:i+1] - layer_2) ** 2)
        correct_cnt += int(np.argmax(layer_2) == np.argmax(labels[i:i+1]))

        layer_2_delta = (labels[i:i+1] - layer_2)
        layer_1_delta = layer_2_delta.dot(weights_1_2.T) * relu2deriv(layer_1)
        layer_1_delta *= dropout_mask

        weights_1_2 += alpha * layer_1.T.dot(layer_2_delta)
        weights_0_1 += alpha * layer_0.T.dot(layer_1_delta)

    sys.stdout.write("\r I:" + str(j) + \
                     " Train-Err:" + str(error / float(len(images)))[0:5] + \
                     " Train-Acc:" + str(correct_cnt / float(len(images))))

    if j % 10 == 0 or j == iterations - 1:
        error, correct_cnt = (0.0, 0)

        for i in range(len(test_images)):
            layer_0 = test_images[i:i + 1]
            layer_1 = relu(np.dot(layer_0, weights_0_1))
            layer_2 = np.dot(layer_1, weights_1_2)

            error += np.sum((test_labels[i:i + 1] - layer_2) ** 2)
            correct_cnt += int(np.argmax(layer_2) == \
                               np.argmax(test_labels[i:i + 1]))
        sys.stdout.write(" Test-Err:" + str(error / float(len(test_images)))[0:5] + \
                         " Test-Acc:" + str(correct_cnt / float(len(test_images))) + "\n")
        print()
'''
# ----------------------------------Batch Gradient Descent--------------------------------------------------------------
batch_size = 100
alpha, iterations = (0.001, 300)
pixels_per_image, num_labels, hidden_size = (784, 10, 100)

weights_0_1 = 0.2 * np.random.random((pixels_per_image, hidden_size)) - 0.1
weights_1_2 = 0.2 * np.random.random((hidden_size, num_labels)) - 0.1

for j in range(iterations):
    error, correct_cnt = (0.0, 0)
    for i in range(int(len(images) / batch_size)):
        batch_start, batch_end = ((i * batch_size), ((i + 1) * batch_size))

        layer_0 = images[batch_start:batch_end]
        layer_1 = relu(np.dot(layer_0, weights_0_1))
        layer_2 = np.dot(layer_1, weights_1_2)

        error += np.sum((labels[batch_start:batch_end] - layer_2) ** 2)
        for k in range(batch_size):
            correct_cnt += int(np.argmax(layer_2[k:k + 1]) == np.argmax(labels[batch_start + k:batch_start + k + 1]))

        layer_2_delta = (labels[batch_start:batch_end] - layer_2) / batch_size
        layer_1_delta = layer_2_delta.dot(weights_1_2.T) * relu2deriv(layer_1)

        weights_1_2 += alpha * layer_1.T.dot(layer_2_delta)
        weights_0_1 += alpha * layer_0.T.dot(layer_1_delta)

    if (j % 10 == 0):
        test_error = 0.0
        test_correct_cnt = 0

        for i in range(len(test_images)):
            layer_0 = test_images[i:i + 1]
            layer_1 = relu(np.dot(layer_0, weights_0_1))
            layer_2 = np.dot(layer_1, weights_1_2)

            test_error += np.sum((test_labels[i:i + 1] - layer_2) ** 2)
            test_correct_cnt += int(np.argmax(layer_2) == np.argmax(test_labels[i:i + 1]))

        sys.stdout.write("\n" + \
                         "I:" + str(j) + \
                         " Test-Err:" + str(test_error / float(len(test_images)))[0:5] + \
                         " Test-Acc:" + str(test_correct_cnt / float(len(test_images))) + \
                         " Train-Err:" + str(error / float(len(images)))[0:5] + \
                         " Train-Acc:" + str(correct_cnt / float(len(images))))