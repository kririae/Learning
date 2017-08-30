# encoding = utf-8
# author : KriaeTh
# date : 2018-8-30

=begin
从今天开始，初中升入高中的暑假就彻底结束了，学校也不允许带手机
ruby的学习也只能停留在书上了
我还是会坚持每天读书的，但是写程序大概是不可能了...除非...
但是看我们班主任是绝对不会同意的...

反正，之后我的编程大概就停留在竞赛的层面了吧，周五周六竞赛训练
再见了
心伤啊
=end

# 下面是学习方法的定义
=begin
在面向对象，或者说在ruby中，对调用方法有一种特殊的解释
“向对象发送信息”
关于调用方法，大概是这样的
这行代码："100".to_i
programmer(transfer) =>(to_i) =>"100"(receiver)
                                 |||
          variables <= result <= 100

所以有了object.respond_to?()这一方法
=end

=begin
还有一种叫做：带块的方法
详情就是：
10.times do |i| puts i end
这里的do .. end is called "带块的方法"
10.times {|i| puts i }
=end

=begin
object.functionName params do |__params__|
  process
end
=end

# In ruby, operators are not exists... they are all methods
# code : 2 - 1
# This code have the following comprehension : "2.:-(1)" object:2 is the receiver;param is 1;method name is "-"

# according to the type of receiver , we can devided methods into three parts...
# class method\objective method\functional method
# method without erceiver can be called as functional method..


