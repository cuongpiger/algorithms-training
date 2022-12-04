import heapq
import sys


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    N = int(input())
    no_reviews = 0
    min_heap = []
    max_heap = []
    
    for _ in range(N):
        line = input()
        
        if line[0] == "1":
            x = int(line[2:])
            no_reviews += 1
            
            if len(min_heap) != 0 and min_heap[0] < x:
                heapq.heappush(min_heap, x)
                heapq.heappush(max_heap, -heapq.heappop(min_heap))
            else:
                heapq.heappush(max_heap, -x)
            
            if no_reviews % 3 == 0:
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
                
        else:
            if len(min_heap) == 0:
                print("No reviews yet")
            else:
                print(min_heap[0])
            
    
# FILE_IO()
solve()