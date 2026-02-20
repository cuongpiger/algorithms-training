class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        # try largest sides first
        for i in range(len(nums) - 1, 1, -1):
            a, b, c = nums[i-2], nums[i-1], nums[i]
            if a + b > c:
                return a + b + c
        return 0
