class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        if numRows == 0:
            return ""

        segments = ["" for _ in range(numRows)]
        cur_row = 0
        direct = 1

        for ch in s:
            segments[cur_row] += ch

            if cur_row == 0:
                direct = 1
            elif cur_row == numRows - 1:
                direct = -1

            cur_row += direct

        return "".join(segments)     
