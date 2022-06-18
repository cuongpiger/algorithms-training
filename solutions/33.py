import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    
    
def get_input(sea):
    N, M = map(int, input().split())
    for i in range(N):
        sea[i][:M] = list(map(int, input().split()))
    
    return N, M

def next_directions(R, C, N, M, sea):
    candidates = [
        (R + 1, C),
        (R - 1, C),
        (R, C + 1),
        (R, C - 1)
    ]
    
    return [(r, c) for r, c in candidates if 0 <= r < N and 0 <= c < M and sea[r][c] == 1]
    

def bfs(R, C, N, M, sea, queue):
    l, r = 0, 0
    queue[l] = (R, C)
    sea[R][C] = 2

    while  l <= r:
        top = queue[l]
        l += 1
        for candidate in next_directions(top[0], top[1], N, M, sea):
            r += 1
            queue[r] = candidate
            sea[candidate[0]][candidate[1]] = 2
            
    return r + 1


def solve():
    sea = [[0 for i in range(255)] for j in range(255)]
    queue = [None] * (255 * 255)
    
    while True:
        N, M = get_input(sea)
        res = {}
        
        if N + M == 0:
            return
        
        for i in range(N):
            for j in range(M):
                if sea[i][j] == 1:
                    nos = bfs(i, j, N, M, sea, queue)
                    res[nos] = res.get(nos, 0) + 1
                    
        print(sum(res.values()))
        for k in sorted(res.keys()):
            print(k, res.get(k))
    
    
# FILE_IO()
solve()