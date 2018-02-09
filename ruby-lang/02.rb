class ClassTest
	100.times do |i|
		define_method "method_#{i}" do |*args|
			puts i
		end
	end
end
a = ClassTest.new
a.method_1