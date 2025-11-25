class Solution:
    def addBinary(self, a: str, b: str) -> str:
        len_a = len(a)
        len_b = len(b)

        res = ""
        leftover = 0

        for i in range(max(len_a, len_b)):
            val_a = 0 if i >= len_a else int(a[-(i + 1)] == "1")
            val_b = 0 if i >= len_b else int(b[-(i + 1)] == "1")
            sm = val_a + val_b + leftover
            
            if sm == 0:
                res = f"0{res}"
            elif sm == 1:
                res = f"1{res}"
                leftover = 0
            elif sm == 2:
                res = f"0{res}"
                leftover = 1
            else:
                res = f"1{res}"
                leftover = 1

        if leftover > 0:
            res = f"1{res}"

        return res
