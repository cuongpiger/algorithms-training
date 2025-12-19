from functools import reduce
import operator


class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        keyboard = {}
        for x in "qwertyuiop" + "qwertyuiop".upper():
            keyboard[x] = 1

        for x in "asdfghjkl" + "asdfghjkl".upper():
            keyboard[x] = 2

        for x in "zxcvbnm" + "zxcvbnm".upper():
            keyboard[x] = 4

        res = []
        for word in words:
            val = reduce(operator.and_, [keyboard[x] for x in word])
            if val > 0 and (val & (val - 1)) == 0:
                res.append(word)

        return res
