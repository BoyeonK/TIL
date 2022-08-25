dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
for _ in range(10):
    tc = int(input())
    miro = []
    for i in range(16):
        row = list(map(int, input()))
        miro.append(row)
        if 2 in row:
            sp = (i, row.index(2))
        elif 3 in row:
            ep = (i, row.index(3))
    stack = [sp]
    going = True
    ans = 0
    while stack and going:
        y = stack[-1][0]
        x = stack[-1][1]
        miro[y][x] = 1
        for i in range(4):
            newy = y + dy[i]
            newx = x + dx[i]
            step = miro[newy][newx]
            if step == 0:
                stack.append((newy, newx))
                break
            elif step == 3:
                ans = 1
                going = False
                step = len(stack)
                break
            if i == 3:
                stack.pop()
    print(f'#{tc} {step}')
