for _ in range(10):
    tc = int(input())
    PW = list(map(int, input().split()))
    btn = True
    while btn:
        snake = []
        for i in range(1, 6):
            newnm = PW[i - 1] - i
            if newnm > 0:
                snake.append(newnm)
            else:
                newnm = 0
                snake.append(newnm)
                btn = False
                break
        PW = PW[len(snake):] + snake
    print(f'#{tc}', *PW)
