package main
import (
	"fmt"
	"math/rand"
)
func main() {
	rand.Seed(2333)
	fmt.Println("The number is: ", rand.Int() % 10000)
}
