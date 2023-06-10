class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        idx = {}
        res = None
        for i in range(len(nums)):
            x = idx.get(nums[i], None)
            if x is None:
                idx[nums[i]] = [i]
            else:
                idx[nums[i]] = x + [i]

        sorted_nums = sorted(nums)
        for nb in sorted_nums:
            sub = target - nb

            x = idx.get(sub, None)
            if x is not None:
                if sub == nb and len(x) == 2:
                    res = x
                    break

                res = [x[0], idx[nb][0]]
                break

        return res