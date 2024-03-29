'''
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1187
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''
INF = 10**9
c, r, q = 0, 0, 0
tc = 0
cost = []
grp = []
dist = []

def floyWarshall():
    maxCost = [[0 for j in range(c + 5)] for i in range(c +5)]

    for i in range(c):
        for j in range(c):
            maxCost[i][j] = max(cost[i], cost[j])
            dist[i][j] = min(INF, grp[i][j] + maxCost[i][j])

    for t in range(2):
        for k in range(c):
            for i in range(c):
                for j in range(c):
                    if dist[i][j] > dist[i][k] + dist[k][j] - min(maxCost[i][k], maxCost[k][j]):
                        dist[i][j] = dist[i][k] + dist[k][j] - min(maxCost[i][k], maxCost[k][j])
                        maxCost[i][j] = max(maxCost[i][k], maxCost[k][j])

#__main__
#FILE_IO()
while True: 
    tc += 1
    c, r, q = list(map(int, input().split()))

    if c + r + q == 0:
        break

    if tc > 1:
        print()

    cost = list(map(int, input().split()))
    grp = [[INF for j in range(c + 5)] for i in range(c + 5)]
    dist = [[0 for j in range(c + 5)] for i in range(c + 5)]

    for i in range(c + 5):
        grp[i][i] = 0

    for i in range(r):
        u, v, w = map(int, input().split())
        grp[u - 1][v - 1] = grp[v - 1][u - 1] = w

    floyWarshall()
    print('Case #{}'.format(tc))

    for i in range(q):
        u, v = map(int, input().split())
        print(-1 if dist[u - 1][v - 1] == INF else dist[u - 1][v - 1])