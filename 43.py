import sys
from typing import List


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    
def dfs(G: List[List[int]], vst: List[bool], u: int):
    vst[u] = True
    for v in G[u]:
        if not vst[v]:
            dfs(G, vst, v)

def solve():
    T = int(input())
    G: List[List[int]] = [[] for _ in range(100_005)]
    vst: List[bool] = [False for _ in range(100_005)]
    for _ in range(T):
        input()
        N = int(input())
        E = int(input())
        for i in range(N):
            G[i].clear()
            vst[i] = False
        
        for _ in range(E):
            u, v = map(int, input().split())
            G[u].append(v)
            G[v].append(u)
            
        cnt = 0
        for i in range(N):
            if not vst[i]:
                cnt += 1
                dfs(G, vst, i)
        
        print(cnt)
        
# FILE_IO()
solve()