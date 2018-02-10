#!/usr/bin/env python
import os
import fnmatch

def search(pattern, root=os.curdir):
    for path, dirs, files in os.walk(os.path.abspath(root)):
        for filename in fnmatch.filter(files, pattern):
            yield os.path.join(path, filename)

for x in search("*.exe"): 
    print ("Deleting {0}".format(x))
    os.remove(x)
for x in search("*.swp"):
    print ("Deleting {0}".format(x))
    os.remove(x)
for x in search("*.log"):
    print ("Deleting {0}".format(x))
    os.remove(x)