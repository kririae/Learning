package main

import (
	"fmt"
)

func main() {
	fmt.Println(addThemUp(1, 2, 3, 4, 5, 6, 7))
}

func addThemUp(arg ...int) int{
	sum := 0
	for _, value := range arg {
		sum += value
	}
	return sum
}