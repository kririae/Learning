# encoding = utf-8
# author : KriaeTh
# date : 2017-8-29

require "pp"
str1 = "KriaeTh" # => deepcopy
str2 = str1
# TODO
#pp str1.equal? str2
#pp str1.eql? str2

# The ways of looping
a = 10
a.times do |i|
  #puts "第#{i}次循环"
end
=begin
补充:
  do .. end的作用是代码块，现在不细致解释
=end
=begin
from = 1
to = 100000000
sum = 0
for i in from..to
  sum += i
end
puts sum
=end
res = 0
#100000000.times{|i| res += i + 1}
#puts res

#下面的是速度极其快的位运算
pp 2 << 100
#还可以
pp 1 << 1
#下面是关于===的运算
pp (1 ... 100) === 50
pp String === "KriaeTh"
pp /ruby/i === "ruby"



