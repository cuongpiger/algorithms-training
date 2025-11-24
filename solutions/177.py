from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i, j = 0, len(nums) - 1
        k = 0
        while i <= j:
            if nums[j] == val:
                j -= 1
                k += 1
            elif nums[i] == val:
                nums[j], nums[i] = nums[i], nums[j]
                j -= 1
                i += 1
                k += 1
            else:
                i += 1
        
        return len(nums) - k
