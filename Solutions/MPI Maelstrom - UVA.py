'''
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=364
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

INF = 10**9
grp = []
dist = [INF]*105

def bellManFord(s):
    dist[s] = 0

    for i in range(1, n):
        for u, v, w in grp:
            if dist[u] != INF and dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
            
#__main__
#FILE_IO()

n = int(input())
for i in range(2, n + 1):
    line = input().split()

    for j in range(i - 1):
        if line[j] != 'x':
            grp.append((j + 1, i, int(line[j])))
            grp.append((i, j + 1, int(line[j])))

bellManFord(1)
res = 0

for i in range(1, n + 1):
    res = max(res, dist[i]);

print(res)