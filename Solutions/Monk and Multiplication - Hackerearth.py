#https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/
'''
Comment
'''

import queue

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    pq = queue.PriorityQueue()

    for vlu in a:
        pq.put(-vlu)

        if pq.qsize() < 3:
            print(-1)
        else:
            first = -pq.get()
            second = -pq.get()
            third = -pq.get()

            print(first*second*third)
            pq.put(-first)
            pq.put(-second)
            pq.put(-third)