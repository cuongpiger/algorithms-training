import sys
from typing import List, Tuple
from queue import PriorityQueue


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

def solve():
    while True:
        n = int(input().strip())
        if n <= 0:
            break
        
        pq = PriorityQueue()
        numbs = list(map(int, input().strip().split()))
        for num in numbs:
            pq.put(num)
            
        cost = 0
        while pq.qsize() > 1:
            c = pq.get() + pq.get()
            cost += c
            pq.put(c)
            
        print(cost)

# FILE_IO()
solve()
