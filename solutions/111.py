class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 1e9 + 7
        n = len(arr)

        # Convert elements to 0 (even) or 1 (odd)
        for i in range(n):
            arr[i] = arr[i] % 2

        dp_even, dp_odd = [0] * n, [0] * n
        if arr[-1] == 0:
            dp_even[-1] = 1
        else:
            dp_odd[-1] = 1

        for num in range(n - 2, -1, -1):
            if arr[num] == 1:
                dp_odd[num] = (1 + dp_even[num + 1]) % MOD
                dp_even[num] = dp_odd[num + 1]
            else:
                dp_even[num] = (1 + dp_even[num + 1]) % MOD
                dp_odd[num] = dp_odd[num + 1]
            
        count = 0
        for odd_count in dp_odd:
            count += odd_count
            count %= MOD

        return int(count)