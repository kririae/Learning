package main

import "fmt"

func main() {
	for i := 1; i < 40; i++ {
		fmt.Println(i)
	}
	var a int = 100
	switch a {
	case 1:
		fmt.Println(a)
	case 2:
		fmt.Println(a)
	default:
		fmt.Println("not 1 or 2")
	}
}
