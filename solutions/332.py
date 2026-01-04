class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        left, right = 0, len(letters) - 1
        ans = 0

        while left <= right:
            mid = left + (right - left) // 2
            if letters[mid] > target:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return letters[ans]
