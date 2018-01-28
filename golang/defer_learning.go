package main

import (
	"fmt"
)

func main() {
	defer printO()
	printT()
}

func printO() {
	fmt.Println(1)
}

func printT() {
	fmt.Println(2)
}
