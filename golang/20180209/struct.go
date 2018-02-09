package main

import "fmt"

func main() {
	var son [2]int
	son[0] = 1
	son[1] = 2
	fmt.Println(son)
	const maxn int = 1e5
	var edges [2]Edge
}

type Edge struct {
	son [2]int
}