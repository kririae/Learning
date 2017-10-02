# date: 2017-10-1 22:58
# author: KriaeTh
# learning block
def block_test
  yield
  yield 1
  yield 1, 2, 3
end
block_test do |a|
  p a
end
puts
block_test do |a, b|
  p a, b
end
puts
block_test do |*a|
  p a
end
puts
block_test do |a, *b|
  p a, b
end

# ---------

# about Proc Object
hello = Proc.new do |name|
  puts "Hello, #{name}."
end

hello.call "KriaeTh"
hello.call "Ruby"

def total from, to, &block
  res = 0
  from.upto to do |value|
    if block
      res += block.call value
    else
      res += value
    end
  end
  res
end

p total 1, 10
p total 1, 10 do |num| num * 2 end
puts
def call_each array, &block
  array.each &block
end
call_each [1, 2, 3] do |item|
  p item
end
puts
a = Proc.new do |item|
  p item
end
[1, 2, 3].each &a