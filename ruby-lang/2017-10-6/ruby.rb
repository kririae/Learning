# encoding = utf-8
# author : KriaeTh
x = y = z = 0
ary = [1, 2, 3]
ary.each do |x; y|
  y = x
  z = x
  p [x, y, z]
end
puts
p [x, y, z]

=begin
irb(main):001:0> c = Complex(0, 2) ** 2
=> (-4+0i)
irb(main):002:0> 5 ** -2
=> (1/25)
irb(main):003:0> 1.0 / 0
=> Infinity
=end
# 运算结果为Rational对象，采用quo方法（
p 5.quo 2

p Math.sqrt 2

b = 0b11110000
def pb b
  printf "%08b\n", b & 0b11111111
end
pb b
p b
p b << 1
p b << 2
p 2 << b
p 3 << b
p 4 << b

x = 0b11110000
y = 0b00001110
pb x + y
pb x * y

p Random.rand
10.times do
  p Random.rand 100
end

r1 = Random.new 1
p r1.rand

#