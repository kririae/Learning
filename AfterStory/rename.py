# Created by kririae
# 2019/02/07
import os

'''
将PATH更改为需要rename的文件夹路径
extract_integers可根据需要自定义，返回值为list
自动完成数字提取与类型提取，有意者自己改
自动补充0...
'''

PATH = ""

def extract_integers(s: 'str') -> 'list':
  if type(s) != str:
    raise Exception('Input type error!')
  s += '#'
  ret, val = [], 0
  for index, value in enumerate(s):
    if value.isdigit():
      val = val * 10 + int(value)
    else:
      if s[index - 1].isdigit() if index >= 1 else False:
        ret.append(val)
        val = 0
  return ret;

def add_zero_to_length(s: 'int', length: 'int') -> 'str':
  if (type(s) != int or type(length) != int):
    raise Exception('Input type error')
  return '0' * (length - len(str(s)) + 1) + str(s);

if __name__ == '__main__':
  lst = os.listdir(PATH)
  val, v_max = [], -1
  for index, value in enumerate(lst):
    tmp = extract_integers(value)
    val.append(tmp[0] if len(tmp) > 0 else index)
    v_max = max(v_max, len(list(str(val[index]))))
  for index, value in enumerate(lst):
    os.rename(PATH + '\\' + lst[index], PATH + '\\bgm' + add_zero_to_length(val[index], v_max) + '.' + lst[index].split('.')[-1])
