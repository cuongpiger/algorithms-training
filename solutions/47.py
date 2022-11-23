import sys
from queue import Queue, PriorityQueue, LifoQueue


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    stack = LifoQueue()
    queue = Queue()
    pqueue = PriorityQueue()
    
    while (True):
        try:
            n = int(input())
        except EOFError:
            break
        
        stack.queue.clear()
        queue.queue.clear()
        pqueue.queue.clear()
        isStack, isQueue, isPQueue = 1, 1, 1
        
        for _ in range(n):
            a, b = map(int, input().split())
            if a == 1:
                stack.put(b)
                queue.put(b)
                pqueue.put(-b)
            else:
                if queue.empty():
                    isStack, isQueue, isPQueue = 0, 0, 0
                else:
                    xstack = stack.get()
                    xqueue = queue.get()
                    xpqueue = -pqueue.get()
                
                    if xstack != b:
                        isStack = 0
                    if xqueue != b:
                        isQueue = 0
                    if xpqueue != b:
                        isPQueue = 0
                    
        if isStack + isQueue + isPQueue == 0:
            print('impossible')
        elif isStack + isQueue + isPQueue > 1:
            print('not sure')
        elif isStack:
            print('stack')
        elif isQueue:
            print('queue')
        elif isPQueue:
            print('priority queue')
            

# FILE_IO()
solve()
    
    