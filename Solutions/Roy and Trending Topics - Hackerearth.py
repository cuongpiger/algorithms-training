#https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/description/
'''
Comment
'''

import queue

class Node:
    def __init__(seft, _id, _score, _newScore):
        seft.id = _id
        seft.score = _score
        seft.newScore = _newScore;

    def __lt__(seft, other):
        if seft.score == other.score:
            return seft.id > other.id
        else:
            return seft.score > other.score

if __name__ == "__main__":
    n = int(input())
    maxHeap = queue.PriorityQueue()

    for i in range(n):
        id, oldScr, post, like, cmt, shr = map(int, input().split())
        newScr = post*50 + like*5 + cmt*10 + shr*20
        maxHeap.put(Node(id, newScr - oldScr, newScr));

    for i in range(5):
        if maxHeap.empty():
            exit(0)

        print(maxHeap.queue[0].id, maxHeap.queue[0].newScore)
        maxHeap.get()