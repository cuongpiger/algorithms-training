'''
https://www.spoj.com/problems/PPATH/
Comment
'''
import sys
import queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

primes = [True for _ in range(10005)]

def sievePrimes():
    p = 2

    while p*p <= 10005:
        if primes[p] == True:
            for i in range(p*p, 10005, p):
                primes[i] = False

        p += 1

def bfs(src, des):
    dist = [-1]*10005
    dist[int(src)] = 0
    q = queue.Queue()
    q.put(int(src))

    while not q.empty():
        u = str(q.get())

        if u == des:
            return dist[int(des)]

        for i in range(0, 4):
            for j in range(0, 10):
                v = int(u[:i] + str(j) + u[i + 1:])

                if v > 1000 and primes[v] == True and dist[v] == -1:
                    dist[v] = dist[int(u)] + 1
                    q.put(v)

    return -1        

if __name__ == '__main__':
    #FILE_IO()
    sievePrimes()
    n = int(input())

    for _ in range(n):
        a, b = map(str, input().split())
        res = bfs(a, b)

        if res != -1:
            print(res)
        else:
            print('Impossible')

    