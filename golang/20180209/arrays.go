package main

import "fmt"

func main() {
	var arrays [5]int
	arrays[0] = 1
	arrays[1] = 2
	arrays[2] = 3
	arrays[3] = 4

	fmt.Println(arrays[3])

	list := [100]int32{1, 2, 3, 4, 5}
	fmt.Println(list[23])

	for _, value := range list {
		fmt.Println(value)
	}

	slice := []int{1, 2, 3, 4, 5}
	// slice2 := slice[3: 5]

	// fmt.Println("slice2 = ", slice2[0])
	fmt.Println("slice[:2] = ", slice[:4])

	// slice2 := make([]int, 5)
	slice2 := []int{1, 2, 3, 4, 5}
	for _, value := range slice2 {
		fmt.Print(value, ", ")
		// fmt.Println(value)
	}

	slice2 = append(slice2, 233, 2333)

	fmt.Println()
	for _, value := range slice2 {
		fmt.Print(value, ", ")
		// fmt.Println(value)
	}

	slice3 := make([]int, 10, 15)
	slice3[9] = 1
	fmt.Println(slice3)

	slice3 = append(slice3, 2333, 2333, 2333, 2333, 2333, 23333)
	fmt.Println(cap(slice3))
}
