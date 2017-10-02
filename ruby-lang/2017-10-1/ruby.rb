# date: 2017-10-1 23:15
# author: KriaeTh
# learning block _ 2

require 'ripper'
require 'pp'
code =<<NTR
10.times do |i|
  puts i
end
NTR
puts code
pp Ripper.lex code
