def isPunishmentNumber(i: int, number: int, previous_number: int):
    str_number = str(number)
    for j in range(1, len(str_number)):
        left = int(str_number[:j])
        right = int(str_number[j:])

        if left <= i and isPunishmentNumber(i, right, previous_number + left):
            return True

    return number + previous_number == i

class Solution:
    def punishmentNumber(self, n: int) -> int:
        res = 0
        for i in range(1, n + 1):
            if isPunishmentNumber(i, i**2, 0):
                res += i**2

        return res