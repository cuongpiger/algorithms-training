class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        i = len(num) - 1
        carry = k
        res = []

        while i >= 0 or carry > 0:
            if i >= 0:
                carry += num[i]
                i -= 1
            res.append(carry % 10)
            carry //= 10

        # if any digits left in num (when k becomes 0 early)
        while i >= 0:
            res.append(num[i])
            i -= 1

        return res[::-1]
