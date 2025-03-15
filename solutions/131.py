class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        left, right = 1, max(nums)
        res = 0

        while left < right:
            mid = left + (right - left) // 2
            possible_houses = 0

            idx = 0
            while idx < len(nums):
                if nums[idx] <= mid:
                    possible_houses += 1
                    idx += 2
                else:
                    idx += 1
                    
            if possible_houses >= k:
                right = mid
            else:
                left = mid + 1

        return left
