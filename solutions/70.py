class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        res = nums[0]
        min_distance = abs(nums[0])

        for val in nums[1:]:
            abs_distance = abs(val - 0)
            if abs_distance == min_distance:
                res = max(res, val)
            elif abs_distance < min_distance:
                min_distance = abs_distance
                res = val
        
        return res
