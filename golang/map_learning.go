package main

import "fmt"

func exist(mmp map[string]int, val string) bool {
	_, status := mmp[val]
	return status
}
func main() {
	// the cost of finding a element in a map is O(n\log_2{n})?
	// var mmp map[string]int
	// or
	mmp := make(map[string]int)
	mmp["fakegirl"] = 233
	fmt.Println(mmp["fakegirl"])

	// if exist?
	fmt.Println(exist(mmp, "fakegirl"))

	delete(mmp, "fakegirl")

	fmt.Println(exist(mmp, "fakegirl"))
}
