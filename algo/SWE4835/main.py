attempt = int(input())
for T in range(1, attempt+1):
    length, rows = map(int, input().split())
    numbers = list(map(int, input().split()))
    mxm = 0
    mnm = 0
    for row in range(rows):
        mxm += numbers[row]
    mnm = mxm
    total = 0
    for index in range(1, length-rows+1):
        for row in range(rows):
            total += numbers[index+row]
        if total > mxm:
            mxm = total
        if total < mnm:
            mnm = total
        total = 0

    print("#{0}".format(T), end=" ")
    print(mxm-mnm)
