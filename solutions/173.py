def is_triangle(a: int, b: int, c: int) -> bool:
    sm = a + b + c
    for v in (a, b, c):
        if sm - v <= v:
            return False

    return True

class Solution:
    def triangleType(self, nums: List[int]) -> str:
        if nums[0] == nums[1] and nums[1] == nums[2]:
            return "equilateral"
        
        if is_triangle(nums[0], nums[1], nums[2]):
            if nums[0] == nums[1] or nums[1] == nums[2] or nums[0] == nums[2]:
                return "isosceles"
            else:
                return "scalene"

        return "none"
