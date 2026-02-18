class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0]*n
        cur_odd,cur_even = 0,1
        for num in nums:
            if num%2:
                ans[cur_even] = num
                cur_even += 2
            else:
                ans[cur_odd] = num
                cur_odd += 2
        return ans
