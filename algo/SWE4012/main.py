T = int(input())
for tc in range(1, T+1):
    length = int(input())
    points = [list(map(int, input().split())) for _ in range(length)]

    for y in range(1, length):
        for x in range(y):
            points[y][x] += points[x][y]

    half = int(length / 2)
    listnum = [i for i in range(length)]
    setnum = set(listnum)
    digit = [0] * length
    for i in range(half):
        digit[i] = 1
    mnm = 20000

    while digit[length-1] < 1:
        setA = set()
        pointA = 0
        pointB = 0
        if sum(digit) == half:
            for i in range(length):
                if digit[i]:
                    setA.add(listnum[i])
                setB = setnum - setA

            for y in range(1, length):
                for x in range(y):
                    if x in setA and y in setA:
                        pointA += points[y][x]
                    elif x in setB and y in setB:
                        pointB += points[y][x]
            diff = abs(pointA-pointB)
            if mnm > diff:
                mnm = diff

        digit[0] += 1
        for i in range(length-1):
            if digit[i] > 1:
                digit[i] = 0
                digit[i+1] += 1
    print(f"#{tc} {mnm}")

