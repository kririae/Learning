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