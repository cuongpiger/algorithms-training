import queue

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        pq = queue.PriorityQueue()
        for num in nums:
            pq.put(num)

        res = 0
        while pq.qsize() > 1:
            first_num = pq.get()
            second_num = pq.get()

            if first_num >= k:
                break

            new_value = min(first_num, second_num) * 2 + max(first_num, second_num)
            pq.put(new_value)
            res += 1

        return res