class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        res = 0
        diff_count = {}

        for i in range(len(nums)):
            diff = i - nums[i]
            good_pairs_cnt = diff_count.get(diff, 0)
            res += i - good_pairs_cnt
            diff_count[diff] = good_pairs_cnt + 1

        return res