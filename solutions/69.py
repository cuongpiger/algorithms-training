def replaceVowel(word: str) -> str:
    res = ""
    for chr in word.lower():
        if chr in ("a", "o", "e", "u", "i"):
            res = res + "_"
        else:
            res = res + chr

    return res

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        words = set(wordlist)
        cap = dict()
        vow = dict()

        # Go reverse to get the first word
        for word in wordlist[::-1]:
            # print(word)
            cap[word.lower()] = word

            vowel_word = replaceVowel(word)
            vow[vowel_word] = word


        res = []

        for word in queries:
            if word in words:
                res.append(word)
            else:
                w = cap.get(word.lower(), None)
                if w is not None:
                    # print(f"cap: {word}")
                    res.append(w)
                    continue
                
                w = vow.get(replaceVowel(word), None)
                if w is not None:
                    # print(f"vow: {word}")
                    res.append(w)
                    continue

                res.append("")

        return res