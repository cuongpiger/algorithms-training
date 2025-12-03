import math as mymath

class Solution:
    def isPowerOfTwo(self, n: int) -> bool: 
        if n < 1:
            return False
            
        x = int(mymath.log2(n))
        return int(2**x) == n
