attempt = int(input())
for T in range(1, attempt+1):
    nm = list(map(int, input().split()))
    n = nm[0]
    m = nm[1]
    point = 0
    cmpr = 0
    fliesmap = []
    for _ in range(n):
        fliesmap.append(list(map(int, input().split())))
    for xindex in range(n-m+1):
        for yindex in range(n-m+1):
            for y in range(yindex, yindex+m):
                cmpr += sum(fliesmap[y][xindex:xindex+m])
            if cmpr > point:
                point = cmpr
            cmpr = 0
    print("#{0}".format(T), end=" ")
    print(point)

