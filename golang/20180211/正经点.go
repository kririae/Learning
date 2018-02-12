package main

import (
	"fmt"
	"math"
)

type Abser interface {
	Abs() float64 // 定义了一个Abser的interface类型
	// go中的interface主要取名为#{method_name}er
}

type MyFloat float64 // 定义了一个MyFloat类型

func (f MyFloat) Abs() float64 { // 为MyFloat类型定义了一个名为Abs()的method
	// 上面来看，MyFloat拥有了一个Abs函数，而这个函数定义在Abser中...所以MyFloat实现了Abser的接口
	// 总感觉有一种霸占的感觉？？？
	/*
	有时候会这么定义
	type Namer interface {
		Method1(paralist) return_type
	}
	// 滚回竞赛了
	*/
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func main() {
	var a Abser
	f := MyFloat(-math.Sqrt2)
	a = f
	fmt.Println(a.Abs())	
}