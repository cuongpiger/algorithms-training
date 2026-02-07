class Solution:
    ord_a = ord("a")

    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        total_lines = 1
        total_pixel_last_line = 0
        current_cost = 0

        for ch in s:
            pixels = widths[self.ord_idx(ch)]
            current_cost += pixels

            if current_cost > 100:
                total_lines += 1
                current_cost = pixels

            total_pixel_last_line = current_cost

        return [total_lines, total_pixel_last_line]

    def ord_idx(self, ch) -> int:
        return ord(ch) - self.ord_a
