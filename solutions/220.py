class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        loc = {}
        for i in range(len(nums)):
            if nums[i] in loc and i - loc[nums[i]] <=k:
                return True

            loc[nums[i]] = i
            
        return False
