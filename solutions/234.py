class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        j = 0
        n = len(nums)

        while i < n:
            if nums[i] != 0:
                i += 1
            else:
                j = max(j, i + 1)
                while j < n and nums[j] == 0:
                    j += 1

                if j >= n:
                    return

                nums[i], nums[j] = nums[j], nums[i]
