class Solution:
    def reverseVowels(self, s: str) -> str:
        i, j = 0, len(s) - 1
        digits = [ch for ch in s]
        vowels = ('A', 'O', 'E', 'U', 'I', 'a', 'o', 'e', 'u', 'i')

        while i < j:
            if digits[i] not in vowels:
                i += 1
            else:
                while j > i:
                    if digits[j] not in vowels:
                        j -= 1
                    else:
                        digits[i], digits[j] = digits[j], digits[i]
                        j -= 1
                        i += 1
                        break

        return "".join(digits)
