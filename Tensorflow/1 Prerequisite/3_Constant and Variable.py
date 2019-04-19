import tensorflow as tf
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# constant is an op
a = tf.constant([2, 2], name='a')
b = tf.constant([[0, 1], [2, 3]], name='b')
with tf.Session() as sess:
    print(sess.run(tf.div(b, a)))
    print(sess.run(tf.divide(b, a)))
    print(sess.run(tf.truediv(b, a)))
    print(sess.run(tf.floordiv(b, a)))
    print(sess.run(tf.truncatediv(b, a)))
    print(sess.run(tf.floor_div(b, a)))

# variable: variable is a class with many ops!
s = tf.Variable(2, name='scalar')
m = tf.get_variable("matrix", initializer=tf.constant([[0, 1], [2, 3]]))
w = tf.Variable(tf.zeros([784,10])) # initialized a variable with another var instance

# var must be initialized before using
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

# Initialize only a subset of variables:
with tf.Session() as sess:
    sess.run(tf.variables_initializer([s, m]))

# Initialize a single variable
W = tf.Variable(10)
op_assign = W.assign((8))
with tf.Session() as sess:
    sess.run(W.initializer)
    print(W)
    print(W.eval())
    for i in range(5):
        sess.run(op_assign) # assign is an op! must be run to take effect
    print(W.eval())
