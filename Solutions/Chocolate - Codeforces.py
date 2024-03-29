#https://codeforces.com/problemset/problem/617/B
'''
Comment
'''

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0]*(n + 10)
    dp = [0]*(n + 10)
    dp[0] = 1

    for i in range(1, n + 1):
        cnt[i] = cnt[i - 1] + a[i - 1]

    for i in range(1, n + 1):
        for j in range(0, i):
            if cnt[i] - cnt[j] == 1:
                dp[i] += dp[j]

    print(dp[n])