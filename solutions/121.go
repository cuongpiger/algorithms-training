func sieve(n int) []bool {
    prime := make([]bool, n + 1)
    for i := range prime {
        prime[i] = true
    }

    prime[0], prime[1] = false, false
    for p := 2; p*p <= n; p++ {
        if prime[p] {
            for i := p * p; i <= n; i += p {
                prime[i] = false
            }
        }
    }

    return prime
}

func closestPrimes(left int, right int) []int {
    primes := []int{}
    sieveArr := sieve(right)
    
    for num := left; num <= right; num++ {
        if sieveArr[num] {
            primes = append(primes, num)
        }
    }

    res := []int{-1, -1}
    minVal := math.MaxInt32

    for i := 1; i < len(primes); i++ {
        if primes[i] - primes[i - 1] < minVal {
            minVal = primes[i] - primes[i - 1]
            res = []int{primes[i -1], primes[i]}
        }
    }

    return res
}