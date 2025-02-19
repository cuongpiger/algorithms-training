import queue

def solve(depth: int, n: int, k: int, prefix_str: str, min_heap: queue.PriorityQueue):
    if min_heap.qsize() >= k:
        return
    
    if depth >= n:
        min_heap.put(prefix_str)
        return

    for c in "abc":
        if prefix_str == "":
            solve(depth + 1, n, k, c, min_heap)
        elif c != prefix_str[-1]:
            new_prefix_str = f"{prefix_str}{c}"
            solve(depth + 1, n, k, new_prefix_str, min_heap)



class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        res = ""
        min_heap = queue.PriorityQueue()
        solve(0, n, k, "", min_heap)

        for i in range(k):
            if min_heap.qsize() > 0:
                res = min_heap.get()
            else:
                res = ""

        return res
