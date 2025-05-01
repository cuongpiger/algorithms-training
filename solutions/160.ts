function countCompleteSubarrays(nums: number[]): number {
    let res = 0;
    let cnt = new Map<number, number>();
    const n = nums.length;
    let right = 0;
    const distinct = new Set(nums).size;

    for (let left = 0; left < n; left++) {
        if (left > 0) {
            const remove = nums[left - 1];
            cnt.set(remove, cnt.get(remove)! - 1);
            if (cnt.get(remove) === 0) {
                cnt.delete(remove);
            }
        }
        while (right < n && cnt.size < distinct) {
            const add = nums[right];
            cnt.set(add, (cnt.get(add) || 0) + 1);
            right++;
        }
        if (cnt.size === distinct) {
            res += n - right + 1;
        }
    }
    return res;
}