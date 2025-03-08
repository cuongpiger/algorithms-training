import (
    "math"
)

func minimumRecolors(blocks string, k int) int {
    numOfBlacks := make([]int, len(blocks) + 1)

    for i := 0; i < len(blocks); i++ {
        isWhite := 0
        if blocks[i] == 'W' {
            isWhite = 1
        }

        numOfBlacks[i + 1] = numOfBlacks[i] + isWhite
    }

    res := math.MaxInt32
    for i := 0; i < len(blocks); i++ {
        rightBoundary := i + k

        if rightBoundary > len(blocks) {
            break
        }

        res = min(res, numOfBlacks[rightBoundary] - numOfBlacks[i])
    }

    if res == math.MaxInt32 {
        return 0
    }

    return res
}

func min(a int, b int) int {
    if a < b {
        return a
    }

    return b
}