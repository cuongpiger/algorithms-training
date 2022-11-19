package main

import (
	"fmt"
	// "os"
	"sort"
)

var DIRECTION = [4]pair{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

type pair struct {
	x, y int
}

type Lake struct {
	size int
	N int
	M int
	ocean bool
	cells []*pair
}

func newLake(N, M int) *Lake {
	return &Lake{0, N, M, false, make([]*pair, 0)}
}

func (s *Lake) addCell(p *pair) {
	s.cells = append(s.cells, p)
	s.size = len(s.cells)
	s.checkOcean(p)
}

func (s *Lake) checkOcean(p *pair) {
	if p.x <= 0 || p.y <= 0 || p.x >= s.N - 1 || p.y >= s.M - 1 {
		s.ocean = true
	}
}

func getInput() (int, int, int, *[][]rune) {
	var N, M, K int
	var graph [][]rune
	var row string
	
	fmt.Scanf("%d %d %d\n", &N, &M, &K)

	for i := 0; i < N; i++ {
		fmt.Scanf("%s\n", &row)
		graph = append(graph, []rune(row))
	}

	return N, M, K, &graph
}

func nextStep(graph *[][]rune, N, M int, p *pair, d *pair) (*pair, bool) {
	i, j := p.x + d.x, p.y + d.y
	if i < 0 || j < 0 || i >= N || j >= M {
		return nil, false
	}

	if (*graph)[i][j] == '*' {
		return nil, false
	}

	return &pair{i, j}, true
}

func bfs(N, M, K int, graph *[][]rune) []*Lake {
	res := make([]*Lake, 0)
	queue := make([]*pair, 0)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			if (*graph)[i][j] == '*' {
				continue
			}

			lake := newLake(N, M)
			queue = append(queue, &pair{i, j})
			for len(queue) > 0 {
				top := queue[0]
				queue = queue[1:]
				lake.addCell(top)
				(*graph)[top.x][top.y] = '*'
				for _, d := range DIRECTION {
					ns, ok := nextStep(graph, N, M, top, &d)
					if !ok {
						continue
					}

					queue = append(queue, ns)
				}
			}

			if !lake.ocean {
				res = append(res, lake)
			}
		}
	}

	sort.Slice(res, func(i, j int) bool {
		return res[i].size < res[j].size
	})

	return res
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
	N, M, K, graph := getInput()
	oG := make([][]rune, N)
	for i := 0; i < N; i++ {
		oG[i] = make([]rune, M)
		copy(oG[i], (*graph)[i])
	}

	lakes := bfs(N, M, K, graph)
	lakes = lakes[:len(lakes)-K]

	sm := 0
	for _, lake := range lakes {
		sm += lake.size
		for _, cell := range lake.cells {
			oG[cell.x][cell.y] = '*'
		}
	}
	fmt.Println(sm)
	g := ""
	for _, row := range oG {
		g += string(row) + "\n"
	}
	fmt.Print(g)
}
