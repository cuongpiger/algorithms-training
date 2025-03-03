function pivotArray(nums: number[], pivot: number): number[] {
    let lessThanPivot: number[] = [];
    let greaterThanPivot: number[] = [];
    let equalToPivot: number[] = [];

    for (let num of nums) {
        if (num > pivot) {
            greaterThanPivot.push(num);
        } else if (num < pivot) {
            lessThanPivot.push(num);
        } else {
            equalToPivot.push(num);
        }
    }

    return [...lessThanPivot, ...equalToPivot, ...greaterThanPivot];
};