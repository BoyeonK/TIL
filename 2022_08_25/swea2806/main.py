def Queen(now, mxm):
    n = len(now)
    if n == mxm:
        global ans
        ans += 1
    else:
        putqueen = set()
        for i, v in enumerate(now):
            putqueen = putqueen.union({v, v+(n-i), v-(n-i)})
        global place
        putqueen = place.difference(putqueen)
        for i in putqueen:
            now.append(i)
            Queen(now, mxm)
            now.pop()


T = int(input())
for tc in range(1, T+1):
    N = int(input())
    ans = 0
    place = set()
    for i in range(N):
        place.add(i)
    Queen([], N)
    print(f'#{tc} {ans}')
