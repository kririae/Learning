package main

import "fmt"

// The same as cpp

func main() {
	const (
		A = 1
		B = 2
		C = 3
	)
	var (
		a = 1
		b = 2
		c = 3
	)
	fmt.Println(A, B, C)
	fmt.Println(a, b, c)

	const (
		x = iota
		y
		z
	)
	fmt.Println(x, y, z)
}
