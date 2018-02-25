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