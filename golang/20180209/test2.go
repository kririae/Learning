package main

import "fmt"

func main() {
	x := 0
	changexval(&x)
	fmt.Println(x)
	fmt.Println(&x)

	ptr := new(int)
	changeptr(ptr)
	fmt.Println(*ptr)
}

func changexval(x *int) {
	(*x) = 2
}

func changeptr(ptr *int) {
	*ptr = 100
}