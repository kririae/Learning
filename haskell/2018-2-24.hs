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