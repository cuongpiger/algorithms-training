class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0 for _ in range(n + 1)]

        if n >= 1:
            res[1] = 1
            first_index = 1

            for i in range(2, len(res)):
                if i == first_index * 2:
                    res[i] = 1
                    first_index = i
                else:
                    second_index = i - first_index
                    res[i] = res[first_index] + res[second_index]

        return res
