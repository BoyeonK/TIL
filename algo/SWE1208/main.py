attempt = 10
for T in range(1, attempt + 1):
    dump = int(input())
    boxes = list(map(int, input().split()))

    counts = [0]*101
    for box in boxes:
        counts[box] += 1
        # 박스의 높이(index)에 해당하는 박스 개수

    for i in range(101):
        if counts[i]:
            mnm = i
            break
        # 0부터 셌을 때 처음으로 개수가 0이 아닌 높이(index)값

    for i in range(100, -1, -1):
        if counts[i]:
            mxm = i
            break
        # 100부터 거꾸로 셌을 때 처음으로 0이 아닌 높이(index)값

    while dump:     # dump가 0이 아니면 반복
        if (mxm-mnm) < 2:   # 최대, 최소 차가 1이하면 중단.
            break
        counts[mxm] -= 1
        counts[mxm-1] += 1
        counts[mnm] -= 1
        counts[mnm+1] += 1
        dump -= 1
        # 덤핑을 구현

        while counts[mxm] == 0:
            mxm -= 1
            # 최댓값이 0이 됬을 경우 남은 값 중에서 최대 값을 찾음
        if counts[mnm] == 0:
            mnm += 1
            # 최솟값이 0이 됬을 경우 (이전 과정에서 덤핑되서 높이가 올라옴)

    ans = mxm-mnm
    print("#{0} {1}".format(T, ans))
