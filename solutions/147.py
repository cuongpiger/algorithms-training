class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums = sorted(nums)
        
        dp = [1] * len(nums)
        prev = [-1] * len(nums)
        maxi = 0

        for i in range(0, len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    prev[i] = j

            if dp[i] > dp[maxi]:
                maxi = i

        res = []
        i = maxi
        while i > -1:
            res.append(nums[i])
            i = prev[i]

        return res