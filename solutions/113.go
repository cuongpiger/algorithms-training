func lenLongestFibSubseq(arr []int) int {
	n := len(arr)
	maxLen := 0
	// dp[prev][curr] stores length of Fibonacci sequence ending at indexes prev, curr
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}

	// Map each value to its index for O(1) lookup
	valToIdx := make(map[int]int)
	for i, num := range arr {
		valToIdx[num] = i
	}

	// Fill dp array
	for curr := 0; curr < n; curr++ {
		for prev := 0; prev < curr; prev++ {
			diff := arr[curr] - arr[prev]
			prevIdx, exists := valToIdx[diff]

			// Update dp if valid Fibonacci sequence possible
			if exists && diff < arr[prev] {
				dp[prev][curr] = dp[prevIdx][prev] + 1
			} else {
				dp[prev][curr] = 2
			}
			maxLen = max(maxLen, dp[prev][curr])
		}
	}

	// Return 0 if no sequence of length > 2 found
	if maxLen > 2 {
		return maxLen
	}
	return 0
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}