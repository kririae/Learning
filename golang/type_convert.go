package main

import "fmt"
import "strconv"

func main() {
	var orz string = "23333"

	result, _ := strconv.Atoi(orz)
	fmt.Println(result)
}