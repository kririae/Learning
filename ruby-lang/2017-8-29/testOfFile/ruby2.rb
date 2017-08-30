# pratice of producing file
require "pp"
file = File.open "file.txt"
file.each_line do |chr|
  if /#include/ =~ chr || /using namespace/ =~ chr || /return/ =~ chr
    puts chr
  end end
