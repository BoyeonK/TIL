def Queen(now, mxm):
    n = len(now)

    # 모든 퀸이 놓여져 있는가?
    if n == mxm:
        global ans
        ans += 1

    # 아니라면 이제 퀸을 놓을거야
    else:
        # 내가 퀸을 놓고 싶은 자리 i
        for i in range(mxm):
            putable = True
            for j in range(1, n+1):
                # i(퀸을 놓고 싶은 자리)가 now[-j](퀸이 이미 있는 자리) 의 직선 혹은 대각방향인가? (놓을 수 없는 자리인가?)
                if now[-j] == i or now[-j] == i+j or now[-j] == i-j:
                    putable = False
                    break

            # 놓을 수 있는 자리면
            if putable:
                # 놓고
                now.append(i)
                # 재귀
                Queen(now, mxm)

                # 이 이후의 줄이 실행된다는 건 앞서 놓은 퀸을 두고 가능한 모든 경우의 수를 탐색했다는 뜻임
                # 이제 이 친구는 할일을 다 했으니 뗀다.
                now.pop()


T = int(input())
for tc in range(1, T+1):
    N = int(input())
    ans = 0
    Queen([], N)
    print(f'#{tc} {ans}')





