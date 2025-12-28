class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        nf = len(flowerbed)
        for i in range(nf):
            left = i == 0 or flowerbed[i - 1] == 0
            right = i == nf - 1 or flowerbed[i + 1] == 0

            if left and right and flowerbed[i] == 0:
                n -= 1
                flowerbed[i] = 1

        return n <= 0
