#!usr/bin/env ruby
#coding=utf-8

#author:kino3z
#date:2017-6-21

#i am praticing python recently....


class A
  ::VAR1 = 1
  ::VAR2 = 2
  def show
    puts "#{::VAR1}"
    puts "#{::VAR2}"
  end
end
puts A::VAR1
a = A.new
a.show

#queston???

module B
  CONST1 = 1
  ::CONST1 = 2
end

puts B::CONST1

#and == &&
#or == ||

c = true
d = 0
begin
  puts d
  d+=1
end while d <= 10
#每个都可以这么用w

for i in 0..5
  puts i
end
#相同
(0..5).each do |i| puts i end

#break的用法和python相同

#retry(返回到主体的begin)

begin
  #dosomething
  puts "do some things"
rescue
  retry
end

#until和while相反

while true
  #SOMETHING
  puts nil
  break
end
#==
until false
  #SOMETHING
  break
  puts nil
end

def test a1='ruby',a2='test'
  puts a1
  puts a2
end

test
test 'python','ruby'

$A = 1

alias kino3z test


kino3z

$a = 1
alias $b $a
puts "#{$b} is printing "
$b = 2
puts "#{$b} is printing"
puts "#{$a} is printing"
undef test
