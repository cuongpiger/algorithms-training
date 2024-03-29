'''
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
Comment
'''
import sys
import queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''

INF = 10**9
grp = [[] for i in range(20005)]
n = m = s = d = None

def dijkstra():
    dist = [INF]*(n + 5)
    dist[s] = 0
    pq = queue.PriorityQueue()
    pq.put((0, s))

    while not pq.empty():
        w, u = pq.get()

        if w != dist[u]:
            continue

        for neibor, weight in grp[u]:
            if dist[neibor] > w + weight:
                dist[neibor] = w + weight
                pq.put((dist[neibor], neibor))

    if dist[d] == INF:
        return 'unreachable'
    return str(dist[d])

#_____main_____
#FILE_IO()

data = sys.stdin.readlines()
tc = int(data[0])
line = 1

for cs in range(1, tc + 1):
    n, m, s, d = map(int, data[line].split())
    line += 1
    
    while m > 0:
        u, v, w = map(int, data[line].split())
        line += 1
        m -= 1

        grp[u].append((v, w))
        grp[v].append((u, w))

    print(f"Case #{cs}: {dijkstra()}")

    for i in range(n):
        grp[i].clear()

