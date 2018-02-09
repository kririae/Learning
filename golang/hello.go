package main

import (
	"fmt"
	"os"
)

func main() {
	target := "World"
	if len(os.Args) > 1 {
		target = os.Args[1]
	}
	fmt.Println("Hello", target)
}
