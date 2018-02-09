package main

import "fmt"

func main() {
	var myname = "kririae"

	for i, val := range myname {
		fmt.Println(i, val)
	}
	fmt.Println("-----------")
	// also, if you want to ignore index, just replace it with "_"
	// the following is a sample
	for _, val := range myname {
		fmt.Println(val)
	}
}
