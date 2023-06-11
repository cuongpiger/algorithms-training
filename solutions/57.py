"""
Time complexity: O(nlogn)

- n: length of the longest string in strs
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        sorted_strs = sorted(strs)
        first = sorted_strs[0]
        last = sorted_strs[-1]
        res = ""

        for i in range(min(len(first), len(last))):
            if first[i] == last[i]:
                res += first[i]
            else:
                break
        
        return res
    