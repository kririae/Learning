def square_digits num
  # code goes here
  res = num.to_s.split('').map{|i| ((i.to_i)**2).to_s}.join("")
  return res.to_i
end

#以下是异常处理
begin
  puts a
rescue
  puts "error"
else
ensure

end

class BOX
  def initialize w,h
    @width,@height = w,h
  end
  def getter_w
    @width
  end
  def getter_h
    @height
  end
  def setter_w=value
    @width = value
  end
  def setter_h=value
    @height = value
  end
end


#设置器方法
b = BOX.new 10,20
p b.getter_w
p b.getter_h
b.setter_h = 20
b.setter_w = 40
p b.getter_w
p b.getter_h
class Person
  attr_accessor :kino3z,:name
end

c = Person.new
c.kino3z =123
c.name = 234
p c.kino3z
p c.name







