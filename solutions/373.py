class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        delete = 0

        for i in range(len(strs[0])):
            s = "".join(strs[j][i] for j in range(len(strs))) + 'z'
            for k in range(len(s) - 1):
                if s[k] > s[k+1]:
                    delete += 1
                    break

        return delete
