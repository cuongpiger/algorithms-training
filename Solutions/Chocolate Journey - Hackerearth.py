'''
https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/successful-marathon-0691ec04/description/
Comment
'''
import sys
import queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

INF = 10 ** 9

def dijkstra(s):
    dist = [INF] * (n + 1)
    dist[s] = 0
    q = queue.PriorityQueue()
    q.put((0, s))

    while not q.empty():
        w, u = q.get()

        if w != dist[u]:
            continue

        for neibor, weight in grp[u]:
            if dist[neibor] > w + weight:
                dist[neibor] = w + weight
                q.put((dist[neibor], neibor))

    return dist
    
#_____main_____
#FILE_IO()

data = sys.stdin.readlines()
n, m, k, x = map(int, data[0].strip().split())
chocoCity = list(map(int, data[1].strip().split()))
grp = [[] for i in range(n + 1)]

for i in range(m):
    u, v, w = map(int, data[i + 2].strip().split())
    grp[u].append((v, w))
    grp[v].append((u, w))
a, b = map(int, data[-1].strip().split())

distA = dijkstra(a)
distB = dijkstra(b)
res = INF

for city in chocoCity:
    if distB[city] <= x:
        res = min(res, distA[city] + distB[city])
    
if res < INF:
    print(res)
else:
    print(-1)
