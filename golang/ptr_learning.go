package main

import "fmt"

func main() {
	// ptr to a value
	var a int = 20
	var ptr *int = &a

	fmt.Println("The number is", a, "ptr is", ptr)
	*ptr = 23333
	fmt.Println(a)

	// ptr to a array
	// only can it be implemented like this???
	asize := 5
	b := [asize]int{1, 2, 3, 4, 5}
	var ptr_to_array [asize]*int

	for i := 0; i < asize; i++ {
		ptr_to_array[i] = &b[i]
	}
}
