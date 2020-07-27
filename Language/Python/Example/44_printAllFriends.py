def get_friend(friend_dictionary, target):
    target_friend_list = [target]

    count = 0
    while True:
        if count >= len(target_friend_list):
            break

        for friend in friend_dictionary[target_friend_list[count]]:
            if friend not in target_friend_list:
                target_friend_list.append(friend)

        count += 1

    print(target_friend_list)


def get_friend2(friend_dictionary, target):
    target_friend_list = [target]

    # print([target_friend_list.append(friend_friend) for friend in target_friend_list for friend_friend in friend_dictionary[friend] if friend_friend not in target_friend_list])

    for friend in target_friend_list:
        for friend_friend in friend_dictionary[friend]:
            if friend_friend not in target_friend_list:
                target_friend_list.append(friend_friend)

    print(target_friend_list)


def test23():
    friend_dict = {"Summer": ["John", "Justin", "Mike"],
                   "John": ["Summer", "Justin"],
                   "Justin": ["Summer", "John", "Mike", "May"],
                   "Mike": ["Summer", "Justin"],
                   "May": ["Justin", "Kim"],
                   "Kim": ["May"],
                   "Tom": ["Jerry"],
                   "Jerry": ["Tom"]}
    get_friend2(friend_dict, "Summer")
