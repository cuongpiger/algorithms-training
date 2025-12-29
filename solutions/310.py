class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        sum_conti = [0]
        for x in nums:
            sum_conti.append(x + sum_conti[-1])

        res = -1 * 10**5
        for i in range(k, len(sum_conti)):
            res = max((sum_conti[i] - sum_conti[i - k]) / k, res)

        return res
