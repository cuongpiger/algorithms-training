class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        highestSeen = 0
        highestDiff = 0
        ans = 0
        for num in nums:
            if highestDiff * num > ans:
                ans = highestDiff * num
            if highestSeen - num > highestDiff:
                highestDiff = highestSeen - num
            if num > highestSeen:
                highestSeen = num
        return ans
