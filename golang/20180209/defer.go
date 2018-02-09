package main

import "fmt"

func main() {
	// var a, b int
	// fmt.Scanf("%d %d", &a, &b)
	// fmt.Println(a + b)
	// fmt.Println(ret(10, 10))
	// fmt.Println(save(1, 0))
	// fmt.Println(save(3, 0))

	dempanic()
}

func save(a, b int) int {
	// defer func() {
	// 	if recover() != nil {
	// 		fmt.Println("error happens")
	// 	}
	// }()
	solution := a / b
	return solution
}

func dempanic() {
	defer func() {
		fmt.Println(recover())
	}()
	panic("panic")
}
