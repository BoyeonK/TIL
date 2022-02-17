T = int(input())
for tc in range(1, T+1):
    string = input()
    bars = 0
    total = 0
    for index in range(len(string)):
        if string[index] == '(':
            bars += 1
        elif string[index-1] == '(':
            bars -= 1
            total += bars
        else:
            bars -= 1
            total += 1
    print(f"#{tc} {total}")

