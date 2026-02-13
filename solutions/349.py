class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1a, y1a, x2a, y2a = rec1
        x1b, y1b, x2b, y2b = rec2

        if x2a <= x1b or x2b <= x1a or y2a <= y1b or y2b <= y1a:
            return False

        return True
