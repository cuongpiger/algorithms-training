'''
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

INF = 10**9
grp = []
n = m = None

def bellManFord():
    dist = [INF]*(n + 5)
    dist[0] = 0

    for i in range(1, n):
        for u, v, w in grp:
            if dist[u] != INF and dist[v] > dist[u] + w:
                dist[v] = dist[u] + w

    for u, v, w in grp:
        if dist[u] != INF and dist[v] > dist[u] + w:
            return True

    return False

#__main__
#FILE_IO()

tc = int(input())

while tc > 0:
    tc -= 1

    n, m = map(int, input().split())
    for i in range(m):
        u, v, w = map(int, input().split())
        grp.append((u, v, w))

    res = bellManFord()
    print('possible' if res else 'not possible')
    grp.clear()
