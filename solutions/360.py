class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        increase = True
        decrease = True

        for i in range(1, len(nums)):
            if not (increase and nums[i] >= nums[i-1]):
                increase = False
            
            if not (decrease and nums[i] <= nums[i-1]):
                decrease = False

        return increase or decrease
