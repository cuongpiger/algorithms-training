class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        bow = [0 for _ in range(30)]
        for x in magazine:
            idx = ord(x) - ord('a')
            bow[idx] += 1

        for x in ransomNote:
            idx = ord(x) - ord('a')
            bow[idx] -= 1
            if bow[idx] < 0:
                return False

        return True
