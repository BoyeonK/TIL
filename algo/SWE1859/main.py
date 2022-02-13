attempt = int(input())
for T in range(1, attempt + 1):
    length = int(input())
    price = list(map(int, input().split()))
    money = 0
    while price:
        mxi = price.index(max(price))
        mxv = max(price)
        money += mxi * mxv - sum(price[0:mxi])
        price = price[mxi+1:length]
    print(f"#{T} {money}")






