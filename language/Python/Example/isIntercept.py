def run():
    point_list = []
    for _ in range(4):
        point_list.append(tuple(map(int, input("Enter x, y: ").split())))

    if (point_list[0][0] < point_list[2][0] < point_list[1][0] or \
            point_list[0][0] < point_list[3][0] < point_list[1][0]) and \
            (point_list[0][1] < point_list[2][1] < point_list[1][1] or \
             point_list[0][1] < point_list[3][1] < point_list[1][1]):
        print("Intersect")
    else:
        print("Not intersect")