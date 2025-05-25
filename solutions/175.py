class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        words_dict = {}

        for w in words:
            words_dict[w] = words_dict.get(w, 0) + 1

        res = 0
        double_digit = 0
        for k, v in words_dict.items():
            if k == k[::-1]:
                if v % 2 == 0:
                    res += 2*v
                else:
                    double_digit = 2
                    if v > 1:
                        res += 2*(v - 1)
            else:
                reverve_v = words_dict.get(k[::-1], 0)
                if reverve_v > 0:
                    res += min(v, reverve_v) * 4
                    words_dict[k] = 0
                    words_dict[k[::-1]] = 0

        return res + double_digit
