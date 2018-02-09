require 'benchmark'
a = nil
count = 0
File.open "/home/kriaeth/Desktop/input.in" do |f|
  a = eval f.readline
  end
Benchmark.bmbm 5 do |t|
  t.report {
    a.sort! do |a, b|
      count += 1
      a <=> b
    end
  }
end
puts "executing times: #{count}"