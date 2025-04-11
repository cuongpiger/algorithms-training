class Solution {
    public int minimumOperations(int[] nums) {
        int[] distinctNums = new int[105];
        int index = -1;

        for (int i = nums.length - 1; i >= 0; i--) {
            distinctNums[nums[i]]++;
            if (distinctNums[nums[i]] > 1) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return 0;
        }

        index += 1;
        return (index / 3) + ((index % 3 > 0) ? 1 : 0);
    }
}