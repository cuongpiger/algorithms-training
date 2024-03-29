#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
'''
Comment
'''
import queue
from sys import stdin

if __name__ == "__main__":
    while True:
        try:
            n = int(input())
        except EOFError:
            break

        stk = queue.LifoQueue() 
        que = queue.Queue()
        prq = queue.PriorityQueue()
        isStack = isQueue = isPrQue = True

        for _ in range(n):
            t, v = map(int, input().split())

            if t == 1:
                stk.put(v)
                que.put(v)
                prq.put(-v)
            else:
                if stk.empty():
                    isStack = isQueue = isPrQue = False
                else:
                    isStack = isStack and (v == stk.get())
                    isQueue = isQueue and (v == que.get())
                    isPrQue = isPrQue and (v == -prq.get())

        if isStack + isQueue + isPrQue == 0:
            print("impossible")
        elif isStack + isQueue + isPrQue > 1:
            print("not sure")
        elif isStack:
            print("stack")
        elif isQueue:
            print("queue")
        else:
            print("priority queue")