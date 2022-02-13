T = 10
for test_case in range(1, T+1):
    a = int(input())
    b = list(map(int, input().split()))
    c = [b[0], b[1], b[2], b[3], b[4]]
    index = 2
    point = 0
    while 1:
        if max(c) == b[index]:
            point += (b[index]-sorted(c)[3])
        index += 1
        if index >= len(b)-2:
            break
        c.pop(0)
        c.append(b[index+2])
    print("#{0}".format(test_case), end=" ")
    print(point)
