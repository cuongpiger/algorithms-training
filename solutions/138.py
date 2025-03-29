from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings = sorted(meetings, key=lambda x: (x[0], x[1]))
        print(meetings)
        count = 0
        current_day = 0

        for meeting in meetings:
            if current_day < meeting[0]:
                count += meeting[0] - current_day - 1
                current_day = meeting[1]
            else:
                current_day = max(meeting[1], current_day)

        count += days - current_day

        return count
