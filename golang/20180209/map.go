package main

import "fmt"

func main() {
	name := make(map[string]string)
	name["kririae"] = "fakegirl"

	fmt.Println(len(name))
	fmt.Println(name["kririae"])
	delete(name, "kririae")

	// -----------------------------

	listnum := []float64{1, 2, 3, 4, 5}
	fmt.Println(addThemUp(listnum))

	num1, num2 := next2value(5)
	fmt.Println(num1, num2)

	fmt.Println(sub(1, 2, 3, 4, 5, 6, 7, 8, 9, 10))
}

func addThemUp(number []float64) float64 {
	sum := 0.0
	for _, value := range number {
		sum += value
	}
	return sum
}

func next2value(number int) (int, int) {
	return number + 1, number + 2
}

func sub(args ...int) int {
	sum := 0
	for _, value := range args {
		sum -= value
	}
	return sum
}
