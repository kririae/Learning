#coding = utf-8
require 'net/smtp'

Net::SMTP.start('ss.touhou.studio') do |smtp|
  smtp.send_message('hello','kino3z@yuyuko.cc','lwz@margatroid.xyz')
end