from PIL import Image
import sys
sys.setrecursionlimit(10000)
# info[x, y]索引到第x列第y行
def load_photo(path, basex, basey):
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    im = Image.open(path)
    x, y = im.size
    print(x, y)
    info = im.load()
    basec = info[basex, basey]
    def dfs(cx, cy):
        info[cx, cy] = 0, 0, 0, 0
        for i in range(4):
            if (cx + dx[i] >= y or cy + dy[i] >= x or cx + dx[i] < 0 or cy + dy[i] < 0):
                return
            if(info[cx + dx[i], cy + dy[i]] == basec):
                dfs(cx + dx[i], cy + dy[i])
    dfs(basex, basey)
    im.save(path, 'png')
if __name__ == '__main__':
    load_photo("uuz.png", 0, 0)