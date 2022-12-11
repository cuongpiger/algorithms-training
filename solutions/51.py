from queue import PriorityQueue
import sys


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    N = int(input())
    pq = PriorityQueue()
    S = [0, 1, 50, 5, 10, 20]
    for _ in range(N):
        line = list(map(int, input().split()))
        ix = line[0]
        score = sum([S[i] * line[i] for i in range(2, 6)])
        diff = score - line[1]
        pq.put((-diff, -ix, score))
        
    for _ in range(min(5, N)):
        t = pq.get()
        print(f"{-t[1]} {t[2]}")
        
                
# FILE_IO()
solve()