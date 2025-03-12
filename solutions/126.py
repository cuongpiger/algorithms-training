class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        negativeSet = list(filter(lambda x: x < 0, nums))
        positiveSet = list(filter(lambda x: x > 0, nums))

        return max(len(negativeSet), len(positiveSet))
