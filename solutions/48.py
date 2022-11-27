import sys
from queue import PriorityQueue


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

def solve():
    n = int(input())
    pq = PriorityQueue()
    values = list(map(int, input().split()))
    for x in values:
        pq.put(-x)        
    
        if pq.qsize() > 2:
            a, b, c = -pq.get(), -pq.get(), -pq.get()
            pq.put(-a)
            pq.put(-b)
            pq.put(-c)
            print(a*b*c)
        else:
            print(-1) 
        
# FILE_IO()
solve()