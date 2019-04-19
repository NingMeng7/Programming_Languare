import tensorflow as tf
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# The parameter name can be visualized in the tensorboard
a = tf.constant(2, name='a')
b = tf.constant(3, name='b')
x = tf.add(a, b, name='add')

writer = tf.summary.FileWriter('./graphs', tf.get_default_graph())
with tf.Session() as sess:
    # writer = tf.summary.FileWriter('./graphs', sess.graph)
    print("Addition with constant: %i" % sess.run(x))
    print("Addition with constant: %i" % sess.run(a + b))
writer.close()

# python3 ... // execute your program
# tensorboard --logdir="./graphs" --port 6006
# http://localhost:6006/

# In pycharm, input the second comand in the terminal and then execute the code