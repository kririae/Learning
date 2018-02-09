package main

import (
	"fmt"
	"math"
)

func main() {
	const pi = math.Pi

	var (
		varA = 120391
		varB = 12124124
	)

	fmt.Println(varA - varB)

	var myName string = "kririae"

	fmt.Println(myName, "is a fake girl") // automantically add a space
	fmt.Printf("The two numbers in binary varA: %b, varB: %b \n", varA, varB)
	// there a three ways to define variables
	/*
	var (
		a = true
		b = false
	)
	a := true
	b := false

	var a bool = true
	var b bool = false

	var a = true
	var b = false
	 */
	i := 1
	for i <= 10 {
		fmt.Println(i)
		i++
	}

	// logical operation == != ...
	for j := 0; j < 5 ; j++ {
		fmt.Println("priting j:", j)
	}

	var oneArray[5] int

	for i := 0; i < 5; i++ {
		oneArray[i] = i
	}

	// fmt.Println(oneArray[1])

	// or just
	anotherArray := [5]int {1, 2, 3, 4, 5}

	for _, value := range anotherArray {
		fmt.Println(value)
	}
	fmt.Println()
	oneSlice := []int {5, 4, 3, 2, 1}

	anotherSlice := oneSlice[2: 5]

	for _, value := range anotherSlice {
		fmt.Println(value)
	}

	// using make function

	numSlice := make([]int, 5, 10)

	copy(numSlice, oneSlice)
}
