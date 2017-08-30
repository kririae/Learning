#include <cstdio>
#include <iostream>
#include <cstring>

# encoding = utf-8
# author : KriaeTh
# date : 2017-8-30

require "pp"
$a  = 1
a = 2
puts a
puts $a
#从此处可以看出两种a不一样...
res = 0
until res >= 3
  puts res
  res += 1
end

=begin
break : 跳出当前循环
next ： 进入下一次循环
redo : 重复当前循环
=end

lang = ["cpp","csharp","python","ruby","c"]
lang.each do |lang|
  puts lang
  if lang == "ruby"
    redo #这段代码是死循环
  end end