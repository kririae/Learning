class Person
  attr_accessor :name
  def initialize pname
    self.name = pname
    @love = []
  end
  def method_missing funcname
    return @love.include?((funcname.to_s.gsub /love/, '').gsub /\?/, '') if funcname.to_s.start_with? "love"
    @love << (funcname.to_s.gsub /fellInLoveWith/, '') if funcname.to_s.start_with? "fellInLoveWith"
  end
  def add_person pname
    @love << pname
  end
end
you = Person.new "KriaeTh"
you.fellInLoveWithme
p you.loveme?
if(you.loveme?) then
  puts "goodBye, #{you.name}"
end
# funcname : love(a person)?