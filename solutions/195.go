func maxProfit(prices []int) int {
    floor := prices[0]
    roof := prices[0]
    profit := 0

    for i := 1; i < len(prices); i++ {
        if prices[i] < floor {
            floor = prices[i]
            roof = prices[i]
        } else if prices[i] > roof {
            roof = prices[i]
            
            if roof - floor > profit {
                profit = roof - floor
            }
        }
    }

    return profit
}
