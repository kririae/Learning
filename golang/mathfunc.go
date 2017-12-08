package main

import (
	"fmt"
	"math"
)

func add(x int, y int) int {
	return x + y
}

func anotherAdd(x, y int) int {
	return x + y
}

func getSq(x float64) float64 {
	return math.Pi * (x * x)
}

func swap(a, b string) (string, string) {
	return b, a
}

func split(sum int) (x, y, z int) {
	x = sum / 2 - 1
	y = sum / 2 + 1
	z = 0
	return
}

func main() {
	fmt.Println(math.Sqrt(math.Pi))
	fmt.Println(add(233, 233))
	fmt.Println(anotherAdd(233, 233))
	fmt.Println(getSq(15))

	a, b := swap("Alice", "Margatroid")
	fmt.Println(a, b)

	fmt.Println(split(100))
}