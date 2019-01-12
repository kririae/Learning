title: 「学习笔记」haskell
author: kririae
tags:
  - haskell
  - 学习笔记
categories: []
date: 2018-02-24 16:54:00
---
# Haskell学习笔记

---

haskell学习笔记

<!--more-->

2018/2/24
```haskell
-- # haskell装逼指南

-- > 好吧只是我的一个学习笔记

{-
haskell是纯函数式语言。其不会保留状态。`x = 5`的意义就仅仅是`x的值是5，是一个既定事实`。
## 语法学习
### 函数调用省略逗号
`succ 1` -> 2   
`succ (succ 1)` -> 3

---

### 装逼指南1 => 
两参数的函数可以使用``将其变成中缀函数   
`min 1 2` -> `1`   
写成```1 `min` 2``` -> 1

---

### 函数的使用
`doubleMe x = x + x` -> [4] -> 8
-}
doubleMe x = x + x
doubleUs x y = x*2 + y*2
doubleSmallNumber x = if x > 100
                      then x
                      else x * 2
doubleSmallNumber' x = (if x > 100 then x else x * 2) + 1
aliceMargatroid = "kririae" 
-- 写了半天才知道注释怎么写  
-- 上面那玩意儿不是变量，仅仅是一个定义，因为其不可变
-- lostNumbers = [4, 8, 15, 16, 23, 48]
a = [1, 2, 3, 4, 5]
b = [6, 7, 8, 9, 10]
-- c = a ++ b
-- ++运算符效率很低，谨慎使用...对于左边很长的时候很低
-- :是++运算符的简化方法，使用如下 
c = 0 : a
-- 如果要添加一个元素到b -> d
d = 0 : b
-- 错误示范 =>>
{-
d = 1 ++ b
2018-2-24.hs:43:5: error:
    ? No instance for (Num [a0]) arising from the literal ‘1’
    ? In the first argument of ‘(++)’, namely ‘1’
      In the expression: 1 ++ b
      In an equation for ‘d’: d = 1 ++ b
   |
43 | d = 1 ++ b
   | 
   
正确:
d = [1] ++ b
-}

e = 1: 2: 3: 4: 5:[]
f = [1, 2, 3, 4, 5]
-- 效果相同

-- 下面又是hs的骚语法习惯了
g = [1, 2, 3, 4, 5]
h = g !! 3 -- ==> g[3]
-- 下面是一些比较正常的比较
{-
_(┐「ε:)_>>>[3, 2, 1] > [2, 1, 0]
True
_(┐「ε:)_>>>[3, 2, 1] > [2, 10000, 1000000000]
True
_(┐「ε:)_>>>[3, 4, 2] > [3, 4]
True
_(┐「ε:)_>>>[3, 4, 2] >= [3, 4]
True
_(┐「ε:)_>>>[3, 4, 6, 3, 5, 3, 3, 3, 2, 1, 3, 4] > [1000]
False
-}

{-
List函数列表
a = [1, 2, 3, 4, 5]
head      =>> a[0]            -> 1
tail      =>> a[1:5]          -> [2, 3, 4, 5]
last      =>> a[a.size() - 1] -> 5
init      =>> a[0:4]          -> [1, 2, 3, 4]
length    =>> a.size()        -> 5
null      =>> a.empty()       -> False
--null [] =>> a.empty()       -> True
reverse   =>> a.reverse       -> [5, 4, 3, 2, 1]
take      =>> a[:3]           -> [1, 2, 3]
maximum   =>> max(a)          -> 5
minimum   =>> min(a)          -> 1
sum       =>> sum(a)          -> 15
product   =>> a.inject :*     -> 120
elem      =>> 4 in a          -> True
--elem    =>> hs:4 `elem` a   -> True
-}

-- Range类型
qwq = [2, 4..20]
-- 题目1，[1..20]中有多少3的倍数
length [1, 4..20]

-- 惰性求值是真的骚，比如这里
take 10 (cycle [1, 2, 3]) 
-- =>> [1, 2, 3, 1, 2, 3, 1, 2, 3, 1]
-- 求前24个13的倍数
{-
loli>>>take 24 [13, 26..]
[13,26,39,52,65,78,91,104,117,130,143,156,169,182,195,208,221,234,247,260,273,286,299,312]
-}

-- 接下来是我最喜欢的列表解析
a = [x | x <- [1..]] -- 创建了一个无限列表
-- 只有在需要的时候才进行计算

geti lst val = [x | x <- lst, x `mod` val == 0]
-- 这个函数的意义是获取lst中，val的倍数

length' xs = sum [1 | _ <- xs]

removeUpperCase st = [c | c <- st, not (c `elem` ['A'..'Z'])]
removeUpperCase' st = [c | c <- st, c `elem` ['a'..'z']]

let xxs = [[1,3,5,2,3,1,2,4,5],[1,2,3,4,5,6,7,8,9],[1,2,4,2,1,6,3,1,3,2,3,6]]
ret = [[x | x <- xs, even x] | xs <- xxs]
```

2018/2/25
```haskell
-- Tuple（总有种学python的赶脚...
a = [(1, 2), (3, 4), (5, 6)] -- -> true
-- b = [(1, 2), (3, 4, 5)] -- -> CompileError 因为(3, 4, 5)的类型和(1, 2)不相同

-- 函数1
fst (8, 11) -- -> 8

-- 函数2
snd (8, 11) -- -> 11

-- 有用的函数（python用过
zip [1, 2, 3, 4, 5] [6, 7, 8, 9, 10]
-- =>> [(1,6),(2,7),(3,8),(4,9),(5,10)]
zip [1 .. 5] ["one", "two", "three", "four", "five"]
-- =>> [(1,"one"),(2,"two"),(3,"three"),(4,"four"),(5,"five")]
-- 同时可以zip无限列表
b = zip [1..] [2..]

-- 获取周长100以内的直角三角形
righttrangle = [ (a, b, c) | c <- [1..100], b <- [1..c], a <- [1..b], a ^ 2 + b ^ 2 == c ^ 2, a + b + c `elem` [1..100]]

-- # Types and Typeclasses
removeNonUppercase :: [Char] -> [Char]
removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']]

-- or
removeNonUppercase' :: String -> String
removeNonUppercase' st = [ c | c <- st, c `elem` ['A'..'Z']]

addThree :: Int -> Int -> Int -> Int
addThree x y z = x + y + z

{-
[functionName] :: types -> return types
[functionName] parameters = result
-}

-- Integer 高精度 in haskell
factorial :: Integer -> Integer
factorial n = product [1..n]

-- Typeclasses
{-
:t (==)
(==) :: (Eq a) => a -> a -> Bool
=> 左的叫类型约束，书上这么解释：
有意思。在这里我们见到个新东西： => 符号。
它左边的部分叫做类型约束。
我们可以这样阅读这段类型声明：
"相等函数取两个相同类型的值作为参数并回传一个布尔值，
而这两个参数的类型同在 Eq 类之中(即类型约束)"

总结一下的话：
Eq包含判断相等的类型 == /=
Ord包含比较大小的类型 < > <= >=
    compare函数取两个Ord类型中的值，回转比较的结果
    有三种类型：GT,LT,EQ
-}

-- 新的函数
show 3 -- -> "3"
show 5.334 -- -> "5.334"
show True -- -> "True"
show [1, 2, 3, 4, 5] -- -> "[1,2,3,4,5]"

read "[1, 2, 3, 4, 5]" ++ [6] -- -> 6
-- 后面的部分不能省略，read依靠其判断类型

-- 类型注释应运而生
read "5" :: Int
read "[1, 2, 3, 4]" :: [Int]
read "kririae" :: String -- qwq
```

2018/2/26
typeclass后开始蒙蔽
```haskell
-- 今天是haskell那套独（蛇）特（皮）的语法结构
-- pattern matching
lucky :: (Integral a) => a -> String
lucky 7 = "LUCKY NUMBER SEVEN!!!"
lucky x = "qwq..."

sayMe :: (Integral a) => a -> String
sayMe 1 = "One!"
sayMe 2 = "Two!"
sayMe 3 = "Three!"
sayMe 4 = "Four!"
sayMe 5 = "Five!"
sayMe x = "Not between 1 and 5"

factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial (n - 1)

addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)

first :: (a, b, c) -> a
first (x, _, _) = x

second :: (a, b, c) -> b
second (_, y, _) = y

third :: (a, b, c) -> c
third (_, _, z) = z

ls = [(1,3), (4,3), (2,4), (5,3), (5,6), (3,1)]
ret = [a + b | (a, b) <- ls]

head' :: [a] -> a
head' [] = error "Can't call head on an empty list, dummy!"
head' (x:_) = x -- [1, 2, 3]的本质是1:2:3:[], 所以可以写成(x:_), 后面的忽略就是了

test :: (Integral a) => [a] -> [a]
test x = [ a * b | a <- x, b <- x, (a * b) `mod` 2 == 0]

length' :: (Num b) => [a] -> b
length' [] = 0
length' (_:xs) = 1 + length' xs

length'' :: (Num a) => [a] -> Int
length'' x = sum [1 | a <- x]

sum' :: (Num a) => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs
```