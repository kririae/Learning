def get_sum a,b
  res = 0
  if a < b
  (a..b).each do |i| res += i end
  else
    (b..a).each do |i| res += i end
  end
  return res
end

p get_sum 5,-1

def get_sum2(a,b)
  (a..b).reduce(:+) || (b..a).reduce(:+)
end
require 'Time'
time1 = Time.new
p time1.inspect
time2 = Time.now
p time2.inspect

('HELLO1'..'HELLO9').each{|i| puts i}


def binary_array_to_number(arr)
  # your code here
  arr.map!{|i| i.to_s}
  return arr.reduce(:+).to_i(2)
end
p binary_array_to_number [1, 0, 0, 1]