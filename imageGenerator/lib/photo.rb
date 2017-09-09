# encoding = utf-8
require "carrierwave/processing/rmagick"
path = __FILE__.to_s.split('/')
path = (path[0..path.length-3].join '/') + '/' + 'photos/'
p path
p Dir.exist? path
#p FileTest.exist? "photos"