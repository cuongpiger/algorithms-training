import sys
from queue import Queue


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def get_input():
    graph = dict()
    n, m = map(int, input().split())

    for i in range(1, n + 1):
        graph[i] = list()

    for _ in range(m):
        u, v = map(int, input().split())
        graph.get(u).append(v)
        graph.get(v).append(u)

    start = int(input())

    return graph, n, start


def bfs(start, graph):
    q = Queue()
    q.put(start)
    visited = dict()
    visited[start] = 0

    while not q.empty():
        u = q.get()

        for nb in graph.get(u):
            if visited.get(nb) is None:
                visited[nb] = visited[u] + 1
                q.put(nb)

    return visited


def solve():
    NOQ = int(input())

    while NOQ > 0:
        NOQ -= 1
        graph, n, start = get_input()
        vertices = bfs(start, graph)
        res = ["-1" if vertices.get(v) is None else str(vertices.get(v) * 6)
               for v in range(1, n + 1) if v != start]
        print(" ".join(res))


# FILE_IO()
solve()
