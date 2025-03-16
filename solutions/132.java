import java.util.*;

class Solution {
    public long repairCars(int[] ranks, int cars) {
        // The minimum possible time is 1,
        // and the maximum possible time is when the slowest mechanic (highest rank)
        // repairs all cars.
        long low = 1, high = 1L * Arrays.stream(ranks).min().getAsInt() * cars * cars;;

        // Perform binary search to find the minimum time required.
        while (low < high) {
            long mid = (low + high) / 2, carsRepaired = 0;

            // Calculate the number of cars that can be repaired in 'mid' time by all
            // mechanics.
            for (int rank : ranks)
                carsRepaired += (long) (Math.sqrt((1.0 * mid) / rank));

            // If the total cars repaired is less than required, increase the time.
            if (carsRepaired < cars)
                low = mid + 1;
            else
                high = mid; // Otherwise, try a smaller time.
        }

        return low;
    }
}