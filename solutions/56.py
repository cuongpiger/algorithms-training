"""
Time Complexity: O(N)

- N: Number of characters in s
"""

class Solution:
    def romanToInt(self, s: str) -> int:
        subtraction = {
            "IV": 4,
            "IX": 9,
            "XL": 40,
            "XC": 90,
            "CD": 400,
            "CM": 900,
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
            "Z": 0
        }

        sm = 0
        i = 0
        n = len(s)
        while i < n - 1:
            cb = s[i: i + 2]
            got = subtraction.get(cb, None)
            if got is None:
                i = i + 1
            else:
                sm = sm + got
                s = s[:i] + "ZZ" + s[i + 2:]
                i = i + 2
            
        for ch in s:
            sm = sm + subtraction.get(ch, 0)

        return sm
    