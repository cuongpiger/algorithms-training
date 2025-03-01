func applyOperations(nums []int) []int {
    res := []int{}

    for i := 0; i < len(nums) - 1; i++ {
        if nums[i] != 0 {
            if nums[i] == nums[i + 1] {
                nums[i] *= 2
                nums[i + 1] = 0
            }

            res = append(res, nums[i])
        }
    }

    if nums[len(nums) - 1] != 0 {
        res = append(res, nums[len(nums) - 1])
    }

    for len(res) < len(nums) {
        res = append(res, 0)
    }

    return res
}