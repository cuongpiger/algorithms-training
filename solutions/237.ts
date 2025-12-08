class NumArray {
    private sumNums: number[];

    constructor(nums: number[]) {
        this.sumNums = new Array(nums.length + 1).fill(0);
        for (let i = 1; i <= nums.length; i++) {
            this.sumNums[i] = this.sumNums[i - 1] + nums[i - 1];
        }
    }

    sumRange(left: number, right: number): number {
        return this.sumNums[right + 1] - this.sumNums[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */
