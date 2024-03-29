'''
https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1112
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

MAX = 28
INF = 10**9

def FloyWarshall(dist):
    for k in range(MAX):
        for i in range(MAX):
            for j in range(MAX):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

#__main__
#FILE_IO()

while True:
    n = int(input())

    if n == 0:
        break

    grpStudent = [[INF if j != i else 0 for j in range(MAX)] for i in range(MAX)]
    grpProfessor = [[INF if j != i else 0 for j in range(MAX)] for i in range(MAX)]

    for i in range(n):
        t, d, u, v, w = input().split()
        u = ord(u) - 65
        v = ord(v) - 65
        w = int(w)

        if t == 'Y':
            if grpStudent[u][v] > w:
                grpStudent[u][v] = w

                if d == 'B' and grpStudent[v][u] > w:
                    grpStudent[v][u] = w
        else:
            if grpProfessor[u][v] > w:
                grpProfessor[u][v] = w

                if d == 'B' and grpProfessor[v][u] > w:
                    grpProfessor[v][u] = w
        
    lctStudent, lctProfessor = map(lambda x: ord(x) - 65, input().split())

    FloyWarshall(grpProfessor)
    FloyWarshall(grpStudent)
    res = []
        
    for i in range(MAX):
        distStudent = grpStudent[lctStudent][i]
        distProfessor = grpProfessor[lctProfessor][i]

        if distStudent != INF and distProfessor != INF:
            res.append((distStudent + distProfessor, i))

    if len(res) == 0:
        print('You will never meet.')
        continue

    res.sort()
    for i in range(len(res)):
        if i == 0:
            print(res[i][0], end = '')

        if res[i][0] == res[0][0]:
            print(' {}'.format(chr(res[i][1] + 65)), end = '')
    print()
            