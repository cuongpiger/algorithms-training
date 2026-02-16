class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        freq = Counter((s1 + " " + s2).split())
        return [w for w, c in freq.items() if c == 1]
