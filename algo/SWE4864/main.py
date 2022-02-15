attempt = int(input())
for T in range(1, attempt+1):
    alpha = input()
    beta = input()

    check = 0
    ans = 0
    for b in beta:
        check = check + 1 if b == alpha[check] else 0
        if check == len(alpha):
            ans = 1
            break
    print(f"#{T} {ans}")
