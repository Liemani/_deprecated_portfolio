def run():
    point_list = []
    for _ in range(2):
        point_list.append(tuple(map(int, input("Enter x, y: ").split())))

    if point_list[0][0] == point_list[1][0]:
        print("Infinite")
    else:
        inclination = (point_list[0][1] - point_list[1][1]) / (point_list[0][0] - point_list[1][0])

    y_intercept = (point_list[0][0] * point_list[1][1] - point_list[1][0] * point_list[0][1]) / (point_list[0][0] - point_list[1][0])

    print("inclination: %d, y-intercept: %d" % (inclination, y_intercept))