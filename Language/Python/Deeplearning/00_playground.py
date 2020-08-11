import tensorflow as tf
import keras as k
import numpy as np

# print("tensorflow version =", tf.__version__)
# print("keras version =", k.__version__)


def test00():
    import pandas as pd
    import matplotlib.pyplot as plt
    import seaborn as sns

    df = pd.read_csv("pima-indians-diabetes.csv", names=["pregnant", "plasma", "pressure", "thickness", "insulin", "BMI", "pedigree", "age", "class"])

    print(df.head(5))

    print(df.info())

    print(df.describe())

    print(df[["plasma", "class"]])

    colormap = plt.cm.gist_heat
    plt.figure(figsize=(12, 12))

    sns.heatmap(df.corr(), linewidths=0.1, vmax=0.5, cmap=colormap, linecolor="white", annot=True)
    plt.show()

    grid = sns.FacetGrid(df, col="class")
    grid.map(plt.hist, "plasma", bins=10)
    plt.show()

    from tensorflow.keras.models import Sequential
    from tensorflow.keras.layers import Dense

    import numpy
    import tensorflow as tf

    numpy.random.seed(3)
    tf.random.set_seed(3)

    dataset = numpy.loadtxt("pima-indians-diabetes.csv", delimiter=",")
    x = dataset[:, 0:8]
    y = dataset[:, 8]

    model = Sequential()
    model.add(Dense(12, input_dim=8, activation="relu"))
    model.add(Dense(8, activation="relu"))
    model.add(Dense(1, activation="sigmoid"))

    model.compile(loss="binary_crossentropy",
                  optimizer="adam",
                  metrics=["accuracy"])

    model.fit(x, y, epochs=200, batch_size=10)

    print("\n Accuracy: %.4f" % (model.evaluate(x, y)[1]))


if __name__ == "__main__":
    test00()
