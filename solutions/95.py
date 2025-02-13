class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        cache = {}
        res = -1
        for i, num in enumerate(nums):
            sum_digits = sum([int(v) for v in str(num)])
            value = cache.get(sum_digits, [])
            cache[sum_digits] = sorted(value + [num])
            if len(cache[sum_digits]) > 1:
                res = max(res, cache[sum_digits][-1] + cache[sum_digits][-2])
        
        return res