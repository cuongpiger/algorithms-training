class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        n = len(candyType)
        noCandyType = len(set(candyType))

        return noCandyType if noCandyType <= n // 2 else n // 2
