package main

// 之前学的全都忘完了TAT
// 重新学一次吧
import (
	"fmt"
)

/*
func main() {
	fmt.Println("The time is", time.Now())
	rand.Seed(23333)
	fmt.Println(rand.Intn(10))
}
*/
// 注意 只有首字母大写的函数才会被导出...

var c, pythonn, java bool

var a, b int = 1, 2

func swapp(x, y int) {
	x, y = y, x
}

func test2() {
	a, b, c := 1, 2, 3
	fmt.Println(a, b, c)
}

func main() {
	var i int
	fmt.Println(i, c, pythonn, java)
	fmt.Println(a, b)
	swapp(a, b)
	fmt.Println(a, b)
	// ?????
	// another define method
	var m, n int = 1, 2
	fmt.Println(m, n)

	test2()
}
