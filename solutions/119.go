func coloredCells(n int) int64 {
    tmp := int64(n*2 - 1)
    res := tmp
    tmp -= 2

    for tmp >= 1 {
        res += tmp * 2
        tmp -= 2
    }

    return res
}