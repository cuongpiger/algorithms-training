#https://www.codechef.com/problems/RRATING
'''
Comment
'''
import heapq

if __name__ == "__main__":
    n = int(input())
    noReviews = 0
    minHeap = []
    maxHeap = []

    for _ in range(n):
        line = list(map(int, input().split()))

        if line[0] == 1:
            noReviews += 1

            if len(minHeap) != 0 and minHeap[0] < line[1]:
                heapq.heappush(minHeap, line[1])
                heapq.heappush(maxHeap, -heapq.heappop(minHeap))
            else:
                heapq.heappush(maxHeap, -line[1])

            if noReviews % 3 == 0:
                heapq.heappush(minHeap, -heapq.heappop(maxHeap))
        else:
            if len(minHeap) == 0:
                print("No reviews yet")
            else:
                print(minHeap[0])