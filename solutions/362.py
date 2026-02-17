class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        min_val = min(nums)
        max_val = max(nums)

        if (max_val - k) - (min_val + k) >= 0:
             return (max_val - k) - (min_val + k)

        return 0
