package main

import "fmt"

func main() {
	// define a slice
	// var identifier []type
	// var slice1 []int = make([]int, 233)
	// =>
	slice1 := make([]int, 5)
	fmt.Println(slice1)

	sl := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	fmt.Println(sl)
	var s, t int = 0, 5
	fmt.Println(sl[s:t]) // s -> t - 1 index
	sl = append(sl, 233, 2333, 23333, 233333)
	fmt.Println(sl)
	fmt.Println(len(sl))
}
