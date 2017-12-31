import requests
import sys
import pprint
import json
import pickle
import os
import win32clipboard as wc

url_update = "https://sm.ms/api/upload"
url_list = "https://sm.ms/api/list"
url_clear = "https://sm.ms/api/clear"

def load():
    if os.path.exists("./sm.ms.svd"):
        plist = pickle.loads("./sm.ms.svd")
def update_photo(filepath):
    ret = requests.post(url_update, files = {"smfile": open(filepath, "rb")})
    return json.loads(ret.text)
def get_list():
    ret = requests.get(url_list)
    return json.loads(ret.text)
def clear():
    ret = requests.get(url_clear)
    return json.loads(ret.text)
class ClipBoard:
    def setText(text):
        wc.OpenClipboard()
        wc.EmptyClipboard()
        wc.SetClipboardText(text)
        wc.CloseClipboard()
    def getformat():
        # copy others
        wc.OpenClipboard()
        # formats = []
        lastFormat = 0
        while 1:
            nextFormat = wc.EnumClipboardFormats(lastFormat)
            if 0 == nextFormat:
                break
            else:
                lastFormat = nextFormat
        return lastFormat
        wc.CloseClipboard()
    def loadFile():
        wc.OpenClipboard()
        d = wc.GetClipboardData(ClipBoard.getformat())
        wc.CloseClipboard()
        return d
if __name__ == '__main__':
    # wc.OpenClipboard()
    # d = wc.GetClipboardData(win32con.CF_TEXT)
    # ClipBoard.setText("kriaeth")
    print(ClipBoard.loadFile())
    with open("tempo.jpg", "wb") as f:
        f.write(ClipBoard.loadFile())
        ret = update_photo("./tempo.jpg")
        print(ret)
    print(ClipBoard.getformat())