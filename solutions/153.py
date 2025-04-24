from collections import defaultdict

class Solution:
    def countLargestGroup(self, n: int) -> int:
        bucket = defaultdict(int)
        for i in range(1, n + 1):
            key = sum([int(x) for x in str(i)])
            bucket[key] += 1

        maxValue = max(bucket.values())
        count = sum(1 for v in bucket.values() if v == maxValue)
        return count