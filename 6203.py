class Person:
    def __init__(self, korean, english, math):
        self.korean = korean
        self.english = english
        self.math = math
        print("국어, 영어, 수학의 총점: {0}".format(self.korean + self.english + self.math))

a, b, c = map(int, input().split(','))
member = Person(a, b, c)