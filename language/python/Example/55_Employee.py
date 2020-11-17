class Employee:
    def __init__(self, name, work_year, has_degree):
        self.name = name
        self.year = work_year
        self.has_degree = has_degree

    def print_description(self):
        salary = 0
        if self.year <= 5:
            salary = 3000 + self.year * 100
        elif self.year <= 10:
            salary = 3500 + self.year * 110
        else:
            salary = 4000 + self.year * 130

        if self.degree:
            salary += 1200

        print(salary)

    def __getattr__(self, item):
        print("No that attribute.")
