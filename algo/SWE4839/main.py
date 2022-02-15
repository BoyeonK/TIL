attempt = int(input())
for T in range(1, attempt+1):
    P, Pa, Pb = map(int, input().split())

    amax = P
    amin = 1
    amid = int((amax+amin)/2)
    atrial = 1
    # 중간값이 찾는 값과 다르면 반복
    while amid != Pa:
        # 작으면 중간값을 아래값으로 대체
        if Pa > amid:
            amin = amid
        # 크면 중간값을 위의 값으로 대체
        else:
            amax = amid
        # 새로운 중간값을 구함
        amid = int((amax + amin) / 2)
        # 시도 횟수 +1
        atrial += 1

    bmax = P
    bmin = 1
    bmid = int((bmax+bmin)/2)
    btrial = 1
    while bmid != Pb:
        if Pb > bmid:
            bmin = bmid
        else:
            bmax = bmid
        bmid = int((bmax + bmin) / 2)
        btrial += 1

    # A의 횟수와 B의 횟수를 비교
    ans = 0
    if atrial-btrial:
        if atrial < btrial:
            ans = 'A'
        else:
            ans = 'B'

    print(f"#{T} {ans}")
