attempt = int(input())
for T in range(1, attempt+1):
    length = int(input())
    ans = list(map(int, input().split()))
    for i in range(length-1):
        for j in range(length-i-1):
            if i % 2:
                if ans[j] < ans[j+1]:
                    ans[j], ans[j+1] = ans[j+1], ans[j]
            else:
                if ans[j] > ans[j+1]:
                    ans[j], ans[j+1] = ans[j+1], ans[j]

    ans.reverse()
    print(f"#{T} {' '.join(map(str, ans[:10]))}")
