# encoding = utf-8
# author : kriaeth
# get_line
# for free time playing
path, = ARGV
postfix_list = [".rb",".py",".cpp",".h",",c",".cs",".php",".js",".html",".css",".hs",".kt",".java",".md",".txt",".go"]
def get_line path,postfix
	res = nil
	IO.popen "find #{path} -name \"*#{postfix}\" |xargs cat|grep -v ^$|wc -l" do |f|
		res = f.gets
	end
	res.to_i
end
sum = 0
postfix_list.each do |i|
	res = get_line path,i
	puts "#{i} : #{res}" if res != 0
	sum += res
end
puts "summary : #{sum}"

