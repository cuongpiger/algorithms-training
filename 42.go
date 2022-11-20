package main

import (
	"fmt"
	"os"
)

func dfs(G [][]int, V []bool, s int, cnt int) int {
	V[s] = true
	cnt += 1
	for _, v := range G[s] {
		if !V[v] {
			cnt = dfs(G, V, v, cnt)
		}
	}

	return cnt
}


func main() {
	if true == false {
		// reading from file and write to file
		f, err := os.Open("input.txt")
		if err != nil {
			panic(err)
		}
		defer f.Close()
		oldStdin := os.Stdin
		defer func() { os.Stdin = oldStdin }()
		os.Stdin = f

		f2, err := os.Create("output.txt")
		if err != nil {
			panic(err)
		}
		defer f2.Close()
		oldStdout := os.Stdout
		defer func() { os.Stdout = oldStdout }()
		os.Stdout = f2
		// ending reading from file
	}


	// MAIN LOGIC
	var N, M, u, v int
	fmt.Scan(&N, &M)

	G := make([][]int, N)
	for i := 0; i < M; i++ {
		fmt.Scan(&u, &v)
		u -= 1
		v -= 1
		G[u] = append(G[u], v)
	}

	cnt := 0
	for i := 0; i < N; i++ {
		V := make([]bool, N)
		tCnt := dfs(G, V, i, 0)
		if tCnt > cnt {
			cnt = tCnt
		}
	}

	fmt.Println(cnt)
}
