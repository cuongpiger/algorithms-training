class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sm: int = 0
        for i in range(1, len(prices)):
            sm += max(0, prices[i] - prices[i - 1])

        return sm
    