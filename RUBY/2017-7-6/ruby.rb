#coding=utf-8

res = Array.new(10){|i| i+1}
module A
  refine String do
    def plus a
      return self + a
    end
  end
end
using A
p 'a'.plus 'b'
p self.class
#可以用send调用方法w
class MyClass
  def my_method my_arg
    my_arg*2
  end
end
obj = MyClass.new

p obj.my_method 2
p obj.send :my_method,2
p obj.send 'my_method'.to_sym,2

p obj.methods.grep /send/

=begin
记住动态配发...防止代码重复的关键...
=end
=begin
还有dynamic method。
动态方法，使用如下
=end
def self.define_method name
  define_method name do
    #...
  end
end
=begin
还可以使用内省的方法定义，不过不常用，我还是做一个为好
=end
=begin
data_source.methods.grep/^get_(.*)_info$/
{Computer.define_method $1}
question???$1???
#TODO
=end

#There is not only one way to solve a problem

#method missing

class People;end
#p = People.new
#p.talk =>in `<top (required)>': undefined method `talk' for #<People:0x00000002b81918> (NoMethodError)

class People
  def method_missing method,*args
    puts "calling the method '#{method}'"
  end

end
p = People.new
p.talk

p p.respond_to? :talk
a = 2
p a==1||2









































