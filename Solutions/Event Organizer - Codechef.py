'''
https://www.codechef.com/problems/MAXCOMP
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

def floyWarshall():
    for k in range(50):
        for i in range(50):
            for j in range(50):
                if i <= k <= j and dist[i][j] < dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

n = 0
dist = []

#__main__
#FILE_IO()
tc = int(input())

while tc > 0:
    tc -= 1

    n = int(input())
    dist = [[0 for j in range(50)] for i in range(50)]

    for i in range(n):
        s, e, c = map(int, input().split())

        if c > dist[s][e]:
            dist[s][e] = c

    floyWarshall();
    print(dist[0][48])