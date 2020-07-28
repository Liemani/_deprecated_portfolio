import tensorflow as tf
import numpy as np


def placeholder():
    x_data = np.random.randn(5, 10)
    w_data = np.random.randn(10, 1)

    with tf.Graph().as_default():
        x = tf.compat.v1.placeholder(tf.float32, shape=(5, 10))
        w = tf.compat.v1.placeholder(tf.float32, shape=(10, 1))
        b = tf.fill((5, 1), -1.)
        print(b)
        xw = tf.matmul(x, w)

        xwb = xw + b
        s = tf.reduce_max(xwb)
        with tf.compat.v1.Session() as sess:
            outs = sess.run(s, feed_dict={x: x_data, w: w_data})

        print("outs = {}".format(outs))
