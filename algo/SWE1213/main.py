T = 10
for tc in range(1, T+1):
    _ = input()
    small = input()
    big = input()
    length = len(small)
    index = 0
    count = 0
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
    print(f"#{tc} {count}")
