attempt = 10
for T in range(1, attempt+1):
    trial = int(input())
    matrix = []
    for _ in range(100):
        matrix.append(list(map(int, input().split())))

    # 위에서부터 최대값, 한 가로줄의 합, 한 세로줄의 합, 대각선1(좌상->우하) 합, 대각선2(우상->좌하) 합이 들어갈 변수
    max = 0
    row = 0
    col = 0
    dia1 = 0
    dia2 = 0

    for i in range(100):

        # 가로줄 및 세로줄의 합
        for j in range(100):
            row += matrix[i][j]
            col += matrix[j][i]
        # 가로줄, 세로줄의 최대값 판정
        if col > max:
            max = col
        if row > max:
            max = row
        row = 0
        col = 0

        # 대각선의 합
        dia1 += matrix[i][i]
        dia2 += matrix[i][99-i]
    # 대각선 줄의 최대값 판정
    if dia1 > max:
        max = dia1
    if dia2 > max:
        max = dia2

    # 출력
    print(f"#{T} {max}")

