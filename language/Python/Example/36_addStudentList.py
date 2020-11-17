class StudentInformation:
    @staticmethod
    def keys():
        return {"id_number",
                "name",
                "birth",
                "phone_number",
                "address"}

    def __init__(self, **kwargs):
        self.__dict__.update(kwargs)


def add_student():
    dictionary = {}
    student_information_list = []

    while True:
        for key in StudentInformation.keys():
            dictionary[key] = input("{} : ".format(key))

        student_information_list.append(StudentInformation(**dictionary))
        print(dictionary)


def add_student2():
    student_information_key_list = ["student_id", "name", "birth", "phone_number", "address"]
    dictionary = {}
    student_information_list = []

    count = 1
    while True:
        for key in student_information_key_list:
            dictionary[key] = input("{}: ".format(key))

        student_information_list.append(dictionary)
        print("{} student information input complete {}".format(count, dictionary))
        count += 1


if __name__ == "__main__":
    add_student()
    add_student2()
