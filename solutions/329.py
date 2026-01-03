class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        left_sum, right_sum = 0, sum(nums)
        for i, x in enumerate(nums):
            right_sum -= x
            
            if left_sum == right_sum:
                return i
            
            left_sum += x

        return -1
