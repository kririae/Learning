package main

import "fmt"

func main() {
	// common type convert
	var sum int = 17
	var count int = 5

	var mean float64 = float64(sum) / float64(count)
	fmt.Println(mean)
}
