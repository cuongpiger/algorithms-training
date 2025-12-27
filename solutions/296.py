class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums = sorted(nums)
        i, j, n = 0, 0, len(nums)
        res = 0

        while i < n:
            j = i + 1
            k = -1

            while j < n:
                diff = nums[j] - nums[i]
                if diff > 1:
                    break
                elif diff == 1:
                    if k < 0:
                        k = j
                    res = max(res, j - i + 1)
                
                j += 1
            
            i = j if k == -1 else k

        return res
