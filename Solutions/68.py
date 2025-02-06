class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()

        i = 0
        j = len(nums) // 2
        res = 0

        while True:
            if i >= len(nums) // 2 or j >= len(nums):
                break

            if nums[i] * 2 <= nums[j]:
                res = res + 2
                i = i + 1
                j = j + 1
            else:
                j = j + 1

        return res
