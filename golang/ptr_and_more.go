package main

import "fmt"
 /*
 int add_c_ver(int a, int b) {
 	return a + b;
 }
   */
 import "C"

 func add_go_ver(a, b int) int {
 	return a + b
 }
func main() {
	fmt.Println(add_c_ver(1, 2))
	fmt.Println(add_go_ver(1, 2))
}