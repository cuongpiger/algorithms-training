'''
https://www.spoj.com/problems/ARBITRAG/
Comment
'''
import sys
 
def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''
 
cs = 0
n = 0
cost = []
nation = {}
 
def floyWarshall():
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if cost[i][j] < cost[i][k] * cost[k][j]:
                    cost[i][j] = cost[i][k] * cost[k][j]
 
#__main__
#FILE_IO()
 
while True:
    n = int(input())
    cs += 1
 
    if n == 0:
        break
 
    cost = [[0.0 for j in range(n + 5)] for i in range(n + 5)]
    nation.clear()
 
    for i in range(n):
        cost[i][i] = 1.0
        nation[str(input())] = i
 
    m = int(input())
    for i in range(m):
        u, w, v = input().split()
        cost[nation[u]][nation[v]] = float(w)
 
    floyWarshall()
    flag = False;
 
    for i in range(n):
        if cost[i][i] > 1.0:
            flag = True
            break
 
    print('Case {}: {}'.format(cs, 'Yes' if flag else 'No'))
    input() 