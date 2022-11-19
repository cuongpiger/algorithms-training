import queue
import sys
from queue import Queue


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


MAX = 10010
visited = [0 for _ in range(MAX)]
graph = [[] for _ in range(MAX)]


def dfs(u):
    visited[u] = 1  # mark this vertex as visited
    for v in graph[u]:  # loop through all adjacent vertices
        if visited[v] == 1:  # has been visited before
            return True  # cycle detected
        elif visited[v] == 0:  # has not been visited before
            if dfs(v):  # recursively call dfs, if cycle detected => return True
                return True
            
    visited[u] = 2  # mark this vertex as visited completely but not detected cycle
    return False


def solve():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().strip().split())
        for i in range(1, N+5):
            graph[i].clear()
            visited[i] = 0
        
        for _ in range(M):
            u, v = map(int, input().strip().split())
            graph[u].append(v)
            
        cycle = "NAO"
        for i in range(1, N+1):
            if visited[i] == 0 and dfs(i):
                cycle = "SIM"
                break
            
        print(cycle)
        
# FILE_IO()
solve()