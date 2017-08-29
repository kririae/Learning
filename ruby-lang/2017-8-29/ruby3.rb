require "pp"
require "open-uri"
require "json"
class NeteaseCloudMusic
  def search name
    url = "http://music.163.com/api/search/get/";res = []
    response = open(url,"s" => name, "limit" => "20", "type" => "1", "offset" => "0")
    self.response do |f|
      f.each_line {|i| res << i} end
    res.inject :+ end
end
#res = %q{{"result":{"queryCorrected":["mz92"],"songs":[{"id":423776696,"name":"痒","artists":[{"id":12071053,"name":"齐悦","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},{"id":0,"name":"92","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":34801319,"name":"痒","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1470311247377,"size":1,"copyrightId":0,"status":1,"picId":18296972998230671},"duration":179881,"copyrightId":0,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":30284319,"name":"无心","artists":[{"id":1047020,"name":"小緣","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":3087250,"name":"最新热歌慢摇92","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1388505600004,"size":129,"copyrightId":0,"status":2,"picId":3294136838291284},"duration":268120,"copyrightId":0,"status":-1,"alias":["心做し"],"rtype":0,"ftype":0,"transNames":["无心"],"mvid":5293500,"fee":0,"rUrl":null,"alias":["心做し"]},{"id":459432,"name":"92","artists":[{"id":14598,"name":"冈本光市","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":44464,"name":"RANDOM","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1104508800000,"size":97,"copyrightId":0,"status":1,"picId":6040716883333198},"duration":5120,"copyrightId":0,"status":-1,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":30798757,"name":"雨き声残響","artists":[{"id":1047067,"name":"ゆめこ","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":3087250,"name":"最新热歌慢摇92","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1388505600004,"size":129,"copyrightId":0,"status":2,"picId":3294136838291284},"duration":173244,"copyrightId":0,"status":-1,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":347274,"name":"遥望","artists":[{"id":11127,"name":"Beyond","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":34211,"name":"遥望","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":744134400000,"size":12,"copyrightId":5003,"status":3,"picId":119846767440732,"alia":["黄家驹不死音乐精神特别纪念集92-93"]},"duration":324336,"copyrightId":7002,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":5337637,"fee":0,"rUrl":null},{"id":33920800,"name":"HeartBeat","artists":[{"id":1132794,"name":"JustLn","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},{"id":0,"name":"92","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":3265699,"name":"HeartBeat","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1345046400000,"size":1,"copyrightId":0,"status":0,"picId":3361207046469269},"duration":163787,"copyrightId":0,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":30148805,"name":"Tight With You","artists":[{"id":27595,"name":"Akon","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":3087250,"name":"最新热歌慢摇92","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1388505600004,"size":129,"copyrightId":0,"status":2,"picId":3294136838291284},"duration":152659,"copyrightId":0,"status":-1,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":420125697,"name":"STYX HELIX【Re：从零开始的异世界生活 ED】","artists":[{"id":1056002,"name":"三无MarBlue","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":3087250,"name":"最新热歌慢摇92","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1388505600004,"size":129,"copyrightId":0,"status":2,"picId":3294136838291284},"duration":291604,"copyrightId":0,"status":-1,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":386501,"name":"92全运会闭幕表演音乐(活力e时代篇)","artists":[{"id":13193,"name":"五月天","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":38279,"name":"92全运会纪念EP","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1062345600000,"size":5,"copyrightId":1003,"status":1,"picId":49478023262210},"duration":503000,"copyrightId":1003,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":386498,"name":"92全运会开幕表演音乐(跃动北县篇)","artists":[{"id":13193,"name":"五月天","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":38279,"name":"92全运会纪念EP","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1062345600000,"size":5,"copyrightId":1003,"status":1,"picId":49478023262210},"duration":583000,"copyrightId":1003,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":347253,"name":"不可一世","artists":[{"id":11127,"name":"Beyond","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":34211,"name":"遥望","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":744134400000,"size":12,"copyrightId":5003,"status":3,"picId":119846767440732,"alia":["黄家驹不死音乐精神特别纪念集92-93"]},"duration":257280,"copyrightId":7002,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":8,"rUrl":null},{"id":442315494,"name":"92 (prod. meat)","artists":[{"id":12191216,"name":"lil spence","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":35005344,"name":"92","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1471622400007,"size":1,"copyrightId":0,"status":0,"picId":3444769944962520},"duration":88711,"copyrightId":0,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":484343995,"name":"I See It","artists":[{"id":12453988,"name":"MZ92","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":35619372,"name":"I See It","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1497438510178,"size":1,"copyrightId":0,"status":0,"picId":109951162948873150},"duration":182804,"copyrightId":0,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":460298034,"name":"Soap [Wave '92 cut]","artists":[{"id":12290055,"name":"ENTRO //","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":35174924,"name":"Soap [Wave '92 cut]","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1478880000007,"size":1,"copyrightId":0,"status":0,"picId":18504780697249746},"duration":146468,"copyrightId":0,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":436305468,"name":"92","artists":[{"id":12097079,"name":"Myth Syzer","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},{"id":0,"name":"TA-HA","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":34929040,"name":"92","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1427472000007,"size":1,"copyrightId":0,"status":0,"picId":1416170993389342},"duration":212662,"copyrightId":0,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":386496,"name":"92全运会纪念演奏曲","artists":[{"id":2737,"name":"范宗沛","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":38279,"name":"92全运会纪念EP","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1062345600000,"size":5,"copyrightId":1003,"status":1,"picId":49478023262210},"duration":142000,"copyrightId":1003,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":484730057,"name":"92","artists":[{"id":12474020,"name":"seba yuri","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":35644028,"name":"92","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1464883200007,"size":1,"copyrightId":0,"status":0,"picId":18498183627651280},"duration":219193,"copyrightId":0,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":480575299,"name":"92","artists":[{"id":12170095,"name":"jawn","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":35559130,"name":"92","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1448035200007,"size":1,"copyrightId":0,"status":0,"picId":19038043835089604},"duration":153965,"copyrightId":0,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":0,"rUrl":null},{"id":453291444,"name":"92","artists":[{"id":46460,"name":"417.3","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":35123366,"name":"34","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1468425600007,"size":5,"copyrightId":0,"status":0,"picId":18684001092503129},"duration":500066,"copyrightId":405025,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":8,"rUrl":null},{"id":493448783,"name":"92","artists":[{"id":87467,"name":"Comity","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null}],"album":{"id":35844109,"name":"...As Everything Is A Tragedy","artist":{"id":0,"name":"","picUrl":null,"alias":[],"albumSize":0,"picId":0,"img1v1Url":"http://p1.music.126.net/6y-UleORITEDbvrOLV0Q8A==/5639395138885805.jpg","img1v1":0,"trans":null},"publishTime":1149091200007,"size":99,"copyrightId":7003,"status":3,"picId":18858823439692608},"duration":35735,"copyrightId":7003,"status":0,"alias":[],"rtype":0,"ftype":0,"mvid":0,"fee":8,"rUrl":null}],"songCount":600},"code":200}}
ncm = NeteaseCloudMusic.new
res = ncm.search "Stardust"
json_context = JSON.parse res
pp json_context