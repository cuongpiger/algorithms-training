import sys
from queue import Queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    
def get_input():
    sea = []
    N, M = map(int, input().split())
    for _ in range(N):
        sea.append(input().strip())
        
    return N, M, sea

DIRECTIONS = ((1, 0), (-1, 0), (0, 1), (0, -1))
def bfs(sx, sy, tx, ty, N, M, sea):
    visited = dict()
    visited[(sx, sy)] = 1
    q = Queue()
    q.put((sx, sy))
    
    while not q.empty():
        u = q.get()
        for x, y in DIRECTIONS:
            vx, vy = u[0] + x, u[1] + y
            if 0 <= vx < N and 0 <= vy < M and sea[vx][vy] == '.' and visited.get((vx, vy), 0) == 0:
                visited[(vx, vy)] = 1
                q.put((vx, vy))
                if (vx, vy) == (tx, ty):
                    return True
                
    return False

def solve():
    t = int(input())
    while t > 0:
        t -= 1
        N, M, sea = get_input()
        
        if N + M == 0:
            return
        
        res = {}
        gates = []
        for i in range(N):
            for j in range(M):
                if sea[i][j] == '.' and (i == 0 or j == 0 or i == N - 1 or j == M - 1):
                    gates.append((i, j))
                    
        if len(gates) == 2:
            if bfs(gates[0][0], gates[0][1], gates[1][0], gates[1][1], N, M, sea):
                print("valid")
                continue
            
        print("invalid")
    
    
# FILE_IO()
solve()