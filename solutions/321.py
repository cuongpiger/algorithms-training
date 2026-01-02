class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        ans = len(nums) + 1
        heap = dict()
        max_freq = 0

        for i, x in enumerate(nums):
            val = heap.get(x, None)
            
            if val is None:
                heap[x] = (1, i)
            else:
                freq = val[0] + 1
                heap[x] = (freq, val[1])
                if freq > max_freq:
                    max_freq = freq
                    ans = i - val[1] + 1
                elif freq == max_freq:
                    ans = min(ans, i - val[1] + 1)

        return 1 if ans == len(nums) + 1 else ans
