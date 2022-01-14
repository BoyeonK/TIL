import random


numbers = range(1, 46)
lucky_numbers = random.sample(numbers,6)
sorted_numbers = sorted(lucky_numbers)
print(f'{sorted_numbers}')


target = [6, 12, 22, 27, 42, 43]
'''
for _ in range(5):
    lucky_numbers = random.sample(numbers,6)
    sorted_numbers = sorted(lucky_numbers)
    print(target)
    print(sorted_numbers)
'''