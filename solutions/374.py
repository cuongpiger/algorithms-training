class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        def compare(word_a, word_b, alphabet):
            for i in range(min(len(word_a), len(word_b))):
                if alphabet[word_a[i]] < alphabet[word_b[i]]:
                    return 0
                elif alphabet[word_a[i]] > alphabet[word_b[i]]:
                    return 1
            
            return 0 if len(word_a) <= len(word_b) else 1

        alphabet = {ch: i for i, ch in enumerate(order)}
        for i in range(len(words) - 1):
            word_a = words[i]
            word_b = words[i+1]
            if compare(word_a, word_b, alphabet) == 1:
                return False

        return True
