#coding=utf-8

class Test
  def method_missing name,*args
    puts name
    puts args
  end
end
t = Test.new
t.fuck "ass we can"
#=>fuck,ass we can


