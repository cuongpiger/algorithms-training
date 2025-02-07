# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

def cacheCheck(mid: int, cache: dict) -> bool:
    got = cache.get(mid, None)
    if got is None:
        got = isBadVersion(mid)
        cache[mid] = got

    return got

def binSearch(left: int, right: int, cache: dict) -> int:
    if left <= right:
        mid = left + (right - left) // 2
        print(f"l: {left}, r: {right}, m: {mid}")
        if ((mid == left) or not cacheCheck(mid - 1, cache)) and cacheCheck(mid, cache):
            return mid
        elif not cacheCheck(mid, cache):
            return binSearch(mid + 1, right, cache)
        else:
            return binSearch(left, mid - 1, cache)

    return -1

class Solution:
    def firstBadVersion(self, n: int) -> int:
        c = dict()
        return binSearch(1, n, c)