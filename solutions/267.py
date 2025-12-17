class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        cnt = 0
        i, j = 0, 0
        n = len(nums)

        while i < n and j < n:
            if nums[i] == 0:
                i += 1
                continue

            j = i + 1
            while j < n:
                if nums[j] == 1:
                    j += 1
                else:
                    break

            cnt = max(cnt, j - i)
            i = j

        return cnt
