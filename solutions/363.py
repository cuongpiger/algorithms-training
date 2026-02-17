from collections import Counter
from math import gcd
from functools import reduce
from typing import List

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        counts = Counter(deck).values()
        g = reduce(gcd, counts)
        return g >= 2
