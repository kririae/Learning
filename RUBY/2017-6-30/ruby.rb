#coding=utf-8
time = Hash.new "time"
#time为time哈希的默认值w
p time #=>"time"

p time[2333] #=>"time"
time['date'] = 1
p time['date']
time = {'date'=>'1','m'=>10}
time.each{|date,m| puts date,m}
p time.has_value? 10
p time.has_key? 'date'

p time.keys
p time.values

