class Solution:
    def checkRecord(self, s: str) -> bool:
        cnt_absent = 0
        cnt_late = 0

        for ch in s:
            if ch == 'L':
                cnt_late += 1
            else:
                if cnt_late < 3:
                    cnt_late = 0

                if ch == 'A':
                    cnt_absent += 1

        return cnt_absent < 2 and cnt_late < 3
