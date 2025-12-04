class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)

        if n < 1:
            return []

        nums = nums + [nums[-1] + 10]
        res = []
        i = 0
        for j in range(n):
            if nums[j] + 1 != nums[j + 1]:
                if j == i:
                    res.append(f"{nums[i]}")
                else:
                    res.append(f"{nums[i]}->{nums[j]}")

                i = j + 1

        return res
