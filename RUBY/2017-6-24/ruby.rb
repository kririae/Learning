#!usr/bin/env/ruby -
#coding=utf-8
$a = 1
while $a<20 do
  puts "haha"
  $a+=1
end
$b = 1
begin
  puts $b
  $b +=1
end while $b < 20
for i in (0..10)
  puts i
end
for i in (0..10) do puts i end
(0..10).each do |i|  puts i end


#处理异常：
begin
  #d
rescue
  retry
end


#retry 是循环一次的意思，即重新评估
#redo 是重新开始，不检查循环条件

def sample *test
  puts test.length
  test.each do |i| puts i end
end

sample (1..10).to_a

#再写一次alias，避免忘记了
#underf
=begin
def test
  puts '1'
  yield
  puts 2
  yield
end

def test
  yield [5]
  yield [10]
end

test {|i| puts i}
#test {puts "parts"}
=end
def test
  yield [1]
  yield [1,2]
  yield [1,2,3]
end
#重点

test do
|a,b,c| puts a,b,c
end
=begin
module A
    def put
      puts "hello"
    end

end
A::B.put
=end


module A

  def c
    puts 'using a'
  end

end
#mixin
class D
  include A
  def e
    puts 'using e'
  end
end
d =D.new
d.c
d.e

desc = %Q{我服}#双引号规则
desc2 = %q{我服？}#单引号规则

#以下是java写法
mystr = String.new("MYSTR")
p mystr
p mystr.downcase

p mystr*2
p mystr+'233333'

n = 122
#约等于python-chr函数
p mystr << n
p mystr == n
p mystr <=> n

p 'mystr'.capitalize
p 'mystr'.capitalize!

puts "mystr\n\n\n"
puts "mystr\n\n".chomp!
