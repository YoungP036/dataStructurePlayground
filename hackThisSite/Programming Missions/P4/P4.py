import os
import bz2
from bz2 import decompress

in_path="/root/Downloads/plotMe.xml.bz2"
out_path="/root/Downloads/plotMe.xml"
with open(in_path,'rb') as source, open(out_path,'wb') as dest:
    dest.write(bz2.decompress(source.read()))


