MOD = 10**9 + 7

def fast_exponentiation(value: int, power_of: int, modulo: int = MOD) -> int:
    res, mul = 1, value
    while power_of > 0:
        if power_of % 2 == 1:
            res = res * mul % modulo
        
        mul = mul**2 % modulo
        power_of //= 2

    return res

class Solution:
    def countGoodNumbers(self, n: int) -> int:
        even_positions = fast_exponentiation(5, (n + 1) // 2)
        odd_positions = fast_exponentiation(4, n // 2)
        return even_positions * odd_positions % MOD