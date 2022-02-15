attempt = int(input())
for T in range(1, attempt+1):
    length = int(input())
    ans = list(map(int, input().split()))

    for i in range(length-1):
        for j in range(length-i-1):
            # 홀수일때 작은걸 뒤로 밀기
            if i % 2:
                if ans[j] < ans[j+1]:
                    ans[j], ans[j+1] = ans[j+1], ans[j]
            # 짝수일때 큰걸 뒤로 밀기
            else:
                if ans[j] > ans[j+1]:
                    ans[j], ans[j+1] = ans[j+1], ans[j]

    #뒤집기
    ans.reverse()
    print(f"#{T} {' '.join(map(str, ans[:10]))}")
