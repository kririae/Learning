package main

import "fmt"

func getSequence() (func() int) {
	i := 0
	return func() int {
		i++
		return i
	}
}

func proc(list []int, f func(int) int) {
	for i, value := range list {
		list[i] = f(value)
	}
}

func add1(a int) int {
	return a + 1
}

func main() {
	list := []int {1, 2, 3, 4, 5}
	proc(list, add1)
	for _, value := range list {
		fmt.Println(value)
	}
}
