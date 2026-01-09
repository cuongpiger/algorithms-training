class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        largest_num = 0
        second_num = 1
        res = 0

        for i in range(len(nums)):
            if nums[i] > largest_num:
                second_num = largest_num
                largest_num = nums[i]
                res = i
            elif nums[i] > second_num:
                second_num = nums[i]

        if second_num == 0 or largest_num / second_num >= 2:
            return res

        return -1
