#https://www.spoj.com/problems/TRVCOST/
'''
Comment
'''

import queue

INF = 60000
grp = [[] for _ in range(510)]
dist = [INF for _ in range(510)]

class Node:
    def __init__(seft, _vertex, _weight):
        seft.vertex = _vertex
        seft.weight = _weight

    def __lt__(seft, other):
        return seft.weight < other.weight

def dijkstra(src):
    pq = queue.PriorityQueue()
    pq.put(Node(src, 0))
    dist[src] = 0

    while not pq.empty():
        top = pq.get()
        v = top.vertex
        w = top.weight

        for neightbor in grp[v]:
            if w + neightbor.weight < dist[neightbor.vertex]:
                dist[neightbor.vertex] = w + neightbor.weight
                pq.put(Node(neightbor.vertex, dist[neightbor.vertex]))


if __name__=="__main__":
    n = int(input())
    for _ in range(n):
        a, b, w = map(int, input().split())
        grp[a].append(Node(b, w))
        grp[b].append(Node(a, w))

    src = int(input())
    qry = int(input())
    dijkstra(src)

    for _ in range(qry):
        des = int(input())
        print(dist[des] if dist[des] != INF else "NO PATH")