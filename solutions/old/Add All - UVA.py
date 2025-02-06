#https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895
'''
Comment
'''

import sys
from queue import PriorityQueue

if __name__ == "__main__":
    while True:
        q = PriorityQueue()
        sum = 0
        
        n = int(sys.stdin.readline())
        line = sys.stdin.readline().strip().split()
        a = [int(vlu) for vlu in line]

        for vlu in a:
            q.put(vlu)

        if (n == 0):
            break
        
        while q.qsize() > 1:
            tmp1 = q.get()
            tmp2 = q.get()
            sum += (tmp1 + tmp2)
            q.put(tmp1 + tmp2)

        print(sum)
