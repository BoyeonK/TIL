for tc in range(1, 11):
    _ = input()
    string = [input() for _ in range(100)]
    flag = False
    ans = ''
    length = 100
    while length > 1:
        if flag:
            break
        half = length // 2
        for i in range(100):
            if flag:
                break
            for j in range(100 - length + 1):
                check = 0
                if flag:
                    break
                for k in range(half):
                    if string[i][j + k] == string[i][j + length - k - 1]:
                        check += 1
                    else:
                        break
                    if check == half:
                        flag = True

        for i in range(100 - length + 1):
            if flag:
                break
            for j in range(100):
                if flag:
                    break
                check = 0
                for k in range(half):
                    if string[i + k][j] == string[i + length - k - 1][j]:
                        check += 1
                    else:
                        break
                    if check == half:
                        flag = True
        length -= 1
    print(f"#{tc} {length + 1}")
