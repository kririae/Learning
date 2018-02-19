package main

import (
	"fmt"
	"math/rand"
)

type Phone interface {
	boom()
	defence()
}

type Nokia struct {
	hard_level int64
}

type Note7 struct {
	power int64
}

func (nuclear_bomb note7) boom() {
	fmt.Println("warning warning, note7 will boom in the next ten seconds")
}

func (protecting_mask Nokia) defence() {
	fmt.Println("Protecting mask is expanding")
}

func main() {
	var war Phone
	protecting_mask = new(Nokia)
	boom = new(Note7)
}