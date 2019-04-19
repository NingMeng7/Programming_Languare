import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
import tensorflow as tf

a = tf.add(3, 5)
print(a)	# A tensor instead of 8

with tf.Session() as sess:
    print(sess.run(a))	# We get the value of a in the session!

# More complicated graph	
x = 2
y = 3
op1 = tf.add(x, y)
op2 = tf.multiply(x, y)
op3 = tf.pow(op2, op1)
with tf.Session() as sess:
    op3_output = sess.run(op3)	# To get the value of op3, sess compute all the nodes that leads to op3
    print(op3_output)
    # Note that do not let op3 = sess.run(op3)

# More than one graph
g1 = tf.get_default_graph()	# To handle the default graph
g2 = tf.Graph()
# add ops to the default graph
with g1.as_default():
	a = tf.Constant(3)
# add ops to the user created graph
with g2.as_default():
	b = tf.Constant(5)

with tf.Session(graph=g1) as sess1:
    print(sess1.run(a))

with tf.Session(graph=g2) as sess2:
    print(sess2.run(b))