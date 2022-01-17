A = lambda x: x + 4
B = lambda x: x + 3
C = lambda x: x + 2
D = lambda x: x + 1

sum = 0
moon = 'ADCBBBBCABBCBDACBDCAACDDDCAABABDBCBCBDBDBDDABBAAAAAAADADBDBCBDABADCADC'

for i in moon:
    if i == 'A':
        sum = A(sum)
    elif i == 'B':
        sum = B(sum)
    elif i == 'C':
        sum = C(sum)
    elif i == 'D':
        sum = D(sum)

print(sum)