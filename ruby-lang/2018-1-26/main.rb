method_name = [:f, :s, :t]

method_name.each do |name|
  define_method name do ||
    puts name.to_s
  end
end

temp = ['a', 'b', 'c'].push('d').shift.tap { |x| puts x }.upcase.next
puts temp