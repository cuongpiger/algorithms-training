package main

import (
	"fmt"
	// "os"
)

func dfs(G [][]int, V []bool, s int) {
	V[s] = true
	for _, v := range G[s] {
		if !V[v] {
			dfs(G, V, v)
		}
	}
}


func main() {
	// reading from file and write to file
	// f, err := os.Open("input.txt")
	// if err != nil {
	// 	panic(err)
	// }
	// defer f.Close()
	// oldStdin := os.Stdin
	// defer func() { os.Stdin = oldStdin }()
	// os.Stdin = f

	// f2, err := os.Create("output.txt")
	// if err != nil {
	// 	panic(err)
	// }
	// defer f2.Close()
	// oldStdout := os.Stdout
	// defer func() { os.Stdout = oldStdout }()
	// os.Stdout = f2
	// ending reading from file

	// MAIN LOGIC
	var T int
	fmt.Scanf("%d\n", &T)

	for i := 0; i < T; i++ {
		var N, E, u, v int
		fmt.Scanf("\n%d\n", &N)
		fmt.Scanf("%d\n", &E)
		G := make([][]int, N)
		V := make([]bool, N)
		for i := 0; i < E; i++ {
			fmt.Scanf("%d %d\n", &u, &v)
			G[u] = append(G[u], v)
			G[v] = append(G[v], u)
		}

		var count int
		for i := 0; i < N; i++ {
			if !V[i] {
				dfs(G, V, i)
				count++
			}
		}

		fmt.Println(count)
	}
}
