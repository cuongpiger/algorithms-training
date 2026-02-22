class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        for i in range(len(nums)):
            if k == 0:
                break

            if nums[i] < 0:
                nums[i] = abs(nums[i])
                k -= 1
            else:
                break

        nums = sorted(nums)
        if k > 0 and k % 2 == 1:
            nums[0] *= -1

        return sum(nums)
