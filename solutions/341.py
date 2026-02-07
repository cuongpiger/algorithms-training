class Solution:
    more_code = [
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
    ]
    ord_a = ord("a")

    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        return len(set([self.transform(word) for word in words]))

    def transform(self, word: str) -> str:
        return "".join(self.more_code[ord(w) - self.ord_a] for w in word)
