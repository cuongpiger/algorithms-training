'''
https://www.spoj.com/problems/MICEMAZE/
Comment
'''
import sys
import queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''

INF = 10 ** 9

def dijkstra():
    pq = queue.PriorityQueue()
    pq.put((0, exit))
    dist[exit] = 0

    while not pq.empty():
        w, u = pq.get()

        if w != dist[u]:
            continue

        for neibor, weight in grp[u]:
            if dist[neibor] > w + weight:
                dist[neibor] = w + weight
                pq.put((dist[neibor], neibor))

#_____main_____
#FILE_IO()

V = int(input())
exit = int(input())
t = int(input())
E = int(input())

grp = [[] for i in range(V + 5)]
dist = [INF]*(V + 5)

for i in range(E):
    v, u, w = map(int, input().split())
    grp[u].append((v, w))

dijkstra()
cnt = 0;

for i in range(1, V + 1):
    if dist[i] <= t:
        cnt += 1

print(cnt)