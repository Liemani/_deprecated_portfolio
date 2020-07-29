def multiple_linear_regression():
    data = [[2, 0, 81], [4, 4, 93], [6, 2, 91], [8, 3, 97]]

    x1, x2, y = [row for row in zip(*data)]

    import matplotlib.pyplot as plt
    from mpl_toolkits import mplot3d

    ax = plt.axes(projection="3d")
    ax.set_xlabel("study_hours")
    ax.set_ylabel("private_class")
    ax.set_zlabel("Score")
    ax.dist = 11
    ax.scatter(x1, x2, y)
    plt.show()

    x1_data = np.array(x1)
    x2_data = np.array(x2)
    y_data = np.array(y)

    a1 = 0
    a2 = 0
    b = 0

    lr = 0.015

    epochs = 2001

    for i in range(epochs):
        y_hat = a1 * x1_data + a2 * x2_data + b
        error = y_data - y_hat
        a1_diff = 2 * sum(error * x1_data) / len(data)
        a2_diff = 2 * sum(error * x2_data) / len(data)
        b_diff = 2 * sum(error) / len(data)

        a1 = a1 + lr * a1_diff
        a2 = a2 + lr * a2_diff
        b = b + lr * b_diff

        if i % 100 == 0:
            print("epoch=%.f, 기울기1=%.04f, 기울기2=%.04f, 절편=%.04f" % (i, a1, a2, b))
