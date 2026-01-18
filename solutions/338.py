class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        res = 0
        for x in stones:
            res += int(x in jewels)

        return res
