grades = {'kim': 80, 'lee': 100}
for key in grades:
    print(key, grades[key])

for key in grades.keys():
    print(key, grades[key])

for value in grades.values():
    print(value)

for key, value in grades.items():
    print(key, value)