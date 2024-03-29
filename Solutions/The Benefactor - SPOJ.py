'''
https://www.spoj.com/problems/BENEFACT/
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

dist = None
grp = None

def dfs(u):
    for v, w in grp[u]:
        if dist[v] == -1:
            dist[v] = dist[u] + w
            dfs(v)

if __name__ == '__main__':
    #FILE_IO()
    tc = int(input())

    for _ in range(tc):
        n = int(input())
        dist = [-1]*(n + 5)
        grp = [[] for i in range(n + 5)]

        for i in range(n - 1):
            u, v, w = map(int, input().split())
            grp[u].append([v, w])
            grp[v].append([u, w])

        dist[1] = 0
        dfs(1)
        maxVer = dist.index(max(dist))
        dist = [-1]*(n + 5)
        dist[maxVer] = 0
        dfs(maxVer)
        print(max(dist))