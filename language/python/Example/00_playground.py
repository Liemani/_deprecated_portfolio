def test00():
    a = input().split()
    del a[-5:]
    print(a)


def test01():
    student_list = ["e hwang", "e e", "1 hyo"]
    print("Current student", student_list)

    new_student = input("Enter the name of new student: ")
    student_list.append(new_student)

    print("sorting")
    student_list.sort()

    for i in range(0, len(student_list)):
        print(i + 1, student_list[i])


def test02():
    weight = int(input("How weight your luggage?"))

    if weight >= 20:
        print("You have to pay 20 dollars.")
    else:
        print("There is no additional pay.")

    print("Thank you.")


def test03():
    score = int(input("Enter your score: "))

    if score >= 140:
        print("You can graduate!")
    else:
        print("You are hard to graduate!")


def test04():
    months = int(input("How long have your baby born? "))

    if 0 <= months <= 1:
        print("Should be vaccinated against tuberculosis.")

    if 0 <= months <= 2:
        print("Should be vaccinated against Hepatitis B.")

    if 2 <= months <= 6:
        print("Should be vaccinated against tetanus.")

    if 2 <= months <= 15:
        print("Should be vaccinated against Pneumococcus.")


def test05():
    string = input("Enter string: ")

    length = len(string)
    if length % 2 == 0:
        print(string[length // 2 - 1], string[length // 2], sep="")
    else:
        print(string[length // 2])


def test06():
    korean = int(input("Korean score"))
    english = int(input("English score"))
    history = int(input("History score"))
    select1 = int(input("Select1 score"))
    select2 = int(input("Select2 score"))

    if korean < 40 or \
            english < 40 or \
            history < 40 or \
            english < 40 or \
            select1 < 40 or \
            select2 < 40:
        print("F")
    else:
        print("P")


def test08():
    quality = input("Enter the quality of apple: ")
    price = int(input("Enter the price of an apple: "))

    if quality == "fresh":
        if price < 1000:
            print("Buy 10 apple")
        else:
            print("Buy 5 apple")
    else:
        print("Don't buy apple.")


def test09():
    total = 0

    for number in range(1, 101):
        if number % 3 == 0:
            total += number

    print(total)


def test10():
    number = int(input("Enter number: "))

    total = 0
    while number != 0:
        number, digit = divmod(number, 10)
        total += digit

    print("total: ", total)


def test11():
    number = input("Enter number: ")

    total = 0
    for digit in number:
        total += int(digit)

    print("total: ", total)


def test12():
    print("If you want to exit, enter negative number")

    total = 0
    count = 0
    score = int(input("Enter score: "))
    while score >= 0:
        total += score
        count += 1
        score = int(input("Enter score: "))

    print("Average:", total / count)


def test13():
    sentence = "I love you"

    reversed_sentence = ""
    for char in sentence:
        reversed_sentence = char + reversed_sentence

    print(reversed_sentence)


def test14():
    number_string = "0123456789"
    int_list = map(lambda x: int(x + x), number_string)
    print(list(int_list))


def set_test():
    superset = {"a", "b", "c", "d", "e"}
    subset = {"b", "c", "d"}

    if subset <= superset:
        del subset


def test15():
    thing = input("operate: ")
    number = round(abs(eval(thing)))

    if chr(number).isalpha():
        print(chr(number))
    else:
        print(number)


def simul(list_to_print):
    string_list = list(map(str, list_to_print))

    print("is all data true:", all(list_to_print))
    print("length:", len(list_to_print))
    print("max value:", max(string_list))
    print("ascending order:", sorted(string_list))
    print("data number:", list(enumerate(list_to_print)))


def test16():
    simul([1, 3, 5, "A", "b"])


def distance(x=0, y=0):
    from math import sqrt

    if x == 0 and y == 0:
        x = input("x-axis: ")
        y = input("y-axis: ")

    x = int(x)
    y = int(y)

    dist = sqrt(x**2 + y**2)

    print(dist)


def test17():
    distance(3, 4)
    distance()


def test18():
    import urllib.request
    response = urllib.request.urlopen("http://theteamlab.io")
    print(response.read())


def test19():
    import webbrowser
    webbrowser.open("http://computing.or.kr")


def test20():
    from urllib.request import urlopen
    from bs4 import BeautifulSoup

    python_url = urlopen("http://python.org")
    soup = BeautifulSoup(python_url.read(), "html.parser")
    print(soup.h1)
    print()
    print(soup)


def test21():
    import urllib.request

    url = "http://storage.googleapis.com/patents/grant_full_text/2014/ipg140107.zip"

    print("Start Download")
    fname, header = urllib.request.urlretrieve(url, 'ipg140107.zip')

    print("End download")


def test22():
    from bs4 import BeautifulSoup

    with open("example.html") as file:
        soup = BeautifulSoup(file, "html.parser")

    target = soup.find("div")
    print(target)


def test23():
    from bs4 import BeautifulSoup

    with open("example.html") as page:
        soup = BeautifulSoup(page, "html.parser")

    target = soup.find_all("div")
    print(target)


def test24():
    from bs4 import BeautifulSoup

    with open("example.html") as page:
        soup = BeautifulSoup(page, "html.parser")

    target = soup.find_all("div", {"id": "ABC_id"})
    print(target)


def test25():
    from urllib.request import urlopen
    from bs4 import BeautifulSoup

    naver_url = urlopen("https://movie.naver.com/movie/sdb/rank/rmovie.nhn")
    soup = BeautifulSoup(naver_url.read(), "html.parser")
    print(soup.title)


def test26():
    from urllib.request import urlopen
    from bs4 import BeautifulSoup

    naver_url = urlopen("https://movie.naver.com/movie/sdb/rank/rmovie.nhn")
    soup = BeautifulSoup(naver_url.read(), "html.parser")
    movie_list = soup.find_all("div", "tit3")
    print(movie_list)

    for movie in movie_list:
        print(movie.find("a").text)

    for i, movie in enumerate(movie_list):
        print("[%d] %s" % (i, movie.find("a").text))


def test27():
    from bs4 import BeautifulSoup as bs
    from urllib.request import urlopen
    from urllib.parse import quote_plus
    baseUrl = "https://search.naver.com/search.naver?where=image&sm=tab_jum&query="
    plusUrl = input("Input search: ")
    crawl_num = int(input("Input crawl_num(max: 50): "))

    url = baseUrl + quote_plus(plusUrl)
    html = urlopen(url)
    soup = bs(html, "html.parser")
    img = soup.find_all(class_="_img")

    n = 1
    for i in img:
        print(n)
        imgUrl = i["data-source"]
        with urlopen(imgUrl) as f:
            with open("images/img" + str(n)+".jpg", "wb") as h:
                img = f.read()
                h.write(img)
            n += 1
            if n > crawl_num:
                break

        print("Image Crawling is done.")


def test28():
    import numpy as np

    np_array = np.array([(1, 2, 3), (4, 5, 6), (7, 8, 9)], dtype=float)
    print(np_array)

    a = np.full((2, 3), 99, dtype=float)
    b = np.ones_like(a)
    print(b)


def test29():
    import numpy as np

    a = np.arange(0, 10, 5)
    b = np.linspace(0, 10, 5)
    print(a, b)


def test30():
    import numpy as np

    a = np.random.normal(15, 1, (2, 4))
    print(a)


def test31():
    import matplotlib.pyplot as plt

    sqr = [i ** 2 for i in range(14)]
    my_number = [i * 10 for i in range(14)]

    plt.plot(sqr, linewidth=10)
    plt.plot(my_number, linewidth=5)

    plt.title("0 to 13 Square Numbers")
    plt.xlabel("This is x label")
    plt.ylabel("This is y label")

    plt.legend(["SQR", "My Number"])

    plt.show()


def test32():
    import matplotlib.pyplot as plot

    x_data = range(1, 11)
    y_data = range(10, 0, -1)

    colormap = x_data
    plot.scatter(x_data, y_data, s=50, c=colormap)
    plot.title("Scatter makes scatter graph")
    plot.xlabel("This is x label")
    plot.ylabel("This is y label")
    plot.colorbar()

    plot.show()


def test33():
    import matplotlib.pyplot as plot

    x_data = range(6)
    y_data = [100, 120, 130, 140, 80, 150]

    plot.bar(x_data, y_data, width=0.5, color="red")

    plot.show()


def test34():
    import matplotlib.pyplot as plot
    import numpy as np

    x_data = range(1, 5)
    a = np.array([10, 15, 20, 25])
    b = np.array([50, 55, 60, 65])
    c = np.array([100, 105, 110, 115])

    plot.bar(x_data, a, color="pink")
    plot.bar(x_data, b, color="green", bottom=a)
    plot.bar(x_data, c, color="r", bottom=a+b)

    plot.show()


def test35():
    import matplotlib.pyplot as plot

    ratio = [25, 25, 25, 25]

    plot.pie(ratio)

    plot.show()


def test36():
    import matplotlib.pyplot as plot
    import numpy as np

    a = np.random.randn(100000)
    plot.hist(a, bins=30)

    plot.show()


def tst37():
    import matplotlib.pyplot as plot
    import numpy as np

    a = np.random.normal(10, 3, 5000)
    plot.hist(a, bins=30, color="pink")

    plot.show()


if __name__ == "__main__":
    tst37()
