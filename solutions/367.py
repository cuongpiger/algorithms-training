class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        stats1 = [[name[0], 1]]
        for i in range(1, len(name)):
            if name[i] == name[i-1]:
                stats1[-1][1] += 1
            else:
                stats1.append([name[i], 1])

        stats2 = [[typed[0], 1]]
        for i in range(1, len(typed)):
            if typed[i] == typed[i-1]:
                stats2[-1][1] += 1
            else:
                stats2.append([typed[i], 1])

        if len(stats1) != len(stats2):
            return False

        for x, y in zip(stats1, stats2):
            if x[0] != y[0] or x[1] > y[1]:
                return False

        return True
