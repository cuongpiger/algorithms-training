class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"

        res = ""
        map_hex = [f"{x}" for x in range(0, 10)] + [chr(x) for x in range(ord('a'), ord('g'))]
        if num < 0:
            num = (1 << 32) + num

        while num > 0:
            res = f"{map_hex[num % 16]}{res}"
            num //= 16
        
        return res
