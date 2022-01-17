def RPS(a):
    if a[2] == a[3]:
        print('비겼습니다.')
    elif a[2] == '가위' or a[3] == '가위':
        if a[2] == '바위' or a[3] == '바위':
            print('바위가 이겼습니다!')
        else:
            print('가위가 이겼습니다!')
    else:
        print('보가 이겼습니다!')

a = input()
b = input()
c = input()
d = input()
e = [a, b, c, d]
RPS(e)