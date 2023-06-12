"""
Time complexity: O(n)

- n: length of nums
"""


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        i, j = 0, 1
        res = []
        if len(nums) == 0:
            return res

        while True:
            if j == len(nums):
                if i == j - 1:
                    res.append(f"{nums[i]}")
                else:
                    res.append(f"{nums[i]}->{nums[j-1]}")
                break

            if nums[j] - nums[i] == j - i:
                j += 1
                continue

            if i == j - 1:
                res.append(f"{nums[i]}")
            else:
                res.append(f"{nums[i]}->{nums[j-1]}")

            i = j
            j += 1

        return res
