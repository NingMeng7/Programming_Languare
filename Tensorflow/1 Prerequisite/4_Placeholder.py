import tensorflow as tf
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# create a placeholder for a vector of 3 elements, type tf.float32
a = tf.placeholder(tf.float32, shape=[3])
b = tf.constant([5, 5, 5], tf.float32)

# use the placeholder as you would a constant or a variable
c = a + b  # short for tf.add(a, b)

#with tf.Session() as sess:
#    print(sess.run(c)) 			# >> InvalidArgumentError: a doesn’t an actual value

# Example 1: feed_dict with placeholder
with tf.Session() as sess:
    print(sess.run(c, feed_dict={a: [1, 2, 3]})) 	# the tensor a is the key, not the string ‘a’
# >> [6, 7, 8]
# shape=None means that tensor of any shape will be accepted as value for placeholder.
# shape=None is easy to construct graphs, but nightmarish for debugging
# shape=None also breaks all following shape inference, which makes many ops not work because they expect certain rank.
