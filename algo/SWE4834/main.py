attempt = int(input())
for T in range(1, attempt + 1):
    length = int(input())
    numbers = input()

    count = [0] * 10    # 0~9 까지의 index를 가지는 리스트 생성
    for number in numbers:
        count[int(number)] += 1     # index에 해당하는 카드 수 세기

    mxm = 0
    for stack in count:
        if stack > mxm:
            mxm = stack     # count의 원소 중 최대값을 구한다.

    for index in reversed(range(10)):
        if count[index] == mxm:     # 앞서 구한 최댓값을 가질 때의 index 구하기
            card = index
            break

    print("#{0} {1} {2}".format(T, card, mxm))
