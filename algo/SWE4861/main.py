attempt = int(input())
for T in range(1, attempt+1):
    N, M = map(int, input().split())
    alpha = [input() for _ in range(N)]
    half = int(M/2)

    ans = ''
    for i in range(N):
        for j in range(N):
            check = 0
            if j <= N-M:
                for k in range(half):
                    if alpha[i][j+k] == alpha[i][j+M-k-1]:
                        check += 1
                    else:
                        break

                    if check == half:
                        y, x, isr = i, j, True
                        break

            check = 0
            if i <= N-M:
                for k in range(half):
                    if alpha[i+k][j] == alpha[i+M-k-1][j]:
                        check += 1
                    else:
                        break

                    if check == half:
                        y, x, isr = i, j, False
                        break


    for i in range(M):
        ans += alpha[y][x+i] if isr else alpha[y+i][x]
    print(f"#{T} {ans}")
