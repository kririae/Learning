#!/usr/bin/env ruby -w
#coding=utf-8
=begin
BEGIN{
  puts "this program is already to begin"
}

module Kernel
  def range num1,num2=0
    return num2..num1
  end
end

for i in range(10)
  puts i
end
END{
  puts "this program is already to stop"
}
=end

#以上是测试，不要当真
#metaprogramming 之，代码块：block
def returns
  yield 1 if block_given? else 2
end
a = returns
p a
returns{|i| puts 1}
#block_given(划重点----------------------)

=begin
代码油两个部分组成，第一个是code，第二个是binding绑定
代码能够运行的原因就是拥有绑定和代码
=end

#而代码块能够带出变量的原因就是他可以无权引用绑定
print <<EOF
ruby采用绑定加代码的方式来控制变量作用域
而代码块可以访问绑定
EOF

class Test
  def method_missing name,*args
    puts name
    puts args
  end
  def self.define name
    define_method name do
      puts "hello"
    end
  end

  end

t = Test.new
#注意，这里调用了一个不存在的方法qwq
t.define 'fuck'
p t.fuck 4

