#https://codeforces.com/problemset/problem/677/A
'''
Comment
'''

if __name__ == "__main__":
    n, h = map(int, input().split())
    height = list(map(int, input().split()))
    res = 0;

    for i in range(n):
        res += 2 if height[i] > h else 1
    print(res)