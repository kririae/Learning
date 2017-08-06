#coding=utf-8
def Kernel.with resource,name
  begin
    yield
  ensure
    resource.__send__ name.to_sym
  end
end
#using kernel method to take the place of c#'s 'using'
#the following is about closures
def a
  x = "hello"
  yield x
end
x = "goodbye"
a do
  |x| puts x
end
