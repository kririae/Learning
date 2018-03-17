product' :: (Num a) => [a] -> a
product' [] = 1
product' (x:tl) = x * product' tl

length' :: (Num a) => [a] -> a
length' [] = 0
length' (_:tl) = 1 + length' tl