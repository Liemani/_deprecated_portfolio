def prepare3():
    from collections import namedtuple

    argument_label_list = ["name", "cost", "stock_count"]

    Target = namedtuple("Target", argument_label_list)

    stuff_list = [Target("mix", 6000, 2),
                  Target("paper cup", 15000, 3),
                  Target("coffee stick", 3000, 1)]

    total_cost = 0
    print("Stuff list to need")
    for stuff in stuff_list:
        if stuff.stock_count >= 3:
            continue

        need_count = 3 - stuff.stock_count
        cost = need_count * stuff.cost
        total_cost += cost
        print("{} [count: {}, cost: {}]".format(stuff.name, need_count, cost))

    print("total cost: {}".format(total_cost))


if __name__ == "__main__":
    prepare3()
