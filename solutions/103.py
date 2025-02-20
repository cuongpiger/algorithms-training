def solve(bin_str_set: set, prefix_str: str, depth: int, size: int):
    print(f"{depth} - {prefix_str}")
    if depth >= size:
        if prefix_str not in bin_str_set:
            return prefix_str
        else:
            return ""

    for digit in (0, 1):
        new_prefix = f"{prefix_str}{digit}"
        res = solve(bin_str_set, new_prefix, depth + 1, size)
        if res != "":
            return res

    return ""
        

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        bin_str_set = set(nums)
        res = solve(bin_str_set, "", 0, len(nums))
        return res