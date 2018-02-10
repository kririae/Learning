# go learning

---

记得很早之前我写过一篇，不过这次算是比较系统的学习   

go果然对cpp程序员比较友好啊 

首先解析一个程序的基本结构

```go
package main

import "fmt"

func main() {
	fmt.Println("kririae")
}
```
这是一个基本的go程序   

第一行`package main`大概是名称空间的意思   

是每一个可执行程序的开头

`import fmt`则是`import`了一个包，"format"   

和`c`的`cstdio`大概是一个意思   

顺带说一句，go支持内嵌c语言...

```go
package main

import "fmt"

/*
int add(int a, int b) {
  return a + b
}
 */
import "C"

func main() {
  fmt.Println(add(1, 2))
}
```

下一步，变量申明

go的变量声明有两种

局部变量多数时候用`a := 1`

绝非动态语言，go只是帮忙推断类型

全局变量应该是这样的

`var a int = 1`

类型和c差不多。

声明数组用

`var a [5]int`

声明了一个大小为5的数组

`var a []int` 声明了一个大小未知的动态数组

这段语句也可以这么些

`a := make([]int, 5)`

有一个很玄学的第三个啊承诺书

`a := make([]int, 5, 10)`

类比到cpp cpp的vector为了防止加入内容缓慢而减速，设置了cap

cap的意义是“留存一些空间便于下一次分配的时候使用”

那么第三个参数到底是啥意思...

`append(a, 233, 233, 233, 233, 233, 233)`

你会发现，现在的`cap(a)`变成了20。那大概就是每一次分配的空间数了

slice（之前在数组之后介绍的）还zici切片

`fmt.Println(slice[2:5])`，切片qwq



发现一个难点

go语言的返回值

```go
func ret() (re int) {
  defer func() {
    re++
  }
  return 0;
}
```

如果没有看错，得到的是1

干了这样一件事情qwq

首先，给re分配了一个空间，作为返回值。

然后，把0给了ret...

再然后++re

然后返回

```go
func f() (result int) {
    defer func() {
		fmt.Println(result)
        result++
    }()
	return 2333
}
```

比如说这个函数

调用后的结果是`2333`

