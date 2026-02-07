import re
from collections import Counter


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = re.findall(r"\w+", paragraph.lower())
        banned_set = set(banned)
        count = Counter(w for w in words if w not in banned_set)

        return count.most_common(1)[0][0]
