class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        # Sort this `nums` list increasing
        nums.sort()

        final_res = 0

        res = {}

        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                mul_val = nums[i] * nums[j]
                value = res.get(mul_val, 0)
                res[mul_val] = value + 1

        for mul_val, freq in res.items():
            if freq > 1:
                tmp_res = freq * (freq - 1)
                final_res = final_res + tmp_res * 4

        return final_res