class Solution {
    public boolean divideArray(int[] nums) {
        int[] cache = new int[510];

        // Count occurrences of each number
        for (int num : nums) {
            cache[num]++;
        }

        // Check if all counts are even
        for (int v : cache) {
            if (v % 2 != 0) {
                return false;
            }
        }

        return true;
    }
}