attempt = int(input())
for T in range(1, attempt+1):
    num, total = map(int, input().split())
    mnm = 0
    mxm = 0

    for i in range(num):
        mnm += i+1
        mxm += (12-i)

    ans = 0
    if mnm <= total <= mxm:
        subset = [0] * num
        digit = (13-num)
        total -= mnm
        while subset[num-1] < digit:
            isit = False
            if sum(subset) == total:
                isit = True
                for i in range(num - 1):
                    if subset[i+1] < subset[i]:
                        isit = False

            if isit:
                ans += 1

            subset[0] += 1
            for i in range(num-1):
                if subset[i] == digit:
                    subset[i] = 0
                    subset[i+1] += 1

    print(f"#{T} {ans}")

