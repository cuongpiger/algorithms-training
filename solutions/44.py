import sys
from typing import List, Tuple
 
 
def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    
def dfs(G: List[List[Tuple[int, int]]], W: List[int], u: int):
    for v, w in G[u]:
        if W[v] == -1:
            W[v] = W[u] + w
            dfs(G, W, v)
        
        
def find_max(W: List[int], N: int):
    max_id = 0
    for i in range(N):
        if W[i] > W[max_id]:
            max_id = i
    return max_id
 
def solve():
    T = int(input())
    G: List[List[Tuple[int, int]]] = [[] for _ in range(50_005)]
    W: List[int] = [-1 for _ in range(50_005)]
    for _ in range(T):
        N = int(input())
        
        for i in range(N):
            G[i].clear()
            W[i] = -1
        
        for _ in range(N - 1):
            u, v, w = map(int, input().split())
            u -= 1
            v -= 1
            G[u].append((v, w))
            G[v].append((u, w))
            
        
        W[0] = 0
        dfs(G, W, 0)
        max_id = find_max(W, N)
        for i in range(N):
            W[i] = -1
        W[max_id] = 0
        dfs(G, W, max_id)
        print(W[find_max(W, N)])
 
        
# FILE_IO()
solve() 