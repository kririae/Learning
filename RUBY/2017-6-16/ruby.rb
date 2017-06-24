#!/usr/bin/env ruby -w
#coding=utf-8
#author : kino3z
#touhou.studio

#start

=begin
result = 20*40*80
puts result
puts "#{result}"
puts "#{20*40*80}"

(10...15).each do |n|
	puts n
end
class KINO3Z
end


	局部变量：小写或者_开头
	实例变量：@开头
	类变量：@@开头
	全局变量：$开头


class A
	@@number_a = 0
	@bumber_b = 1
end



class B
	def initialize(m,n,h)
		@b_m = m
		@b_n = n
		@b_h = h
	end
end

class Sample
	def function
		puts "kino3z"
	end
end

object = Sample.new
object.function



class Customer
	@@no_of_customers = 0
	def initialize(id,name,addr)
		@cust_id = id
		@cust_name = name
		@cust_addr = addr
		@@no_of_customers+=1
	end
	def display_details
		puts "#{@cust_id}"
		puts "#{@cust_name}"
		puts "#{@cust_addr}"
	end
	def output
		puts @@no_of_customers
	end
end

customer = Customer.new(0,'reimu','gensokyo')

cust2 = Customer.new(1,'marisa','gensokyo')
cust2.output
#do you mean太亲切了


=end
=begin
$global = 10
class Class1
	def print_global
		puts "全局变量输出：#{$global}"
	end
end
c = Class1.new
c.print_global

puts __FILE__
puts __LINE__
=end

$a = 10
$b = 20

puts $a+$b
puts $a*$b
puts $a/$b
puts "#{$a%$b}"
puts $a**$b

puts $a === $b
puts $a == $b
#多了个联合比较运算符
a = 1
b = 1
puts a <=> b
b = 2
puts a <=> b
a = 3
puts a<=>b
#.eql? 判断类型和值
##.equal?
#=
#+=
#-=
#*=
#%=
#**=
#可以并行赋值
#例如
a , b ,c = 1,2,3
a,b = b,c

#位运算符
#
puts ~a









