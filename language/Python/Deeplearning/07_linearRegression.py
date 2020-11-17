def linear_regression():
    import matplotlib.pyplot as plt

    data = [[2, 81], [4, 93], [6, 91], [8, 97]]

    x = [x for x, _ in data]
    y = [y for _, y in data]

    plt.figure(figsize=(8, 5))
    plt.scatter(x, y)
    plt.show()

    x_data = np.array(x)
    y_data = np.array(y)

    a = 0
    b = 0

    lr = 0.03

    epochs = 2001

    for i in range(epochs):
        y_hat = a * x_data + b
        error = y_data - y_hat
        a_diff = 2 * sum(error * x_data) / len(data)
        b_diff = 2 * sum(error) / len(data)

        a = a + lr * a_diff
        b = b + lr * b_diff

        if i % 100 == 0:
            print("epoch=%.f, 기울기=%.04f, 절편=%.04f" % (i, a, b))

    y_pred = a * x_data + b
    plt.scatter(x, y)
    plt.plot([min(x_data), max(x_data)], [min(y_pred), max(y_pred)])
    plt.show()
