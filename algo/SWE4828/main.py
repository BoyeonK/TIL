attempt = int(input())
for T in range(1, attempt+1):
    length = int(input())
    numbers = list(map(int, input().split()))
    for i in range(length-1):
        if numbers[i+1] < numbers[i]:
            exchange = numbers[i]
            numbers[i] = numbers[i+1]
            numbers[i+1] = exchange

    for i in range(length-2):
        if numbers[i+1] > numbers[i]:
            exchange = numbers[i]
            numbers[i] = numbers[i + 1]
            numbers[i + 1] = exchange

    print("#{0}".format(T), end=" ")
    print(numbers[length-1]-numbers[length-2])
