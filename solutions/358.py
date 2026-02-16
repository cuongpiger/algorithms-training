from typing import List

class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        A = sum(aliceSizes)
        B = sum(bobSizes)
        diff = (B - A) // 2   # guaranteed to be integer given a solution exists

        bob_set = set(bobSizes)
        for x in aliceSizes:
            y = x + diff
            if y in bob_set:
                return [x, y]

