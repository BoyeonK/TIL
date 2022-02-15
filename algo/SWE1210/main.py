for _ in range(10):
    tc = int(input())
    ladder = [list(map(int, input().split())) for _ in range(100)]

    # x축 앞, 뒤로 0을 넣어줌 이제 ladder의 사이즈는 102 x 100
    for i in range(100):
        ladder[i].append(0)
        ladder[i].insert(0, 0)

    # y=99 이면서 밸류가 2인 값(도착지)의 x, y 값을 찾아준다.
    for i in range(102):
        if ladder[99][i] == 2:
            y, x = 99, i
            break

    right = False
    left = False

    # y값이 0이 될 때 까지 반복
    while y:
        # 오른쪽으로 가즈아 오른쪽이 0이 될때까지
        while right and ladder[y][x+1]:
            x += 1
        # 왼쪽으로 가즈아 왼쪽이 0이 될때까지
        while left and ladder[y][x-1]:
            x -= 1
        left = False
        right = False

        # 위로 가즈아
        y -= 1

        # 왼쪽이나 오른쪽의 값이 0이 아니다 하면 왼쪽이나 오른쪽으로 가즈아
        if ladder[y][x-1]:
            left = True
        elif ladder[y][x+1]:
            right = True

    # 맨 위에서 ladder의 x값 앞뒤에 의미없는 0을 붙혀 줬기 때문에 구한 x에서 1을 빼야 제대로 나옴
    print(f"#{tc} {x-1}")
