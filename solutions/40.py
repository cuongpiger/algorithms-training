import queue
import sys
from typing import List
from queue import Queue

MAX = 10005
visited = [False] * MAX



def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def get_input():
    n, m = map(int, input().strip().split())
    cat: List[int] = [0] + list(map(int, input().strip().split()))
    visited = [False] * (n + 5)
    graph = [[] for _ in range(n + 5)]
    for _ in range(n - 1):
        u, v = map(int, input().strip().split())
        graph[u].append(v)
        graph[v].append(u)
        
    return m, cat, graph, visited

def solve(m, cat, graph, visited):
    q = Queue()
    q.put((1, int(cat[1] == 1)))
    res = 0
    
    while not q.empty():
        v, c = q.get()
        
        # if is leaf node and not the house node
        if len(graph[v]) == 1 and v != 1 and c <= m:
            res += 1
            continue
        
        if visited[v]:
            continue
        
        visited[v] = True
        for u in graph[v]:
            C = 0
            if visited[u]:
                continue
            
            if cat[u] == 0:
                C = 0
            else:
                C = c + 1
            
            if c <= m:
                q.put((u, C))
                
    return res

# FILE_IO()
print(solve(*get_input()))
        