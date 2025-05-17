class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        freq = [0, 0, 0]
        for x in nums:
            freq[x] += 1

        cnt = 0
        for x in range(3):
            nums[cnt:cnt + freq[x]] = [x for _ in range(freq[x])]
            cnt += freq[x]
            