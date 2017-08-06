#！usr/bin/env ruby
#coding=utf-8
a = 10
puts a if a ==10#=>10
#[code] if [condition]

#defined?
p defined? a    #=>10
p defined? b    #=>"local-variable"

$c = 10
p defined? $c   #=>"global-variable"
#@开头实例变量
#@@开头类变量
#::常量

#运算符
#<=>
#昨天已经演示过了

#eql?
a = 10
b = a
p b.eql?(a)      #=>true

a = 10
b = 10.0
p b.eql?(a)      #=>false
#.eql?比较数值

a = 10
b = a

p b.equal?(a)    #=>true


#logic operator
['and','or','%%','||','!','not']

#三元运算符
#?

(1..10).each do |i| puts i end #include 10
(1...10).each do |i| puts i end#not include 10

#修饰符
unless true
  puts "oh it's true"
else
  puts "oh it's false"
end

#=> oh it's false

puts "oh it's false" unless false

a = 10
case a
  when 0...11
    puts a
    #########
  else
    # type code here
end

