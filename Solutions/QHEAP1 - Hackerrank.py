#https://www.hackerrank.com/challenges/qheap1/problem
'''
Comment
'''

import queue

if __name__ == "__main__":
    n = int(input())
    trash = queue.PriorityQueue()
    heap = queue.PriorityQueue()

    for i in range(n):
        qry = list(map(int, input().split()))

        if qry[0] == 1:
            heap.put(qry[1])
        elif qry[0] == 2:
            trash.put(qry[1])
        else:
            while heap.qsize() and trash.qsize() and heap.queue[0] == trash.queue[0]:
                heap.get()
                trash.get()
            
            print(heap.queue[0])