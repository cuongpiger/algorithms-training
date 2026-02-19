class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        return [item for item, count in Counter(nums).items() if count == len(nums) // 2][0]
