attempt = int(input())
for T in range(1, attempt+1):
    P, Pa, Pb = map(int, input().split())

    amax = P
    amin = 1
    amid = int((amax+amin)/2)
    atrial = 1
    while amid != Pa:
        if Pa > amid:
            amin = amid
        else:
            amax = amid
        amid = int((amax + amin) / 2)
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

    ans = 0
    if atrial-btrial:
        if atrial < btrial:
            ans = 'A'
        else:
            ans = 'B'

    print(f"#{T} {ans}")
