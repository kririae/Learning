package main

import "fmt"

func main() {
	num := 3
	doublenum := func() int {
		num *= 2
		return num
	}
	fmt.Println(doublenum())
	fmt.Println(doublenum())

	fmt.Println(fact(1000))
	var a = true
	fmt.Printf("%T \n", a)
	// fmt.Println(type a)
}

func fact(num int) int {
	if num == 1 {
		return 2
	}
	return num * fact(num - 1)
}
