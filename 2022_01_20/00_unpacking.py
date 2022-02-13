def my_avg(*args):
    return sum(args) / len(args)

numbers = map(int, input().split())

#print(my_avg(numbers)) <= 에러 발생
print(my_avg(*numbers))