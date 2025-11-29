class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        letters = ['Z'] + [chr(i) for i in range(ord('A'), ord('Z'))]
        res = ''

        while columnNumber > 0:
            idx = columnNumber % 26
            columnNumber = columnNumber // 26 
            res = f"{letters[idx]}{res}"

            if idx == 0:
                columnNumber -= 1
        
        return res
