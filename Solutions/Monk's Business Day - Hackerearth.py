'''
https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/monks-business-day/description/
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

INF = 10**9
grp = []

def bellManFord(src):
    dist = [INF] * (n + 5)
    dist[src] = 0

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
n, m = None, None

tc = int(input())

while tc > 0:
    tc -= 1
    n, m = map(int, input().split())

    for i in range(m):
        u, v, w = map(int, input().split())
        grp.append((u, v, -w))

    print('Yes' if bellManFord(1) else 'No')
    grp.clear()
