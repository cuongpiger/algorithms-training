func isPowerOfThree(n int) bool {
    if n <= 0 {
        return false
    }

    if n == 1 {
        return true
    }

    return 1162261467 % n == 0
}
