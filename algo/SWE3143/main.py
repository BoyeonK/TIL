T = int(input())
for tc in range(1, T+1):
    big, small = map(str, input().split())
    count = 0
    index = 0
    length = len(small)
    for alpha in big:
        if alpha == small[index]:
            index += 1
        elif alpha == small[0]:
            index = 1
        else:
            index = 0

        if index == length:
            index = 0
            count += 1
    ans = len(big) - count * (length - 1)
    print(f"#{tc} {ans}")
