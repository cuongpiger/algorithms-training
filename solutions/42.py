import sys
import threading
from typing import List

DIR = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

class node:
    def __init__(self, x: int, y: int, cnt: int) -> None:
        self.x = x
        self.y = y
        self.cnt = cnt


def get_input():
    N, M, K = map(int, input().split())
    G = []
    for _ in range(N):
        G.append(list(input()))
    return N, M, G, K


def dfs(x: int, y: int, cnt: int, N: int, M:int,  graph: List[List[str]], vst: List[List[bool]], rep: bool) -> int:
    vst[x][y] = True
    if rep:
        graph[x][y] = '*'
    cnt += 1
    
    for d in DIR:
        xx = x + d[0]
        yy = y + d[1]
        
        if xx < 0 or xx >= N or yy < 0 or yy >= M:
            continue
        
        if vst[xx][yy] or graph[xx][yy] == '*':
            continue
        
        cnt = dfs(xx, yy, cnt, N, M, graph, vst, rep)
        
    return cnt
    
        
def solve():
    N, M, G, K = get_input()
    vst = [[False for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if (i == 0 or i == N - 1 or j == 0 or j == M - 1) and G[i][j] == '.':
                dfs(i, j, 0, N, M, G, vst, False)
                
    pos: List[node] = []
    for i in range(1, N - 1):
        for j in range(1, M - 1):
            if G[i][j] == '.' and not vst[i][j]:
                cnt = dfs(i, j, 0, N, M, G, vst, False)
                pos.append(node(i, j, cnt))
                
    pos = sorted(pos, key=lambda x: x.cnt)
    sm = 0
    vst = [[False for _ in range(M)] for _ in range(N)]
    for p in pos[:len(pos) - K]:
        sm += p.cnt
        dfs(p.x, p.y, 0, N, M, G, vst, True)
        
    print(sm)
    print("\n".join(["".join(g) for g in G]))
    
FILE_IO()
threading.stack_size(70_000_000)
sys.setrecursionlimit(2**20)
thread = threading.Thread(target=solve)
thread.start()
