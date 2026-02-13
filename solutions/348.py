class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        return [[1 - pxl for pxl in row[::-1]] for row in image]
