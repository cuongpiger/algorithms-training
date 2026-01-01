class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        i = 0
        j = 1
        n = len(nums)
        res = 0

        if n == 1:
            return 1

        while i < n and j < n:
            j = i + 1
            while j < n and nums[j] > nums[j-1]:
                j += 1

            res = max(j - i, res)
            i = j

        return res
