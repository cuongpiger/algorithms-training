class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_element = max(nums)
        cnt, i, res = 0, 0, 0

        for j in range(len(nums)):
            cnt += int(nums[j] == max_element)

            while cnt == k:
                if nums[i] == max_element:
                    cnt -= 1
                
                i += 1
            res += i

        return res
