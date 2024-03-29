'''
https://www.spoj.com/problems/ALLIZWEL/
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

dirt = [(0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]
ans = 'ALLIZZWELL'
m = 0
n = 0
grp = []

def canGo(x, y):
    if x < 0 or x >= m or y < 0 or y >= n:
        return False
    return True

def dfs(ux, uy, id, vs):
    if grp[ux][uy] != ans[id]:
        return False

    if grp[ux][uy] == ans[9] and id >= 9:
        return True

    vs[ux][uy] = True
    for x, y in dirt:
        vx, vy = ux + x, uy + y

        if canGo(vx, vy) and vs[vx][vy] == False and dfs(vx, vy, id + 1, vs):
            return True
    vs[ux][uy] = False

    return False  

def solve():
    for i in range(m):
        for j in range(n):
            if grp[i][j] == 'A':
                vs = [[False]*(n + 5) for k in range(m + 5)]
                
                if dfs(i, j, 0, vs):
                    print('YES')
                    return
    
    print('NO')

if __name__ == '__main__':
    #FILE_IO()
    tc = int(input())

    for _ in range(tc):
        if _ > 0:
            input()

        m, n = map(int, input().split())
        grp = [list(input()) for i in range(m)]
        solve()