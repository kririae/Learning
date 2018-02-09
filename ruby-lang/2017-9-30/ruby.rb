def summary from, to
  result = 0
  from.upto to do |i|
    if block_given?
      result += yield i
    else
      result += i
    end
  end
  result
end
result = summary 1, 1000 do |i|
  i + 1
end
p result

module K_math
  def steady_sort array
    used = array.clone
    used.length.times do |i|
      (i + 1...used.length).each do |value|
        compare = block_given? ? yield(used[i], used[value]) : (used[i] > used[value])
        if compare
          used[i], used[value] = used[value], used[i]
        end end end
    used
  end

  def short_sort array
    res = []
    result = []
    array.each do |i|
      res[i] ||= 0
      res[i] += 1
    end
    res.each_with_index do |i, index|
      if i != nil
        i.times do |value|
          result << index
        end end end
    result
  end
  module_function :steady_sort, :short_sort
end
a = [9, 8, 4, 3, 7, 0, 3, 2, 0, 10]

res = K_math.steady_sort a
print "basic sort: "
p res
res = K_math.steady_sort a do |a, b| a > b end
print "basic sort with block given: "
p res
res = K_math.short_sort a
print "short sort: "
p res
# others types of sort is waiting to be updated

