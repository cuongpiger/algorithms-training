from typing import List

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_occurs = [-1] * 26
        for i, ch in enumerate(s):
            last_occurs[ord(ch) - ord('a')] = i

        partition_end = 0
        partition_start = 0
        results: List[int] = []

        for i, ch in enumerate(s):
            partition_end = max(partition_end, last_occurs[ord(ch) - ord('a')])

            if partition_end == i:
                results.append(partition_end - partition_start + 1)
                partition_start = i + 1

        return results
