class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        first_map = defaultdict(int)
        second_map = defaultdict(int)
        n = len(nums)

        # Add all elements of nums to second_map
        for num in nums:
            second_map[num] += 1

        for index in range(n):
            # Create split at current index
            num = nums[index]
            second_map[num] -= 1
            first_map[num] += 1

            # Check if valid split
            if (
                first_map[num] * 2 > index + 1
                and second_map[num] * 2 > n - index - 1
            ):
                return index

        # No valid split exists
        return -1