package main

import (
	"fmt"
)

func main() {
	const (
		a = 1 << iota
		b = 2 << iota
		c
		d = iota
		e = "kririae"
		f
		g = iota
	)
	fmt.Println(a, b, c, d, e, f, g)
}
