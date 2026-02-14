class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False

        if s == goal:
            # need at least one duplicate char to swap without changing the string
            return len(set(s)) < len(s)

        diff = []
        for i, (a, b) in enumerate(zip(s, goal)):
            if a != b:
                diff.append(i)
                if len(diff) > 2:
                    return False

        if len(diff) != 2:
            return False

        i, j = diff
        return s[i] == goal[j] and s[j] == goal[i]
