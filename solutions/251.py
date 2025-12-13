class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        res = []
        for hour in range(12):
            for minute in range(60):
                if (bin(hour) + bin(minute)).count("1") == turnedOn:
                    res.append(f"{hour}:{minute:02d}")

        return res
