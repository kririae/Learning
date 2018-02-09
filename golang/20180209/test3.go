package main

import "fmt"

func main() {
	fmt.Println(f())
}
func f() (result int) {
    defer func() {
		fmt.Println(result)
        result++
    }()
	return 1000
}