class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine_dict = dict()

        for c in magazine:
            magazine_dict[c] = magazine_dict.get(c, 0) + 1 

        for c in ransomNote:
            if magazine_dict.get(c, 0) == 0:
                return False

            magazine_dict[c] -= 1

        return True
