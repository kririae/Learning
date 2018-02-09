#coding=utf-8
#author:kino3z

#date:2017-7-5
=begin
接触ruby快一个月了，真是一门好语言啊
那么，继续吧...接下来是metaprogramming的世界
=end

=begin
首先别忘了
=end

class A
#  private
  def a;end
end
b = A.new
b.a

p self
p self.class
p Object.methods
module A_module
refine Array do
  def plus a
    self + a
  end
end
end
a = [1,2,3,4]
b = [2,3,4,5]
begin
p a.plus b
rescue
  puts "error"
  using A_module
  retry
ensure
  puts a.plus b
end

p Kernel.methods
10.times do puts 1 end