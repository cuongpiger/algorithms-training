'''
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3252
Comment
'''
import sys
import queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''

#_____main_____
#FILE_IO()

tc = int(input())

while tc > 0:
    tc -= 1

    n, m = map(int, input().split())
    qry = list(map(int, input().split()))
    q = queue.Queue()
    maxHeap = queue.PriorityQueue()
    
    for vl in qry:
        q.put(vl)
        maxHeap.put(-vl)

    cnt = 0
    pos = m

    while True:
        if q.queue[0] == -maxHeap.queue[0]:
            cnt += 1
            q.get()
            maxHeap.get()

            if pos == 0:
                break
        else:
            q.put(q.get())

        pos -= 1
        if pos < 0:
            pos = q.qsize() - 1

    print(cnt)
    
