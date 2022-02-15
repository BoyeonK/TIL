attempt = int(input())
for tc in range(1, attempt+1):
    N, K = map(int, input().split())
    puzzle = [list(map(int, input().split())) for _ in range(N)]

    row = []
    rowtotal = 0
    col = []
    coltotal = 0
    for i in range(N):
        for j in range(N):
            if puzzle[i][j]:
                rowtotal += 1
                if j == N-1 and rowtotal:
                    row.append(rowtotal)
                    rowtotal = 0
            else:
                if rowtotal:
                    row.append(rowtotal)
                    rowtotal = 0

            if puzzle[j][i]:
                coltotal += 1
                if j == N-1 and coltotal:
                    col.append(coltotal)
                    coltotal = 0
            else:
                if coltotal:
                    col.append(coltotal)
                    coltotal = 0

    ans = row.count(K) + col.count(K)
    print(f"#{tc} {ans}")

