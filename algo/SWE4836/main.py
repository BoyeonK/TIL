attempt = int(input())
for T in range(1, attempt+1):
    n = int(input())
    reds = []
    blues = []
    for _ in range(10):
        reds.append([0]*10)
        blues.append([0]*10)

    for _ in range(n):
        a = list(map(int, input().split()))
        if a[4] == 1:
            for dx in range(a[0], a[2]+1):
                for dy in range(a[1], a[3]+1):
                    reds[dx][dy] = 1
        else:
            for dx in range(a[0], a[2]+1):
                for dy in range(a[1], a[3]+1):
                    blues[dx][dy] = 1
    total = 0
    for dx in range(10):
        for dy in range(10):
            total += reds[dx][dy] * blues[dx][dy]
    print(f"#{T} {total}")
