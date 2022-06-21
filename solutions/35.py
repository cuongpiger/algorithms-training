import sys
from queue import Queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    
def get_input():
    ground = []
    W, H = map(int, input().split())
    for _ in range(H):
        ground.append(input().strip())
        
    return H, W, ground

def find_prince(H, W, ground):
    for i in range(H):
        for j in range(W):
            if ground[i][j] == '@':
                return i, j
            
    return -1, -1

DIRECTIONS = ((1, 0), (-1, 0), (0, 1), (0, -1))
def bfs(ph, pw, H, W, ground):
    q = Queue()
    q.put((ph, pw))
    visited = dict()
    visited[(ph, pw)] = True
    
    while not q.empty():
        h, w = q.get()
        for x, y in DIRECTIONS:
            nh, nw = h + x, w + y
            if 0 <= nw < W and 0 <= nh < H and ground[nh][nw] == '.' and not visited.get((nh, nw), False):
                q.put((nh, nw))
                visited[(nh, nw)] = True
                
    return len(visited)

def solve():
    T = int(input())
    for t in range(1, T + 1):
        H, W, ground = get_input()
        prince = find_prince(H, W, ground)
        res = bfs(prince[0], prince[1], H, W, ground)
        
        print(f"Case {t}: {res}")
    
    
# FILE_IO()
solve()