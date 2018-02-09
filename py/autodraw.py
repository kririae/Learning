#coding = utf-8
#by kino3z
#touhou.studio

import requests
import json
from PIL import Image
import asyncio
import time

cookie = [#'sid=8kq8nla0; finger=edc6ecda; fts=1502191607; pgv_pvi=1378505728; buvid3=46006C5D-D8C8-4572-941F-AD6897C4CA1713195infoc; UM_distinctid=15dc198dc3a9c-01da3c8fab8b03-791238-384000-15dc198dc3b305; rpdid=oqsmsxipisdoswiolosxw; biliMzIsnew=1; biliMzTs=0; DedeUserID=11804540; DedeUserID__ckMd5=cc8e10516fd73781; SESSDATA=585fd030%2C1504863349%2C5a36ac30; bili_jct=3cad3d95402baea481cf60b8e53ce2e6; _cnt_pm=0; _cnt_notify=13; _dfcaptcha=030332e37cf5ec4fe5d41c41be3b6b00',
        #'sid=aefgpafs; LIVE_BUVID__ckMd5=18cb5542e247f696; fts=1502439773; buvid3=1E3BF069-6EE2-4184-BFA4-3A8AEB045B6646959infoc; Hm_lvt_8a6e55dbd2870f0f5bc9194cddf32a02=1502439774; LIVE_BUVID=AUTO1115024610342657; DedeUserID=5564980; DedeUserID__ckMd5=72c4ede8a03c5db0; SESSDATA=c3036bd5%2C1505054765%2C21bb9af1; bili_jct=c2def3aecf146044cf74f2011990e69a; _dfcaptcha=9309c3dd069ccb85efe0004476ac3078']
          'sid=aefgpafs; LIVE_BUVID__ckMd5=18cb5542e247f696; fts=1502439773; buvid3=1E3BF069-6EE2-4184-BFA4-3A8AEB045B6646959infoc; Hm_lvt_8a6e55dbd2870f0f5bc9194cddf32a02=1502439774; LIVE_BUVID=AUTO1115024610342657; DedeUserID=5564980; DedeUserID__ckMd5=72c4ede8a03c5db0; SESSDATA=c3036bd5%2C1505054765%2C21bb9af1; bili_jct=c2def3aecf146044cf74f2011990e69a; _dfcaptcha=9309c3dd069ccb85efe0004476ac3078']
class BiliAutoDraw():
    def __init__(self,cookies):
        if(not isinstance(cookies,list)):raise TypeError('cookies is needed as a list')
        self.headers = {
            'Origin': 'https://live.bilibili.py.com',
            'Accept-Encoding': 'gzip, deflate, br',
            'Accept-Language': 'zh-CN,zh;q=0.8',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.90 Safari/537.36',
            'Content-Type': 'application/x-www-form-urlencoded',
            'Accept': 'application/json, text/plain, */*',
            'Referer': 'https://live.bilibili.py.com/pages/1702/pixel-drawing',
            'Connection': 'keep-alive',
            # 'Cookie': 'sid=8kq8nla0; finger=edc6ecda; fts=1502191607; pgv_pvi=1378505728; buvid3=46006C5D-D8C8-4572-941F-AD6897C4CA1713195infoc; UM_distinctid=15dc198dc3a9c-01da3c8fab8b03-791238-384000-15dc198dc3b305; rpdid=oqsmsxipisdoswiolosxw; biliMzIsnew=1; biliMzTs=0; DedeUserID=11804540; DedeUserID__ckMd5=cc8e10516fd73781; SESSDATA=585fd030%2C1504863349%2C5a36ac30; bili_jct=3cad3d95402baea481cf60b8e53ce2e6; _cnt_pm=0; _cnt_notify=13; _dfcaptcha=030332e37cf5ec4fe5d41c41be3b6b00'
        }
        self.cookies_used = cookies
        self.finished = 0
    #def convert(self,cookies):
    #    return ''.join([f"{i[0]}={i[1]}; " for i in cookies.items()])[:-2]
    def load_photo(self,path):
        # 读取一个photo，返回值是一个list，不会用numpy
        #test finish
        im = Image.open(path)
        x,y = im.size
        info = im.load()
        return [[list(info[j, i]) for j in range(x)] for i in range(y)]
    #画一个像素点
    def write_a_pixle(self,x,y,color):
        #test finish
        url = 'https://api.live.bilibili.py.com/activity/v1/SummerDraw/draw'
        data = [('x_min',x),('y_min',y),('x_max',x),('y_max',y),('color',color)]
        headers = self.headers
        cookies = self.cookies_used[0]
        self.cookies_used.remove(cookies)
        headers['Cookie'] = cookies
        res = json.loads(requests.post(url=url,headers=headers,data=data).text)
        print(res)
        print(f"write at {x},{y},color:{color}")
        print('Writing the next pixel,please waiting')
        #print(f"finished {self.finished/}")
        self.finished+=1
        time.sleep(180.1)
        #time.sleep(180.1)
        self.cookies_used.append(cookie)
    def execute(self,p,basic_x,basic_y):
        tasks = []
        pixels = self.load_photo(p)
        for y in range(len(pixels)):
            for x in range(len(pixels[y])):
                pixel=pixels[y][x]
                #if (pixel[0] == 0 and pixel[1] == 0 and pixel[2] == 0): pass
                self.write_a_pixle(basic_x+x,basic_y+y,self.convert_color(pixel[0],pixel[1],pixel[2]))
    def main(self,x,y):
        self.execute("file.png",x,y)
    def convert_color(self,r,g,b):
        res = str(r)+str(g)+str(b)
        index={
            '000':'0','255255255':'1','170170170':'2','858585':'3',
            '254211199':'4','255196206':'5','250172142':'6','255139131':'7',
            '2446754':'8','2333099':'9','226102150':'A','15639176':'B',
            '10358183':'C','6381181':'D','070112':'E','5113151':'F',
            '33150243':'G','0188212':'H','59229219':'I','151253220':'J','221150':'K',
            '5516960':'L','13723066':'M','2152557':'N','255246209':'O',
            '248203140':'P','25523559':'Q','2551937':'R','2551520':'S',
            '2558734':'T','1846339':'S','1218572':'V'}
        ret = index.get(res)
        if(ret==None):return '0'
        else:return ret
if(__name__=='__main__'):
    b = BiliAutoDraw(cookie)
    b.main(373,260)