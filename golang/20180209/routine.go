package main

import (
	"fmt"
	"time"
	"sttconv"
)

func main() {
	for i := 0; i < 10; i++ {
		go count(i)
	}
	time.Sleep(time.Millisecond * 11000)
}

func make(string chan chan string) {

}
