T = int(input())
for _ in range(T):
    tc, _ = map(str, input().split())
    lang = input()
    count = [0]*10
    while 1:
        alpha = lang[0]
        beta = lang[1]
        if alpha == 'Z':
            count[0] += 1
        elif alpha == 'O':
            count[1] += 1
        elif alpha == 'T':
            if beta == 'W':
                count[2] += 1
            else:
                count[3] += 1
        elif alpha == 'F':
            if beta == 'O':
                count[4] += 1
            else:
                count[5] += 1
        elif alpha == 'S':
            if beta == 'I':
                count[6] += 1
            else:
                count[7] += 1
        elif alpha == 'E':
            count[8] += 1
        elif alpha == 'N':
            count[9] += 1

        if len(lang) <= 4:
            break
        lang = lang[4:]

    srt = ''
    srt += 'ZRO ' * count[0]
    srt += 'ONE ' * count[1]
    srt += 'TWO ' * count[2]
    srt += 'THR ' * count[3]
    srt += 'FOR ' * count[4]
    srt += 'FIV ' * count[5]
    srt += 'SIX ' * count[6]
    srt += 'SVN ' * count[7]
    srt += 'EGT ' * count[8]
    srt += 'NIN ' * count[9]
    print(tc)
    print(srt)

