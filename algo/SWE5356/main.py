T = int(input())
for tc in range(1, T+1):
    string = [input() for _ in range(5)]
    ans = ''
    length = 5
    index = 0
    while string:
        if string[index]:
            ans += string[index][:1]
            string[index] = string[index][1:]
            index += 1
        else:
            string.pop(index)
            length -= 1
        if index > length-1:
            index = 0
    print(f"#{tc} {ans}")



