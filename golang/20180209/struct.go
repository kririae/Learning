package main

import "fmt"

func main() {
	var son [2]int
	son[0] = 1
	son[1] = 2
	fmt.Println(son)

}

type Edge struct {
	son [2]int
}

func (edge *Edge) plus int {
	return edge.son[0] + edge.son[1]
}