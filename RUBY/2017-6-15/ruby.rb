#!/usr/bin/ruby -w
#coding=utf-8
#我是注释 请忽略我
puts "这是主程序<<"
BEGIN{
	puts "这是初始化程序"
}
END{
	puts "停止ruby程序"
}

=begin
这也是注释
请忽略这个注释
=end


a = 5
puts "#{a}"
puts 'using #{a}'
puts "using \\"
=begin
	这里注意单引号和双引号
	单引号不可替换，但是可以转义
	双引号既可以替换也可以转义
	序列#{expr}	
=end

=begin
\n : 换行
\r : 回车
\f : 换页
\b : 退格
\a : 报警
\e : 转义
\s : 空格
\nnn : 八进制
\xnn : 十六进制
\cx,\C-x 某emacs
\M-x
\M-\C-x
\x
=end


array = ['kino1z','kino2z','kino3z','kino4z','kino5z','kino6z','kino7z',]
array.each do |i|
	puts i
end
puts array.size,array.length
array2 = Array.new(10,'kino3z')
puts "#{array2}"

array3 = Array.new(10) { |i| i = "kino#{i}z"  }
puts "#{array3}"
