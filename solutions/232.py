class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        if min(nums) > 0:
            return 0

        max_val = max(nums)
        res = sum([x for x in range(max_val + 1)]) - sum(nums)
        
        return res if res > 0 else max_val + 1
