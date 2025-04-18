class Solution:
    def countAndSay(self, n: int) -> str:
        return self.solve("1", 1, n)

    def solve(self, rle: str, depth: int, n: int):
        if depth >= n:
            return rle

        i, j = 0, 0
        new_rle = ""
        while j < len(rle):
            if rle[i] == rle[j]:
                j += 1
            else:
                new_rle = f"{new_rle}{j - i}{rle[i]}"
                i = j

        new_rle = f"{new_rle}{j - i}{rle[i]}"
        return self.solve(new_rle, depth + 1, n)