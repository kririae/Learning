package main

import (
	"fmt"
)

/*
int add(int a, int b) {
	return a + b;
}
*/
import "C"

func main() {
	fmt.Println("kririae")
	// var a int = 2333
	// var favnumber float64 = 3.1415926
	randnum := 1
	fmt.Println(randnum)
	var num1 = 1.000
	var num99 = .999
	fmt.Println(num99 - num1)
	const pi float64 = 3.14159265
	// var (
	// 	a = 2
	// 	b = 3
	// )
	var name string = "kririae"
	fmt.Println(len(name))
	fmt.Println(name)

	var is_fake_girl bool = true
	fmt.Printf("%.3f \n", pi)
	fmt.Printf("%T \n", name)
	fmt.Printf("%T \n", is_fake_girl)

	fmt.Printf("%b \n", 8&-8)

	fmt.Println(add(1, 2))
}

// comment
/*
 *
 *
 *
 */
