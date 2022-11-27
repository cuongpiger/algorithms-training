from queue import PriorityQueue
import sys


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    n = int(input())
    pq = PriorityQueue()
    pqr = PriorityQueue()
    
    for _ in range(n):
        line = input()
        
        if line[0] == '1':
            x = int(line.split()[1])
            pq.put(x)
        elif line[0] == '2':
            x = int(line.split()[1])
            pqr.put(x)
        else:
            while not pqr.empty() and pq.queue[0] == pqr.queue[0]:
                pq.get()
                pqr.get()
        
            print(pq.queue[0])
                
# FILE_IO()
solve()