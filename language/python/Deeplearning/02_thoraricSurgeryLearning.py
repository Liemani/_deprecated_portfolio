import tensorflow as tf
import numpy as np


def thoraric_surgery_learning():
    from tensorflow.keras.models import Sequential
    from tensorflow.keras.layers import Dense

    np.random.seed(3)
    tf.compat.v1.set_random_seed(3)

    data_set = np.loadtxt("dataset/ThoraricSurgery.csv", delimiter=",")

    x = data_set[:, 0:17]
    y = data_set[:, 17]

    model = Sequential()
    model.add(Dense(30, input_dim=17, activation='relu'))
    model.add(Dense(1, activation='sigmoid'))

    model.compile(loss="binary_crossentropy", optimizer="adam", metrics=["accuracy"])
    model.fit(x, y, epochs=100, batch_size=10)


if __name__ == "__main__":
    thoraric_surgery_learning()
