class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        sum_subarray = sum(nums[:3])
        result = int((sum_subarray - nums[1]) * 2 == nums[1])

        for i in range(2, len(nums) - 1):
            sum_subarray -= nums[i - 2]
            sum_subarray += nums[i + 1]
            result += int((sum_subarray - nums[i]) * 2 == nums[i])

        return result
        