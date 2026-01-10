class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        digits = [0 for _ in range(26)]
        for x in licensePlate.lower():
            if x not in "1234567890 ":
                digits[ord(x) - ord('a')] += 1

        res = "aaaaaaaaaaaaaaaaaaaa"
        cnt = sum(digits)
        for word in words:
            c = 0
            digits_clone = [x for x in digits]
            for x in word.lower():
                if x not in "1234567890 " and digits_clone[ord(x) - ord('a')] > 0:
                    c += 1
                    digits_clone[ord(x) - ord('a')] -= 1

                if c >= cnt:
                    break

            if c >= cnt and len(word) < len(res):
                res = word

        return res

