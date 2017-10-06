# encoding = utf-8
# date : 2017-10-6
# author : KriaeTh
a = 0.1 + 0.2
b = 0.3
p [a, b]
p a == b
p a.eql? b
p a.equal? b

# solution
a = Rational(1, 10) + Rational(2, 10)
b = Rational(3, 10)
p a == b
