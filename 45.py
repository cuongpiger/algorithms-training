import queue
import sys
from queue import Queue


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def get_input():
    n, m = map(int, input().strip().split())
    cave = []
    for i in range(n):
        cave.append(list(input().strip()))

    sn, sm = map(int, input().strip().split())
    dn, dm = map(int, input().strip().split())

    return n, m, cave, sn - 1, sm - 1, dn - 1, dm - 1


DIRECTIONS = ((0, 1), (0, -1), (1, 0), (-1, 0))


def bfs(n, m, cave, sn, sm, dn, dm):
    queue = Queue()
    queue.put((sn, sm))

    while not queue.empty():
        ux, uy = queue.get()

        for x, y in DIRECTIONS:
            vx, vy = ux + x, uy + y
            if 0 <= vx < n and 0 <= vy < m:
                if cave[vx][vy] == '.':
                    queue.put((vx, vy))
                    cave[vx][vy] = 'X'
                elif vx == dn and vy == dm:
                    return 'YES'

    return 'NO'


def solve():
    n, m, cave, sn, sm, dn, dm = get_input()
    print(bfs(n, m, cave, sn, sm, dn, dm))


# FILE_IO()
solve()
